#pragma once
#include <string>

using BYTE = unsigned char;

namespace PPT
{
using BlipRef = short;
using bool1 = bool;
using BulletSize = short;
using char2 = wchar_t;

using ExHyperlinkId = unsigned;
using ExHyperlinkIdRef = unsigned;

using ExObjId = unsigned;
using ExObjIdRef = unsigned;

using FileOrDirNameFragment = std::wstring;

using FontIndexRef = unsigned short;
using FontIndexRef10 = unsigned int;

using HttpUrl = std::wstring;

using IndentLevel = unsigned short;

using MachineName = std::wstring;

using MasterId = unsigned int;
using MasterIdRef = unsigned int;
using NotesId = unsigned int;
using NotesIdRef = unsigned int;

using ParaSpacing = short;
using PersistIdRef = unsigned int;

using PrintableAnsiString = std::string;
using PrintableUnicodeString = std::wstring;

using SlideId = unsigned int;
using SlideIdRef = unsigned int;

using SmartTagIndex = unsigned int;
using SoundIdRef = unsigned int;
using TabCrLfPrintableUnicodeString = std::wstring;
using TabSize = short;
using TextPosition = int;
using TxLCID = unsigned short;

using UncOrLocalPath = std::wstring;
using UncPath = std::wstring;
using UncPathOrHttpUrl = std::wstring;
using UnicodeString = std::wstring;
using Utf8UnicodeString = std::string;

}
