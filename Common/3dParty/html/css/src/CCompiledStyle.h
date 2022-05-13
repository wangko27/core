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

        bool m_bRoundingValues;

        std::wstring ConvertUnitMeasure(const std::wstring& sValue, const float& fPreviousValue, ScalingDirection enScalingDirection = ScalingDirectionNone) const;

        void Scale(float &dValue, ScalingDirection enScalingDirection) const;

        float ConvertPx(const std::wstring& sValue) const;
        float ConvertPxToCm(const float& dValue) const;
        float ConvertPxToIn(const float& dValue) const;
        float ConvertPxToMm(const float& dValue) const;
        float ConvertPxToPt(const float& dValue) const;
        float ConvertPxToPc(const float& dValue) const;

        float ConvertCm(const std::wstring& sValue) const;
        float ConvertCmToPx(const float& dValue) const;
        float ConvertCmToIn(const float& dValue) const;
        float ConvertCmToMm(const float& dValue) const;
        float ConvertCmToPt(const float& dValue) const;
        float ConvertCmToPc(const float& dValue) const;

        float ConvertMm(const std::wstring& sValue) const;
        float ConvertMmToPx(const float& dValue) const;
        float ConvertMmToIn(const float& dValue) const;
        float ConvertMmToCm(const float& dValue) const;
        float ConvertMmToPt(const float& dValue) const;
        float ConvertMmToPc(const float& dValue) const;

        float ConvertIn(const std::wstring& sValue) const;
        float ConvertInToPx(const float& dValue) const;
        float ConvertInToMm(const float& dValue) const;
        float ConvertInToCm(const float& dValue) const;
        float ConvertInToPt(const float& dValue) const;
        float ConvertInToPc(const float& dValue) const;

        float ConvertPt(const std::wstring& sValue) const;
        float ConvertPtToPx(const float& dValue) const;
        float ConvertPtToMm(const float& dValue) const;
        float ConvertPtToCm(const float& dValue) const;
        float ConvertPtToIn(const float& dValue) const;
        float ConvertPtToPc(const float& dValue) const;

        float ConvertPc(const std::wstring& sValue) const;
        float ConvertPcToPx(const float& dValue) const;
        float ConvertPcToMm(const float& dValue) const;
        float ConvertPcToCm(const float& dValue) const;
        float ConvertPcToIn(const float& dValue) const;
        float ConvertPcToPt(const float& dValue) const;

    public:
        friend class CSvgStyle;

        NSConstValues::NSCssProperties::Font        m_pFont;
        NSConstValues::NSCssProperties::Margin      m_pMargin;
        NSConstValues::NSCssProperties::Background  m_pBackground;
        NSConstValues::NSCssProperties::Text        m_pText;
        NSConstValues::NSCssProperties::Border      m_pBorder;

        CCompiledStyle();
        CCompiledStyle(const std::map<std::wstring, std::wstring>& mStyle);
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

        void SetRoundingValues(bool bValue);

        CCompiledStyle& operator+= (const CCompiledStyle& oElement);
        CCompiledStyle& operator=  (const CCompiledStyle& oElement);
        bool operator==            (const CCompiledStyle& oElement) const;

        static void StyleEquation(CCompiledStyle& oFirstStyle, CCompiledStyle& oSecondStyle);
    };
}

#endif // CCOMPILEDSTYLE_H
