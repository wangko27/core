﻿/*
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

    #include "../Source/XlsbFormat/Xlsb.cpp"
    #include "../Source/XlsbFormat/WorkBookStream.cpp"
    #include "../Source/XlsbFormat/WorkSheetStream.cpp"
    #include "../Source/XlsbFormat/SharedStringsStream.cpp"
    #include "../Source/XlsbFormat/StylesStream.cpp"
    #include "../Source/XlsbFormat/CommentsStream.cpp"
    #include "../Source/XlsbFormat/TableStream.cpp"
// Biff12_records
    #include "../Source/XlsbFormat/Biff12_records/BeginBook.cpp"
    #include "../Source/XlsbFormat/Biff12_records/FRTBegin.cpp"
    #include "../Source/XlsbFormat/Biff12_records/FRTEnd.cpp"
    #include "../Source/XlsbFormat/Biff12_records/Uid.cpp"
    #include "../Source/XlsbFormat/Biff12_records/FileVersion.cpp"
    #include "../Source/XlsbFormat/Biff12_records/FileSharingIso.cpp"
    #include "../Source/XlsbFormat/Biff12_records/WbProp.cpp"
    #include "../Source/XlsbFormat/Biff12_records/ACBegin.cpp"
    #include "../Source/XlsbFormat/Biff12_records/AbsPath15.cpp"
    #include "../Source/XlsbFormat/Biff12_records/ACEnd.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginBookViews.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndBookViews.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginBundleShs.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BundleSh.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndBundleShs.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginFnGroup.cpp"
    #include "../Source/XlsbFormat/Biff12_records/FnGroup.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndFnGroup.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginExternals.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndExternals.cpp"
    #include "../Source/XlsbFormat/Biff12_records/SupSelf.cpp"
    #include "../Source/XlsbFormat/Biff12_records/SupBookSrc.cpp"
    #include "../Source/XlsbFormat/Biff12_records/SupSame.cpp"
    #include "../Source/XlsbFormat/Biff12_records/PlaceholderName.cpp"
    #include "../Source/XlsbFormat/Biff12_records/SupAddin.cpp"
    #include "../Source/XlsbFormat/Biff12_records/CalcProp.cpp"
    #include "../Source/XlsbFormat/Biff12_records/OleSize.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndBook.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BookProtectionIso.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BookProtection.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginSheet.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginColInfos.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndColInfos.cpp"
    #include "../Source/XlsbFormat/Biff12_records/WsDim.cpp"
    #include "../Source/XlsbFormat/Biff12_records/Drawing.cpp"
    #include "../Source/XlsbFormat/Biff12_records/LegacyDrawing.cpp"
    #include "../Source/XlsbFormat/Biff12_records/LegacyDrawingHF.cpp"
    #include "../Source/XlsbFormat/Biff12_records/HLink.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginMergeCells.cpp"
    #include "../Source/XlsbFormat/Biff12_records/MergeCell.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndMergeCells.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginSheetData.cpp"
    #include "../Source/XlsbFormat/Biff12_records/RwDescent.cpp"
    #include "../Source/XlsbFormat/Biff12_records/CellMeta.cpp"
    #include "../Source/XlsbFormat/Biff12_records/ValueMeta.cpp"
    #include "../Source/XlsbFormat/Biff12_records/WsFmtInfo.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndSheetData.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndWsView.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginWsViews.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndWsViews.cpp"
    #include "../Source/XlsbFormat/Biff12_records/SheetProtectionIso.cpp"
    #include "../Source/XlsbFormat/Biff12_records/SheetProtection.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginListParts.cpp"
    #include "../Source/XlsbFormat/Biff12_records/ListPart.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndListParts.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginSortCond.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndSortCond.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginSortCond14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndSortCond14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginRichSortCondition.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndRichSortCondition.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndSortState.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginConditionalFormatting.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndConditionalFormatting.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginCFRule.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndCFRule.cpp"
    #include "../Source/XlsbFormat/Biff12_records/CFVO.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginIconSet.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndIconSet.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginDatabar.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndDatabar.cpp"
    #include "../Source/XlsbFormat/Biff12_records/Color.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginColorScale.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndColorScale.cpp"
    #include "../Source/XlsbFormat/Biff12_records/CFRuleExt.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginCFRule14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndCFRule14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginConditionalFormatting14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndConditionalFormatting14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginColorScale14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/Color14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndColorScale14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginDatabar14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndDatabar14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginIconSet14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/CFIcon.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndIconSet14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/CFVO14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndSheet.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginSst.cpp"
    #include "../Source/XlsbFormat/Biff12_records/SSTItem.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndSst.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginStyleSheet.cpp"
    #include "../Source/XlsbFormat/Biff12_records/Fmt.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginFmts.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndFmts.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginFonts.cpp"
    #include "../Source/XlsbFormat/Biff12_records/KnownFonts.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndFonts.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginFills.cpp"
    #include "../Source/XlsbFormat/Biff12_records/Fill.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndFills.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginBorders.cpp"
    #include "../Source/XlsbFormat/Biff12_records/Border.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndBorders.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginCellStyleXFs.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndCellStyleXFs.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginCellXFs.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndCellXFs.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginStyles.cpp"
    #include "../Source/XlsbFormat/Biff12_records/Style.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndStyles.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginDXFs.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndDXFs.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndTableStyles.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndTableStyle.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginColorPalette.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndColorPalette.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginIndexedColors.cpp"
    #include "../Source/XlsbFormat/Biff12_records/IndexedColor.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndIndexedColors.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginMRUColors.cpp"
    #include "../Source/XlsbFormat/Biff12_records/MRUColor.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndMRUColors.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndStyleSheet.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginConditionalFormattings.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndConditionalFormattings.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginDXF14s.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndDXF14s.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginDXFs15.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndDXFs15.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginTimelineStyle.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginTimelineStyleElements.cpp"
    #include "../Source/XlsbFormat/Biff12_records/TimelineStyleElement.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndTimelineStyleElements.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndTimelineStyle.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginTimelineStyles.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndTimelineStyles.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginTimelineStyleSheetExt15.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndTimelineStyleSheetExt15.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginSlicerStyle.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginSlicerStyleElements.cpp"
    #include "../Source/XlsbFormat/Biff12_records/SlicerStyleElement.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndSlicerStyleElements.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndSlicerStyle.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginSlicerStyles.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndSlicerStyles.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginStyleSheetExt14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndStyleSheetExt14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginComment.cpp"
    #include "../Source/XlsbFormat/Biff12_records/CommentText.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndComment.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginCommentList.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndCommentList.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginCommentAuthors.cpp"
    #include "../Source/XlsbFormat/Biff12_records/CommentAuthor.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndCommentAuthors.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginComments.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndComments.cpp"
    #include "../Source/XlsbFormat/Biff12_records/TableStyleClient.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginList.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndList.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginListCols.cpp"
    #include "../Source/XlsbFormat/Biff12_records/ListCCFmla.cpp"
    #include "../Source/XlsbFormat/Biff12_records/ListTrFmla.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginListXmlCPr.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginListCol.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndListCols.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndListCol.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginAFilter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndListXmlCPr.cpp"
    #include "../Source/XlsbFormat/Biff12_records/List14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/Top10Filter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/Top10RichFilter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndAFilter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndFilterColumn.cpp"
    #include "../Source/XlsbFormat/Biff12_records/IconFilter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/IconFilter14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/ColorFilter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/DynamicFilter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginFilterColumn.cpp"
    #include "../Source/XlsbFormat/Biff12_records/AFilterDateGroupItem.cpp"
    #include "../Source/XlsbFormat/Biff12_records/RichFilterDateGroupItem.cpp"
    #include "../Source/XlsbFormat/Biff12_records/Filter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/CustomFilter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginCustomFilters.cpp"
    #include "../Source/XlsbFormat/Biff12_records/CustomFilter14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndCustomFilters.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginCustomFilters14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/Filter14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginFilters.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndFilters.cpp"
    #include "../Source/XlsbFormat/Biff12_records/DynamicRichFilter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginRichFilterColumn.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndRichFilterColumn.cpp"
    #include "../Source/XlsbFormat/Biff12_records/RichFilter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginRichFilters.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndRichFilters.cpp"
    #include "../Source/XlsbFormat/Biff12_records/CustomRichFilter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginCustomRichFilters.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndCustomRichFilters.cpp"
    #include "../Source/XlsbFormat/Biff12_records/Margins.cpp"
    #include "../Source/XlsbFormat/Biff12_records/PrintOptions.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginHeaderFooter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndHeaderFooter.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginDVals.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndDVals.cpp"
    #include "../Source/XlsbFormat/Biff12_records/DValList.cpp"
    #include "../Source/XlsbFormat/Biff12_records/BeginDVals14.cpp"
    #include "../Source/XlsbFormat/Biff12_records/EndDVals14.cpp"
// Biff12_structures
    #include "../Source/XlsbFormat/Biff12_structures/LPByteBuf.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/IsoPasswordData.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/CodeName.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/ACProductVersion.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/FRTProductVersion.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/RelID.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/BookProtectionFlags.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/ColSpan.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/Cell.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/GrbitFmla.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/SxOs.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/SxSu.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/UncheckedSqRfX.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/CFType.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/CFTemp.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/CFOper.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/CFTextOper.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/CFDateOper.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/CFVOtype.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/CFVOType14.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/FRTBlank.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/RichStr.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/StrRun.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/PhRun.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/GradientStop.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/Blxf.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/FRTHeader.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/FRTRefs.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/FRTRef.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/FRTSqrefs.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/FRTSqref.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/FRTFormulas.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/FRTFormula.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/FRTParsedFormula.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/FRTRelID.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/ListType.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/XmlDataType.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/ListTotalRowFunction.cpp"
    #include "../Source/XlsbFormat/Biff12_structures/DValStrings.cpp"
// Biff12_unions
    #include "../Source/XlsbFormat/Biff12_unions/FRT.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/ACUID.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/ACABSPATH.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/BOOKVIEWS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/BUNDLESHS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/FNGROUP_bu.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/EXTERNALS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/SUP.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/SUPSAME_bu.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/SUPADDIN_bu.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/COLINFOS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/HLINKS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/MERGECELLS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/CELLTABLE.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/ACCELLTABLE.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/CELL_bu.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/DATACELL.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/FMLACELL.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/SHRFMLACELL.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/TABLECELL.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/CELLMETA_bu.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/WSVIEW2.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/WSVIEWS2.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/LISTPARTS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/RICHSORTCONDITION.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/SORTCOND14.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/ACSORTCONDS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/SORTCOND.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/SORTCONDS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/SORTSTATE.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/uCFVO.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/ICONSET.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/DATABAR.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/COLORSCALE.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/FRTCFRULE.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/CFRULE.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/CONDITIONALFORMATTING.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/CFRULE14.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/CONDITIONALFORMATTING14.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/COLORSCALE14.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/DATABAR14.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/ICONSET14.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/uCFVO14.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/CONDITIONALFORMATTINGS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/FRTWORKSHEET.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/SHAREDSTRINGS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/ACFMT.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/FMTS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/FONTS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/ACFONTS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/FILLS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/BORDERS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/CELLSTYLEXFS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/CELLXFS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/STYLES.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/DXFS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/DXF.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/FRTDXF.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/TABLESTYLES.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/TABLESTYLE.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/MRUCOLORS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/INDEXEDCOLORS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/COLORPALETTE.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/DXF14S.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/DXFS15.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/TIMELINESTYLE.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/TIMELINESTYLES.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/STYLESHEET15.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/SLICERSTYLE.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/SLICERSTYLES.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/STYLESHEET14.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/FRTSTYLESHEET.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/COMMENT.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/COMMENTLIST.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/COMMENTAUTHORS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/COMMENTS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/FRTTABLE.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/TABLE.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/LISTCOLS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/LISTCOL.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/LISTXMLCPR.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/AUTOFILTER.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/FILTERCOLUMN.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/ACICONFILTER.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/ACFILTERCONTENT.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/FILTERS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/CUSTOMFILTERS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/ACCUSTOMFILTER.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/ACFILTERS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/RICHFILTERCONTENT.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/RICHFILTERS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/CUSTOMRICHFILTERS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/HEADERFOOTER.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/ACDVALLIST.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/DVALS.cpp"
    #include "../Source/XlsbFormat/Biff12_unions/DVALS14.cpp"
