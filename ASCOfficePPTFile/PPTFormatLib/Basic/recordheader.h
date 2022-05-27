#pragma once

#include "../../../ASCOfficeXlsFile2/source/XlsFormat/Binary/BinSmartPointers.h"
#include "../../../ASCOfficeXlsFile2/source/XlsFormat/Binary/CFStream.h"
#include "../../../Common/3dParty/pole/pole.h"
#include "../Enums/RecordType.h"
#include "types.h"

namespace PPT
{
using CFStreamPtr = XLS::CFStreamPtr;
const unsigned RecordHeaderLen = 8;

struct RecordHeader
{
    BYTE            recVer;         // 4 bits
    unsigned short  recInstance;    // 12 bits
    RecordType      recType;        // 2 bytes
    unsigned int    recLen;         // 4 bytes


    RecordHeader();
    void Clear();
    bool IsContainer()const;
    inline bool IsCorrect()const {return !m_bBadHeader;}
    std::string Name()const;


    bool ReadFromStream(POLE::Stream * pStream);
    bool ReadFromStream(const CFStreamPtr &pStream);

private:
    bool StreamSizeCorrect(unsigned streamRemLen);

private:
    bool m_bBadHeader{false};

};
}
