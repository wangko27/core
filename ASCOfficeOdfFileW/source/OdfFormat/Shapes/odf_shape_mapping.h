﻿/*
 * (c) Copyright Ascensio System SIA 2010-2018
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
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
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

struct _sh_typ
{
	std::wstring first;
	int second;
};

static const _sh_typ Shape_Types_Mapping[] = // index === OOX::Drawing::EShapeType
{
	{	L""								,  7},			//	shapetypeAccentBorderCallout1 = 0,
	{	L""								,  7},			//	shapetypeAccentBorderCallout2,
	{	L""								,  7},			//	shapetypeAccentBorderCallout3,
	{	L"mso-spt44"					,  7},			//	shapetypeAccentCallout1,
	{	L"mso-spt45"					,  7},			//	shapetypeAccentCallout2,
	{	L"mso-spt46"					,  7},			//	shapetypeAccentCallout3, 
	{	L"actionButtonBackPrevious"		,  7},			//	shapetypeActionButtonBackPrevious,	//mso-spt194
	{	L"mso-spt196"					,  7},			//	shapetypeActionButtonBeginning,
	{	L"mso-spt189"					,  7},			//	shapetypeActionButtonBlank,
	{	L"mso-spt198"					,  7},			//	shapetypeActionButtonDocument,
	{	L"mso-spt195"					,  7},			//	shapetypeActionButtonEnd,
	{	L"mso-spt193"					,  7},			//	shapetypeActionButtonForwardNext,
	{	L"mso-spt191"					,  7},			//	shapetypeActionButtonHelp,
	{	L"mso-spt190"					,  7},			//	shapetypeActionButtonHome,
	{	L"mso-spt192"					,  7},			//	shapetypeActionButtonInformation,
	{	L"mso-spt200"					,  7},			//	shapetypeActionButtonMovie,
	{	L"mso-spt197"					,  7},			//	shapetypeActionButtonReturn,
	{	L"mso-spt199"					,  7},			//	shapetypeActionButtonSound,
	{	L""								,  7},			//	shapetypeArc,
	{	L"mso-spt91"					,  7},			//	shapetypeBentArrow,
	{	L"mso-spt33"					,  7},			//	shapetypeBentConnector2,
	{	L"mso-spt34"					,  7},			//	shapetypeBentConnector3,
	{	L"mso-spt35"					,  7},			//	shapetypeBentConnector4,
	{	L"mso-spt36"					,  7},			//	shapetypeBentConnector5,
	{	L""								,  7},			//	shapetypeBentUpArrow,
	{	L"quad-bevel"					,  7},			//	shapetypeBevel,
	{	L""								,  7},			//	shapetypeBlockArc,
	{	L"mso-spt49"					,  7},			//	shapetypeBorderCallout1,
	{	L"mso-spt50"					,  7},			//	shapetypeBorderCallout2,
	{	L"mso-spt51"					,  7},			//	shapetypeBorderCallout3,
	{	L"brace-pair"					,  7},			//	shapetypeBracePair,
	{	L""								,  7},			//	shapetypeBracketPair,
	{	L"mso-spt41"					,  7},			//	shapetypeCallout1,
	{	L"mso-spt42"					,  7},			//	shapetypeCallout2,
	{	L"mso-spt43"					,  7},			//	shapetypeCallout3,
	{	L"can"							,  7},			//	shapetypeCan,
	{	L""								,  7},			//	shapetypeChartPlus,
	{	L""								,  7},			//	shapetypeChartStar,
	{	L""								,  7},			//	shapetypeChartX,
	{	L""								,  7},			//	shapetypeChevron,
	{	L""								,  7},			//	shapetypeChord,
	{	L""								,  7},			//	shapetypeCircularArrow,
	{	L"cloud"						,  7},			//	shapetypeCloud,
	{	L"cloud-callout"				,  7},			//	shapetypeCloudCallout,
	{	L""								,  7},			//	shapetypeCorner,
	{	L""								,  7},			//	shapetypeCornerTabs,
	{	L"cube"							,  7},			//	shapetypeCube,
	{	L"mso-spt37"					,  7},			//	shapetypeCurvedConnector2,
	{	L"mso-spt38"					,  7},			//	shapetypeCurvedConnector3,
	{	L"mso-spt39"					,  7},			//	shapetypeCurvedConnector4,
	{	L"mso-spt40"					,  7},			//	shapetypeCurvedConnector5,
	{	L""								,  7},			//	shapetypeCurvedDownArrow,
	{	L""								,  7},			//	shapetypeCurvedLeftArrow,
	{	L""								,  7},			//	shapetypeCurvedRightArrow,
	{	L"mso-spt104"					,  7},			//	shapetypeCurvedUpArrow,
	{	L""								,  7},			//	shapetypeDecagon,
	{	L""								,  7},			//	shapetypeDiagStripe,
	{	L""								,  7},			//	shapetypeDiamond,
	{	L""								,  7},			//	shapetypeDodecagon,
	{	L""								,  7},			//	shapetypeDonut,
	{	L""								,  7},			//	shapetypeDoubleWave,
	{	L""								,  7},			//	shapetypeDownArrow,
	{	L""								,  7},			//	shapetypeDownArrowCallout,
	{	L"ellipse"						,  3},			//	shapetypeEllipse,
	{	L"mso-spt107"					,  7},			//	shapetypeEllipseRibbon,
	{	L"mso-spt108"					,  7},			//	shapetypeEllipseRibbon2,
	{	L"flowchart-alternate-process"	,  7},			//	shapetypeFlowChartAlternateProcess,
	{	L"flowchart-collate"			,  7},			//	shapetypeFlowChartCollate,
	{	L"flowchart-connector"			,  7},			//	shapetypeFlowChartConnector,
	{	L"flowchart-decision"			,  7},			//	shapetypeFlowChartDecision,
	{	L"flowchart-delay"				,  7},			//	shapetypeFlowChartDelay,
	{	L"flowchart-display"			,  7},			//	shapetypeFlowChartDisplay,
	{	L"flowchart-document"			,  7},			//	shapetypeFlowChartDocument,
	{	L""								,  7},			//	shapetypeFlowChartExtract,
	{	L"flowchart-data"				,  7},			//	shapetypeFlowChartInputOutput,
	{	L"flowchart-internal-storage"	,  7},			//	shapetypeFlowChartInternalStorage,
	{	L"flowchart-magnetic-disk"		,  7},			//	shapetypeFlowChartMagneticDisk,
	{	L"mso-spt129"					,  7},			//	shapetypeFlowChartMagneticDrum,
	{	L"flowchart-sequential-access"	,  7},			//	shapetypeFlowChartMagneticTape,
	{	L"flowchart-manual-input"		,  7},			//	shapetypeFlowChartManualInput,
	{	L"flowchart-manual-operation"	,  7},			//	shapetypeFlowChartManualOperation,
	{	L"flowchart-merge"				,  7},			//	shapetypeFlowChartMerge,
	{	L"flowchart-multidocument"		,  7},			//	shapetypeFlowChartMultidocument,
	{	L""								,  7},			//	shapetypeFlowChartOfflineStorage,
	{	L"flowchart-off-page-connector"	,  7},			//	shapetypeFlowChartOffpageConnector,
	{	L"flowchart-stored-data"		,  7},			//	shapetypeFlowChartOnlineStorage,
	{	L"flowchart-or"					,  7},			//	shapetypeFlowChartOr,
	{	L"flowchart-predefined-process"	,  7},			//	shapetypeFlowChartPredefinedProcess,
	{	L"flowchart-preparation"		,  7},			//	shapetypeFlowChartPreparation,
	{	L"flowchart-process"			,  7},			//	shapetypeFlowChartProcess,
	{	L"flowchart-card"				,  7},			//	shapetypeFlowChartPunchedCard,
	{	L"flowchart-punched-tape"		,  7},			//	shapetypeFlowChartPunchedTape,
	{	L"flowchart-sort"				,  7},			//	shapetypeFlowChartSort,
	{	L"flowchart-summing-junction"	,  7},			//	shapetypeFlowChartSummingJunction,
	{	L"flowchart-terminator"			,  7},			//	shapetypeFlowChartTerminator,
	{	L"paper"						,  7},			//	shapetypeFoldedCorner,
	{	L""								,  7},			//	shapetypeFrame,
	{	L""								,  7},			//	shapetypeFunnel,
	{	L""								,  7},			//	shapetypeGear6,
	{	L""								,  7},			//	shapetypeGear9,
	{	L""								,  7},			//	shapetypeHalfFrame,
	{	L"heart"						,  7},			//	shapetypeHeart,
	{	L""								,  7},			//	shapetypeHeptagon,
	{	L"hexagon"						,  7},			//	shapetypeHexagon,
	{	L""								,  7},			//	shapetypeHomePlate,
	{	L"horizontal-scroll"			,  7},			//	shapetypeHorizontalScroll,
	{	L""								,  7},			//	shapetypeIrregularSeal1,
	{	L""								,  7},			//	shapetypeIrregularSeal2,
	{	L""								,  7},			//	shapetypeLeftArrow,
	{	L""								,  7},			//	shapetypeLeftArrowCallout,
	{	L"left-brace"					,  7},			//	shapetypeLeftBrace,
	{	L"left-bracket"					,  7},			//	shapetypeLeftBracket,
	{	L""								,  7},			//	shapetypeLeftCircularArrow,
	{	L""								,  7},			//	shapetypeLeftRightArrow,
	{	L"left-right-arrow-callout"		,  7},			//	shapetypeLeftRightArrowCallout,
	{	L""								,  7},			//	shapetypeLeftRightCircularArrow,
	{	L""								,  7},			//	shapetypeLeftRightRibbon,
	{	L""								,  7},			//	shapetypeLeftRightUpArrow,
	{	L""								,  7},			//	shapetypeLeftUpArrow,
	{	L"lightning"					,  7},			//	shapetypeLightningBolt,
	{	L""								,  5},			//	shapetypeLine,
	{	L""								,  7},			//	shapetypeLineInv,
	{	L""								,  7},			//	shapetypeMathDivide,
	{	L""								,  7},			//	shapetypeMathEqual,
	{	L""								,  7},			//	shapetypeMathMinus,
	{	L""								,  7},			//	shapetypeMathMultiply,
	{	L""								,  7},			//	shapetypeMathNotEqual,
	{	L""								,  7},			//	shapetypeMathPlus,
	{	L"moon"							,  7},			//	shapetypeMoon,
	{	L""								,  7},			//	shapetypeNonIsoscelesTrapezoid,
	{	L"forbidden"					,  7},			//	shapetypeNoSmoking,
	{	L""								,  7},			//	shapetypeNotchedRightArrow,
	{	L"octagon"						,  7},			//	shapetypeOctagon,
	{	L""								,  7},			//	shapetypeParallelogram,
	{	L"pentagon"						,  7},			//	shapetypePentagon,
	{	L""								,  7},			//	shapetypePie,
	{	L""								,  7},			//	shapetypePieWedge,
	{	L""								,  7},			//	shapetypePlaque,
	{	L""								,  7},			//	shapetypePlaqueTabs,
	{	L""								,  7},			//	shapetypePlus,
	{	L"quad-arrow"					,  7},			//	shapetypeQuadArrow,
	{	L"quad-arrow-callout"			,  7},			//	shapetypeQuadArrowCallout,
	{	L"rectangle"					,  2},			//	shapetypeRect,
	{	L"mso-spt53"					,  7},			//	shapetypeRibbon,
	{	L"mso-spt54"					,  7},			//	shapetypeRibbon2,
	{	L""								,  7},			//	shapetypeRightArrow,
	{	L""								,  7},			//	shapetypeRightArrowCallout,
	{	L"right-brace"					,  7},			//	shapetypeRightBrace,
	{	L"right-bracket"				,  7},			//	shapetypeRightBracket,
	{	L""								,  7},			//	shapetypeRound1Rect,
	{	L""								,  7},			//	shapetypeRound2DiagRect,
	{	L""								,  7},			//	shapetypeRound2SameRect,
	{	L""								,  7},			//	shapetypeRoundRect,
	{	L""								,  7},			//	shapetypeRtTriangle,
	{	L"smiley"						,  7},			//	shapetypeSmileyFace,
	{	L""								,  7},			//	shapetypeSnip1Rect,
	{	L""								,  7},			//	shapetypeSnip2DiagRect,
	{	L""								,  7},			//	shapetypeSnip2SameRect,
	{	L""								,  7},			//	shapetypeSnipRoundRect,
	{	L""								,  7},			//	shapetypeSquareTabs,
	{	L""								,  7},			//	shapetypeStar10,
	{	L""								,  7},			//	shapetypeStar12,
	{	L""								,  7},			//	shapetypeStar16,
	{	L"star24"						,  7},			//	shapetypeStar24,				//mso-spt59
	{	L"mso-spt60"					,  7},			//	shapetypeStar32,
	{	L"star4"						,  7},			//	shapetypeStar4,
	{	L"star5"						,  7},			//	shapetypeStar5,
	{	L""								,  7},			//	shapetypeStar6,
	{	L""								,  7},			//	shapetypeStar7,
	{	L"star8"						,  7},			//	shapetypeStar8,
	{	L""								,  7},			//	shapetypeStraightConnector1,
	{	L"striped-right-arrow"			,  7},			//	shapetypeStripedRightArrow,
	{	L""								,  7},			//	shapetypeSun,
	{	L""								,  7},			//	shapetypeSwooshArrow,
	{	L""								,  7},			//	shapetypeTeardrop,
	{	L""								,  7},			//	shapetypeTrapezoid,
	{	L""								,  7},			//	shapetypeTriangle,
	{	L""								,  7},			//	shapetypeUpArrow,
	{	L""								,  7},			//	shapetypeUpArrowCallout,
	{	L""								,  7},			//	shapetypeUpDownArrow,
	{	L"up-down-arrow-callout"		,  7},			//	shapetypeUpDownArrowCallout,
	{	L"mso-spt101"					,  7},			//	shapetypeUturnArrow,
	{	L"vertical-scroll"				,  7},			//	shapetypeVerticalScroll,
	{	L""								,  7},			//	shapetypeWave,
	{	L"round-callout"				,  7},			//	shapetypeWedgeEllipseCallout,
	{	L"rectangular-callout"			,  7},			//	shapetypeWedgeRectCallout,
	{	L"round-rectangular-callout"	,  7},			//	shapetypeWedgeRoundRectCallout,
	{	L"mso-spt17"					,  7},			//	shapetypeBallon,
	{	L"up-right-arrow"				,  7},			//	shapetypeRightUpArrow,
	{	L"fontwork-arch-down-pour"		,  7},			//	shapetypeTextArchDownPour,
	{	L"fontwork-arch-up-pour"		,  7},			//	shapetypeTextArchUpPour,
	{	L"mso-spt175"					,  7},			//	shapetypeTextCanDown,
	{	L"mso-spt174"					,  7},			//	shapetypeTextCanUp,
	{	L"fontwork-circle-pour"			,  7},			//	shapetypeTextCirclePour,
	{	L"fontwork-curve-down"			,  7},			//	shapetypeTextCurveDown,
	{	L"fontwork-curve-up"			,  7},			//	shapetypeTextCurveUp,
	{	L"mso-spt161"					,  7},			//	shapetypeTextDeflate,
	{	L"mso-spt163"					,  7},			//	shapetypeTextDeflateBottom,
	{	L"mso-spt166"					,  7},			//	shapetypeTextDeflateInflate,
	{	L"mso-spt167"					,  7},			//	shapetypeTextDeflateInflateDeflat,
	{	L"mso-spt165"					,  7},			//	shapetypeTextDeflateTop,
	{	L"mso-spt158"					,  7},			//	shapetypeTextDoubleWave1,
	{	L"fontwork-fade-down"			,  7},			//	shapetypeTextFadeDown,
	{	L"fontwork-fade-left"			,  7},			//	shapetypeTextFadeLeft,
	{	L"fontwork-fade-right"			,  7},			//	shapetypeTextFadeRight,
	{	L"fontwork-fade-up"				,  7},			//	shapetypeTextFadeUp,
	{	L"mso-spt162"					,  7},			//	shapetypeTextInflateBottom,
	{	L"mso-spt164"					,  7},			//	shapetypeTextInflateTop,
	{	L"mso-spt142"					,  7},			//	shapetypeTextRingInside,
	{	L"mso-spt143"					,  7},			//	shapetypeTextRingOutside,
	{	L"fontwork-wave"				,  7},			//	shapetypeTextWave1,
	{	L"mso-spt157"					,  7},			//	shapetypeTextWave2,
	{	L"mso-spt159"					,  7},			//	shapetypeTextWave4,
	{	L"mso-spt14"					,  7}			//	shapetypeThickArrow
};
