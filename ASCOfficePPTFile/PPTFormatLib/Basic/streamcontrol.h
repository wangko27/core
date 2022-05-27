#pragma once

#include "recordheader.h"

class StreamControl
{
public:
    StreamControl(POLE::Stream *pStream, const PPT::RecordHeader* ptrRH, POLE::uint64 expectedLenght = 0);
    bool CheckAndCorrect();

private:
    POLE::Stream *m_pStream;
    const PPT::RecordHeader* m_pRH;
    POLE::uint64 m_nExpectedLenght;
    POLE::uint64 m_startPossition;
};
