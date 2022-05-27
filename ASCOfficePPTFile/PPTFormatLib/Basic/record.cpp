#include "record.h"
#include "streamcontrol.h"
#include <iostream>

using namespace PPT;
using std::cerr;

void UnknownRecord::ReadFromStream(const RecordHeader & oHeader, const CFStreamPtr &pStream)
{
    rh = oHeader;

    pStream->seekFromCurForward(rh.recLen);
}
void UnknownRecord::ReadFromStream(const RecordHeader & oHeader, POLE::Stream* pStream)
{
    rh = oHeader;

    StreamUtils::StreamSkip((long)rh.recLen, pStream);
    cerr << rh.Name() << " - skipped, lenght: " << rh.recLen << "\n";
}

namespace PPT
{


std::wstring ReadStringW(const CFStreamPtr &pStream, int lLen)
{
    if (!pStream) return (L"");

    unsigned char* pData = new unsigned char[2 * (lLen + 1)];
    memset (pData, 0, 2 * (lLen + 1));

    pStream->read(pData, 2 * lLen);

    if (sizeof(wchar_t) == 4)
    {
        ConversionResult eUnicodeConversionResult;
        UTF32 *pStrUtf32 = new UTF32 [lLen + 1];
        pStrUtf32[lLen] = 0 ;

        const UTF16 *pStrUtf16_Conv = (const UTF16 *) pData;
        UTF32		*pStrUtf32_Conv =                 pStrUtf32;

        eUnicodeConversionResult = ConvertUTF16toUTF32 ( &pStrUtf16_Conv
                                                         , &pStrUtf16_Conv[lLen]
                                                         , &pStrUtf32_Conv
                                                         , &pStrUtf32 [lLen]
                                                         , strictConversion);

        if (conversionOK != eUnicodeConversionResult)
        {
            delete [] pStrUtf32;
            return (L"");
        }
        std::wstring res((wchar_t*)pStrUtf32, lLen);
        if (pStrUtf32) delete [] pStrUtf32;
        return res;
    }
    else
    {
        std::wstring str((wchar_t*)pData);
        delete[] pData;
        return str;
    }

}
std::string ReadStringA(const CFStreamPtr &pStream, int lLen)
{
    if (!pStream) return ("");

    char* pData = new char[lLen + 1];

    pStream->read((unsigned char*)pData, lLen);

    pData[lLen] = 0;

    std::string str(pData, lLen);

    delete[] pData;
    return str;
}

RecordHeader GetReadRecordHeader(POLE::Stream *pStream)
{
    RecordHeader header;
    header.ReadFromStream(pStream);
    return header;
}

#define CREATE_BY_TYPE(RECORD_TYPE, CLASS_RECORD_NAME) \
    case RECORD_TYPE: { pRecord.reset(new CLASS_RECORD_NAME()); break; }

PIRecord CreateByType(const RecordHeader& oHeader)
{
    PIRecord pRecord;
    switch (oHeader.recType)
    {
    CREATE_BY_TYPE(RT_NONE, UnknownRecord) // example

            // ExObjListSubContainer
    CREATE_BY_TYPE(RT_ExternalAviMovie, UnknownRecord)
    CREATE_BY_TYPE(RT_ExternalCdAudio, UnknownRecord)
    CREATE_BY_TYPE(RT_ExternalOleControl, UnknownRecord)
    CREATE_BY_TYPE(RT_ExternalHyperlink, UnknownRecord)
    CREATE_BY_TYPE(RT_ExternalMciMovie, UnknownRecord)
    CREATE_BY_TYPE(RT_ExternalMidiAudio, UnknownRecord)
    CREATE_BY_TYPE(RT_ExternalOleEmbed, UnknownRecord)
    CREATE_BY_TYPE(RT_ExternalOleLink, UnknownRecord)
    CREATE_BY_TYPE(RT_ExternalWavAudioEmbedded, UnknownRecord)
    CREATE_BY_TYPE(RT_ExternalWavAudioLink, UnknownRecord)

            default:
        break;
    }
    if (!pRecord)
    {
        pRecord.reset(new UnknownRecord());
#ifdef _DEBUG
        char str[1024]={};
        sprintf(str, "Unknown record type: %x\t" , oHeader.RecType);
        std::cout << str << GetRecordName(oHeader.RecType) << "\n";
#endif
    }

    return pRecord;
}

int ReadSeveralRecords(ArrRecords &records, unsigned len, POLE::Stream *pStream)
{
    int error = 0;
    while (len > 0)
    {
        RecordHeader rrh = GetReadRecordHeader(pStream);
        len -= rrh.recLen + RecordHeaderLen;

        PIRecord record = CreateByType(rrh);

        StreamControl sc(pStream, &rrh);
        record->ReadFromStream(rrh, pStream);

        if (sc.CheckAndCorrect())
            records.emplace_back(record);
        else
            error++;
    }

    return error;
}

template<typename T>
void GetRecordsByType(const ArrRecords &allRecords, std::vector<T> *pArray, bool bOnlyFirst)
{
    if (pArray == nullptr)
        return;

    for (const auto& pirecord : allRecords)
    {
        T pRecord = dynamic_cast<T>(pirecord.get());
        if (pRecord != nullptr)
        {
            pArray->emplace_back(pRecord);
            if (bOnlyFirst) return;
        }
    }
}

}
