#pragma once

#include "recordheader.h"
#include "../../../Common/DocxFormat/Source/Base/Nullable.h"
#include "../../../Common/DocxFormat/Source/SystemUtility/File.h"
#include <memory>

namespace PPT
{
class IRecord
{
public:
    RecordHeader rh;

    virtual ~IRecord(){}
    virtual void ReadFromStream(const RecordHeader &oHeader, const CFStreamPtr &pStream) = 0;
    virtual void ReadFromStream(const RecordHeader &oHeader, POLE::Stream *pStream) = 0;
};
using PIRecord = std::shared_ptr<IRecord>;
using ArrRecords = std::vector<PIRecord>;

class UnknownRecord : public IRecord
{
    // этот класс - просто для того, чтобы нигде не проверять,
    // реализована ли у нас такая запись

public:
    virtual void ReadFromStream(const RecordHeader &oHeader, const CFStreamPtr &pStream);
    virtual void ReadFromStream(const RecordHeader &oHeader, POLE::Stream *pStream);

};


std::wstring ReadStringW(const CFStreamPtr &pStream, int size);
std::string	 ReadStringA(const CFStreamPtr &pStream, int size);

RecordHeader GetReadRecordHeader(POLE::Stream *pStream);
PIRecord CreateByType(const RecordHeader& oHeader);
int ReadSeveralRecords(ArrRecords &records, unsigned len, POLE::Stream *pStream);

template <typename T>
void GetRecordsByType(const ArrRecords& allRecords, std::vector<T>* pArray, bool bOnlyFirst = false);

}
