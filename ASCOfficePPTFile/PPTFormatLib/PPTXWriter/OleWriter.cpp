#include "OleWriter.h"


OleWriter::OleWriter(COleElement *pOleElement, CRelsGenerator *pRels) :
    m_pOleElement(pOleElement), m_pRels(pRels) {}

void OleWriter::Convert(PPTX::Logic::GraphicFrame &oGraphicFrame)
{
    if (!m_pOleElement)
        return;

    if (/*m_pOleElement->m_xmlRawData.empty() || */true)
    {
        oGraphicFrame.nvGraphicFramePr = new PPTX::Logic::NvGraphicFramePr;
        FillNvGraphicFramePr(oGraphicFrame.nvGraphicFramePr.get2());

        oGraphicFrame.xfrm = new PPTX::Logic::Xfrm;
        FillXfrm(oGraphicFrame.xfrm.get2());

    }
}


void OleWriter::FillNvGraphicFramePr(PPTX::Logic::NvGraphicFramePr& oNvGFPr)
{
    oNvGFPr.cNvPr.id = m_pOleElement->m_lID;
    oNvGFPr.cNvPr.name = m_pOleElement->m_sName;

    PPTX::Logic::Ext ext;
    ext.uri = L"{FF2B5EF4-FFF2-40B4-BE49-F238E27FC236}";
    oNvGFPr.nvPr.extLst.push_back(ext);
}

void OleWriter::FillXfrm(PPTX::Logic::Xfrm &oXFRM)
{
    oXFRM.node_name = L"p:xfrm";
    double multip1 = m_pOleElement->m_bAnchorEnabled ? 1587.5 : 1;

    oXFRM.offX = round(m_pOleElement->m_rcAnchor.left * multip1);
    oXFRM.offY = round(m_pOleElement->m_rcAnchor.top  * multip1);

    oXFRM.extX = round(m_pOleElement->m_rcAnchor.GetWidth()  * multip1);
    oXFRM.extY = round(m_pOleElement->m_rcAnchor.GetHeight() * multip1);
}

