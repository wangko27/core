#include "streamcontrol.h"
#include "../../../Common/DocxFormat/Source/SystemUtility/File.h"
#include <iostream>

StreamControl::StreamControl(POLE::Stream *pStream, const PPT::RecordHeader *ptrRH, POLE::uint64 expectedLenght) :
    m_pStream(pStream), m_pRH(ptrRH), m_nExpectedLenght(expectedLenght), m_startPossition(0)
{
    if (m_pStream == nullptr) return;

    if (m_pRH != nullptr) m_nExpectedLenght = m_pRH->recLen;

    m_startPossition = m_pStream->tell();
}

bool StreamControl::CheckAndCorrect()
{
    const auto endPossition = m_pStream->tell();
    const auto readLenght = endPossition - m_startPossition;
    if (readLenght == m_nExpectedLenght) return true;

    StreamUtils::StreamSeek(m_startPossition + m_nExpectedLenght, m_pStream);
    std::cerr << "Uncorrect " << (m_pRH == nullptr ? "reading" : m_pRH->Name())
              << " lenght: " << readLenght << " not " << m_nExpectedLenght << "\n";

    return false;
}
