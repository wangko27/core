/*
 * (c) Copyright Ascensio System SIA 2010-2019
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at 20A-12 Ernesta Birznieka-Upisha
 * street, Riga, Latvia, EU, LV-1050.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */
#pragma once

#include "../../../ASCOfficePPTXFile/PPTXFormat/Logic/Timing/CTn.h"
#include "../../Records/Animations/ExtTimeNodeContainer.h"

#include "TnChildren.h"
#include "Cond.h"


namespace PPT_FORMAT
{
unsigned gcTn_ID = 1;

void ConvertTnChild(CRecordExtTimeNodeContainer *pETNC, PPTX::Logic::TimeNodeBase &oChild);

    void FillCTn(CRecordExtTimeNodeContainer *pETNC, PPTX::Logic::CTn &oCTn)
    {
        oCTn.id = gcTn_ID++;

        if (pETNC->m_haveTimePropertyList && !pETNC->m_pTimePropertyList->m_bEmtyNode)
        {
            for (auto* pRec : pETNC->m_pTimePropertyList->m_arrElements)
            {
                TimePropertyID4TimeNode VariableType = ( TimePropertyID4TimeNode ) pRec->m_oHeader.RecInstance;

                switch ( VariableType )
                {
                case TL_TPID_Display:
                {
                    oCTn.display = (bool)dynamic_cast<CRecordTimeDisplayType*>(pRec)->m_Value;
                    break;
                }
                case TL_TPID_MasterPos:
                {
                    oCTn.masterRel = new PPTX::Limit::TLMasterRelation;
                    oCTn.masterRel = dynamic_cast<CRecordTimeMasterRelType*>(pRec)->m_Value ?
                                L"sameClick" : L"nextClick";
                    break;
                }
                case TL_TPID_SubType:			break;
                case TL_TPID_EffectID:
                {
                    oCTn.presetID = dynamic_cast<CRecordTimeEffectID*>(pRec)->m_Value;
                    break;
                }
                case TL_TPID_EffectDir:
                {
                    oCTn.presetSubtype = dynamic_cast<CRecordTimeEffectDir*>(pRec)->m_Value;
                    break;
                }
                case TL_TPID_EffectType:
                {
                    // Write presetClass
                    std::wstring presetClass;
                    switch (dynamic_cast<CRecordTimeEffectType*>(pRec)->m_Value) {
                    case 0: break;
                    case 1: presetClass = L"entr";      break;
                    case 2: presetClass = L"exit";      break;
                    case 3: presetClass = L"emph";      break;
                    case 4: presetClass = L"path";      break;
                    case 5: presetClass = L"verb";      break;
                    case 6: presetClass = L"mediacall"; break;
                    }
                    if (!presetClass.empty())
                    {
                        oCTn.presetClass = new PPTX::Limit::TLPresetClass;
                        oCTn.presetClass = presetClass;
                    }
                    break;
                }
                case TL_TPID_AfterEffect:
                {
                    oCTn.afterEffect = (bool)dynamic_cast<CRecordTimeAfterEffect*>(pRec)->m_Value;
                    break;
                }
                case TL_TPID_SlideCount:		break;
                case TL_TPID_TimeFilter:
                {
                    oCTn.tmFilter = dynamic_cast<CRecordTimeNodeTimeFilter*>(pRec)->m_Value;
                    break;
                }
                case TL_TPID_EventFilter:
                {
                    oCTn.evtFilter = dynamic_cast<CRecordTimeEventFilter*>(pRec)->m_Value;
                    break;
                }
                case TL_TPID_HideWhenStopped:	break;
                case TL_TPID_GroupID:
                {
                    oCTn.grpId = dynamic_cast<CRecordTimeGroupID*>(pRec)->m_Value;
                    break;
                }
                case TL_TPID_EffectNodeType:
                {
                    // Write nodeType
                    std::wstring nodeType;
                    switch (dynamic_cast<CRecordTimeEffectNodeType*>(pRec)->m_Value)
                    {
                    case 1: nodeType = L"clickEffect"; break;
                    case 2: nodeType = L"withEffect"; break;
                    case 3: nodeType = L"afterEffect"; break;
                    case 4: nodeType = L"mainSeq"; break;
                    case 5: nodeType = L"interactiveSeq"; break;
                    case 6: nodeType = L"clickPar"; break;
                    case 7: nodeType = L"withGroup"; break;
                    case 8: nodeType = L"afterGroup"; break;
                    case 9: nodeType = L"tmRoot"; break;
                    }
                    if (!nodeType.empty())
                    {
                        oCTn.nodeType = new PPTX::Limit::TLNodeType;
                        oCTn.nodeType = nodeType;
                    }

                    break;
                }
                case TL_TPID_PlaceholderNode:
                {
                    oCTn.nodePh = (bool)dynamic_cast<CRecordTimePlaceholderNode*>(pRec)->m_Value;
                    break;
                }
                case TL_TPID_MediaVolume:		break;
                case TL_TPID_MediaMute:			break;
                case TL_TPID_ZoomToFullScreen:	break;
                default :
                    break;
                }
            }
        }

        // Reading TimeNodeAtom
        const auto& oTimeNodeAtom = pETNC->m_oTimeNodeAtom;

        // Write restart
        if (oTimeNodeAtom.m_fRestartProperty)
            oCTn.restart = PPTX::Limit::TLRestart(oTimeNodeAtom.m_dwRestart) ;


        // Write fill
        if (oTimeNodeAtom.m_fFillProperty)
            oCTn.fill = PPTX::Limit::TLNodeFillType(oTimeNodeAtom.m_dwFill);

        // Write dur
        if (oTimeNodeAtom.m_fDurationProperty)
        {
            if (oTimeNodeAtom.m_nDuration == -1)
                oCTn.dur = L"indefinite";
            else
                oCTn.dur = std::to_wstring(oTimeNodeAtom.m_nDuration);
        }


        //// Write Children ////


        if (!pETNC->m_haveSequenceAtom)
        {
            // Write stCondLst
            if (pETNC->m_arrRgBeginTimeCondition.empty() == false)
            {
                oCTn.stCondLst = new PPTX::Logic::CondLst;
                oCTn.stCondLst->node_name = L"stCondLst";
            }
            for (auto* oldCond : pETNC->m_arrRgBeginTimeCondition) {
                PPTX::Logic::Cond cond;
                cond.node_name = L"cond";
                FillCond(oldCond, cond);
                oCTn.stCondLst->list.push_back(cond);
            }


            // Write endCondLst
            if (pETNC->m_arrRgEndTimeCondition.empty() == false)
            {
                oCTn.endCondLst = new PPTX::Logic::CondLst;
                oCTn.endCondLst->node_name = L"endCondLst";
            }
            for (auto* oldCond : pETNC->m_arrRgEndTimeCondition) {
                        PPTX::Logic::Cond cond;
                        cond.node_name = L"cond";
                        FillCond(oldCond, cond);
                        oCTn.endCondLst->list.push_back(cond);
            }
        }


        // Write childTnLst
        if (pETNC->m_arrRgExtTimeNodeChildren.empty() == false)
        {
            oCTn.childTnLst = new PPTX::Logic::ChildTnLst;
        }
        for (auto* oldChild : pETNC->m_arrRgExtTimeNodeChildren) {
            PPTX::Logic::TimeNodeBase child;
            ConvertTnChild(oldChild, child);
            oCTn.childTnLst->list.push_back(child);
        }


        // Write iterate
        if (pETNC->m_haveIterateDataAtom)
        {
            auto* iter = pETNC->m_pTimeIterateDataAtom;
            oCTn.iterate = new PPTX::Logic::Iterate;

            std::wstring type[] = {L"el", L"wd", L"lt"};
            if (iter->m_fIterateTypePropertyUsed)
                oCTn.iterate->type = type[iter->m_nIterateType % 3];

            if (iter->m_fIterateDirectionPropertyUsed)
                oCTn.iterate->backwards = (bool)iter->m_nIterateDirection;

            if (iter->m_fIterateIntervalTypePropertyUsed)
                oCTn.iterate->tmAbs = std::to_wstring(iter->m_nIterateIntervalType);

            if (iter->m_fIterateIntervalPropertyUsed)
                oCTn.iterate->tmPct = iter->m_nIterateInterval;

        }


        // Write endSync
        if (pETNC->m_haveTimeEndSyncTime)
        {
            auto* sync = pETNC->m_pTimeEndSyncTimeCondition;
            oCTn.endSync = new PPTX::Logic::Cond;
            oCTn.endSync->node_name = L"endSync";
            FillCond(sync, *(oCTn.endSync));
        }


        // Write subTnLst
        if (pETNC->m_arrRgSubEffect.empty() == false)
        {
            oCTn.subTnLst = new PPTX::Logic::TnLst;
        }
        // TODO
//        for (auto* oldChild : pETNC->m_arrRgSubEffect) {
//                    PPTX::Logic::TimeNodeBase child;
//                    ConvertCRecordExtTimeNodeContainerToTnLst(oldChild, child);
//                    oCTn.childTnLst->list.push_back(child);
//        }

    }

}
