#ifndef CCOMPILEDSTYLE_H
#define CCOMPILEDSTYLE_H

#include "CssCalculator_global.h"
#include "ConstValues.h"

#include <map>
#include <set>
#include <vector>
#include <string>

namespace NSCSS
{
    class CSSCALCULATOR_EXPORT CCompiledStyle
    {
        std::set<std::wstring> m_arParentsStyles;
        std::wstring m_sId;

        unsigned short int m_nDpi;
        UnitMeasure m_UnitMeasure;

        CSizeWindow m_oSourceWindow;
        CSizeWindow m_oDeviceWindow;

        std::wstring ConvertUnitMeasure(const std::wstring& sValue, const float& fPreviousValue, ScalingDirection enScalingDirection = ScalingDirectionNone) const;

        void Scale(double &dValue, ScalingDirection enScalingDirection) const;

        double ConvertPx(const std::wstring& sValue) const;
        double ConvertPxToCm(const float& dValue) const;
        double ConvertPxToIn(const float& dValue) const;
        double ConvertPxToMm(const float& dValue) const;
        double ConvertPxToPt(const float& dValue) const;
        double ConvertPxToPc(const float& dValue) const;

        double ConvertCm(const std::wstring& sValue) const;
        double ConvertCmToPx(const float& dValue) const;
        double ConvertCmToIn(const float& dValue) const;
        double ConvertCmToMm(const float& dValue) const;
        double ConvertCmToPt(const float& dValue) const;
        double ConvertCmToPc(const float& dValue) const;

        double ConvertMm(const std::wstring& sValue) const;
        double ConvertMmToPx(const float& dValue) const;
        double ConvertMmToIn(const float& dValue) const;
        double ConvertMmToCm(const float& dValue) const;
        double ConvertMmToPt(const float& dValue) const;
        double ConvertMmToPc(const float& dValue) const;

        double ConvertIn(const std::wstring& sValue) const;
        double ConvertInToPx(const float& dValue) const;
        double ConvertInToMm(const float& dValue) const;
        double ConvertInToCm(const float& dValue) const;
        double ConvertInToPt(const float& dValue) const;
        double ConvertInToPc(const float& dValue) const;

        double ConvertPt(const std::wstring& sValue) const;
        double ConvertPtToPx(const float& dValue) const;
        double ConvertPtToMm(const float& dValue) const;
        double ConvertPtToCm(const float& dValue) const;
        double ConvertPtToIn(const float& dValue) const;
        double ConvertPtToPc(const float& dValue) const;

        double ConvertPc(const std::wstring& sValue) const;
        double ConvertPcToPx(const float& dValue) const;
        double ConvertPcToMm(const float& dValue) const;
        double ConvertPcToCm(const float& dValue) const;
        double ConvertPcToIn(const float& dValue) const;
        double ConvertPcToPt(const float& dValue) const;

    public:

        NSConstValues::NSCssProperties::Font        m_pFont;
        NSConstValues::NSCssProperties::Margin      m_pMargin;
        NSConstValues::NSCssProperties::Background  m_pBackground;
        NSConstValues::NSCssProperties::Text        m_pText;
        NSConstValues::NSCssProperties::Border      m_pBorder;
        NSConstValues::NSCssProperties::Display     m_pDisplay;

        CCompiledStyle();
        explicit CCompiledStyle(const std::map<std::wstring, std::wstring>& mStyle);
        CCompiledStyle(const CCompiledStyle& oStyle);

        ~CCompiledStyle();

        void SetDpi(const unsigned short& uiDpi);
        void SetUnitMeasure(const UnitMeasure& enUnitMeasure);
        void SetSizeSourceWindow(const CSizeWindow& oSizeWindow);
        void SetSizeDeviceWindow(const CSizeWindow& oSizeWindow);

        bool Empty() const;

        void AddPropSel(const std::wstring& sProperty, const std::wstring& sValue, const unsigned int unLevel, const bool& bHardMode = true);
        void AddStyle(const std::map<std::wstring, std::wstring>& mStyle, const unsigned int unLevel, const bool& bHardMode = true);
        void AddStyle(const std::wstring& sStyle, const unsigned int unLevel, const bool& bHardMode = false);
        void AddParent(const std::wstring& sParentName);

        std::vector<std::wstring> GetParentsName() const;

        void SetID(const std::wstring& sId);
        std::wstring GetId() const;

        void ClearImportants();

        CCompiledStyle& operator+= (const CCompiledStyle& oElement);
        CCompiledStyle& operator=  (const CCompiledStyle& oElement);
        bool operator==            (const CCompiledStyle& oElement) const;

        static void StyleEquation(CCompiledStyle& oFirstStyle, CCompiledStyle& oSecondStyle);
    };
}

#endif // CCOMPILEDSTYLE_H
