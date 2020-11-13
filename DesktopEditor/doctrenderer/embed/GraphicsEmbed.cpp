#include "GraphicsEmbed.h"

JSSmart<CJSValue> CGraphicsEmbed::init(JSSmart<CJSValue> width_px, JSSmart<CJSValue> height_px, JSSmart<CJSValue> width_mm, JSSmart<CJSValue> height_mm)
{
    m_pInternal->init(width_px->toDouble(), height_px->toDouble(), width_mm->toDouble(), height_mm->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::EndDraw()
{
    m_pInternal->EndDraw();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::put_GlobalAlpha(JSSmart<CJSValue> enable, JSSmart<CJSValue> globalAlpha)
{
    m_pInternal->put_GlobalAlpha(enable->toBool(), globalAlpha->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::Start_GlobalAlpha()
{
    m_pInternal->Start_GlobalAlpha();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::End_GlobalAlpha()
{
    m_pInternal->End_GlobalAlpha();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::p_color(JSSmart<CJSValue> r, JSSmart<CJSValue> g, JSSmart<CJSValue> b, JSSmart<CJSValue> a)
{
    m_pInternal->p_color(r->toInt32(), g->toInt32(), b->toInt32(), a->toInt32());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::p_width(JSSmart<CJSValue> w)
{
    m_pInternal->p_width(w->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::p_dash(JSSmart<CJSValue> params)
{
    JSSmart<CJSArray> items = params->toArray();
    size_t length = items->getCount();
    double* dash = NULL;
    if(length > 0)
        dash = new double[length];
    for(size_t i = 0; i < length; i++)
        dash[i] = items->get(i)->toDouble();
    m_pInternal->p_dash(length, dash);
    RELEASEARRAYOBJECTS(dash);
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::b_color1(JSSmart<CJSValue> r, JSSmart<CJSValue> g, JSSmart<CJSValue> b, JSSmart<CJSValue> a)
{
    m_pInternal->b_color1(r->toInt32(), g->toInt32(), b->toInt32(), a->toInt32());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::b_color2(JSSmart<CJSValue> r, JSSmart<CJSValue> g, JSSmart<CJSValue> b, JSSmart<CJSValue> a)
{
    m_pInternal->b_color2(r->toInt32(), g->toInt32(), b->toInt32(), a->toInt32());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::transform(JSSmart<CJSValue> sx, JSSmart<CJSValue> shy, JSSmart<CJSValue> shx, JSSmart<CJSValue> sy, JSSmart<CJSValue> tx, JSSmart<CJSValue> ty)
{
    m_pInternal->transform(sx->toDouble(), shy->toDouble(), shx->toDouble(), sy->toDouble(), tx->toDouble(), ty->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::CalculateFullTransform(JSSmart<CJSValue> isInvertNeed)
{
    m_pInternal->CalculateFullTransform();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::_s()
{
    m_pInternal->_s();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::_e()
{
    m_pInternal->_e();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::_z()
{
    m_pInternal->_z();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::_m (JSSmart<CJSValue> x,  JSSmart<CJSValue> y)
{
    m_pInternal->_m(x->toDouble(), y->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::_l (JSSmart<CJSValue> x,  JSSmart<CJSValue> y)
{
    m_pInternal->_l(x->toDouble(), y->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::_c (JSSmart<CJSValue> x1, JSSmart<CJSValue> y1, JSSmart<CJSValue> x2, JSSmart<CJSValue> y2, JSSmart<CJSValue> x3, JSSmart<CJSValue> y3)
{
    m_pInternal->_c(x1->toDouble(), y1->toDouble(), x2->toDouble(), y2->toDouble(), x3->toDouble(), y3->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::_c2(JSSmart<CJSValue> x1, JSSmart<CJSValue> y1, JSSmart<CJSValue> x2, JSSmart<CJSValue> y2)
{
    m_pInternal->_c2(x1->toDouble(), y1->toDouble(), x2->toDouble(), y2->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::ds()
{
    m_pInternal->ds();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::df()
{
    m_pInternal->df();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::save()
{
    m_pInternal->save();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::restore()
{
    m_pInternal->restore();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::clip()
{
    m_pInternal->clip();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::reset()
{
    m_pInternal->reset();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::transform3(JSSmart<CJSValue> sx, JSSmart<CJSValue> shy, JSSmart<CJSValue> shx, JSSmart<CJSValue> sy, JSSmart<CJSValue> tx, JSSmart<CJSValue> ty, JSSmart<CJSValue> isNeedInvert)
{
    m_pInternal->transform3(sx->toDouble(), shy->toDouble(), shx->toDouble(), sy->toDouble(), tx->toDouble(), ty->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::FreeFont()
{
    m_pInternal->FreeFont();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::ClearLastFont()
{
    m_pInternal->ClearLastFont();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::drawImage2(JSSmart<CJSValue> img, JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> w, JSSmart<CJSValue> h, JSSmart<CJSValue> alpha, JSSmart<CJSValue> srcRect)
{
    m_pInternal->drawImage(img->toStringW(), x->toDouble(), y->toDouble(), w->toDouble(), h->toDouble(), alpha->toInt32());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::drawImage (JSSmart<CJSValue> img, JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> w, JSSmart<CJSValue> h, JSSmart<CJSValue> alpha, JSSmart<CJSValue> srcRect, JSSmart<CJSValue> nativeImage)
{
    m_pInternal->drawImage(img->toStringW(), x->toDouble(), y->toDouble(), w->toDouble(), h->toDouble(), alpha->toInt32());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::GetFont()
{
    return CJSContext::createString(m_pInternal->GetFont());
}
JSSmart<CJSValue> CGraphicsEmbed::font(JSSmart<CJSValue> font_id, JSSmart<CJSValue> font_size)
{
    m_pInternal->font();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::SetFont(JSSmart<CJSValue> path, JSSmart<CJSValue> face, JSSmart<CJSValue> size, JSSmart<CJSValue> style)
{
    m_pInternal->SetFont(path->toStringW(), face->toInt32(), size->toDouble(), style->toInt32());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::SetTextPr(JSSmart<CJSValue> textPr, JSSmart<CJSValue> theme)
{
    m_pInternal->SetTextPr();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::SetFontSlot(JSSmart<CJSValue> path, JSSmart<CJSValue> face, JSSmart<CJSValue> size, JSSmart<CJSValue> style)
{
    m_pInternal->SetFont(path->toStringW(), face->toInt32(), size->toDouble(), style->toInt32());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::GetTextPr()
{
    m_pInternal->GetTextPr();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::FillText(JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> text)
{
    m_pInternal->FillText(x->toDouble(), y->toDouble(), text->toInt32());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::t(JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> _arr)
{
    m_pInternal->t(x->toDouble(), y->toDouble(), _arr->toStringW());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::FillText2(JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> text, JSSmart<CJSValue> cropX, JSSmart<CJSValue> cropW)
{
    m_pInternal->FillText(x->toDouble(), y->toDouble(), text->toInt32());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::t2(JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> _arr, JSSmart<CJSValue> cropX, JSSmart<CJSValue> cropW)
{
    m_pInternal->t2();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::FillTextCode(JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> lUnicode)
{
    m_pInternal->FillText(x->toDouble(), y->toDouble(), lUnicode->toInt32());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::tg(JSSmart<CJSValue> text, JSSmart<CJSValue> x, JSSmart<CJSValue> y)
{
    m_pInternal->tg(text->toInt32(), x->toDouble(), y->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::charspace(JSSmart<CJSValue> space)
{
    m_pInternal->charspace();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::private_FillGlyph (JSSmart<CJSValue> pGlyph, JSSmart<CJSValue> _bounds)
{
    m_pInternal->private_FillGlyph();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::private_FillGlyphC(JSSmart<CJSValue> pGlyph, JSSmart<CJSValue> cropX, JSSmart<CJSValue> cropW)
{
    m_pInternal->private_FillGlyphC();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::private_FillGlyph2(JSSmart<CJSValue> pGlyph)
{
    m_pInternal->private_FillGlyph2();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::SetIntegerGrid(JSSmart<CJSValue> param)
{
    m_pInternal->SetIntegerGrid(param->toBool());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::GetIntegerGrid()
{
    m_pInternal->GetIntegerGrid();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::DrawStringASCII (JSSmart<CJSValue> name, JSSmart<CJSValue> size, JSSmart<CJSValue> bold, JSSmart<CJSValue> italic, JSSmart<CJSValue> text, JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> bIsHeader)
{
    m_pInternal->DrawStringASCII();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::DrawStringASCII2(JSSmart<CJSValue> name, JSSmart<CJSValue> size, JSSmart<CJSValue> bold, JSSmart<CJSValue> italic, JSSmart<CJSValue> text, JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> bIsHeader)
{
    m_pInternal->DrawStringASCII2();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::DrawHeaderEdit(JSSmart<CJSValue> yPos, JSSmart<CJSValue> lock_type, JSSmart<CJSValue> sectionNum, JSSmart<CJSValue> bIsRepeat, JSSmart<CJSValue> type)
{
    m_pInternal->DrawHeaderEdit(yPos->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::DrawFooterEdit(JSSmart<CJSValue> yPos, JSSmart<CJSValue> lock_type, JSSmart<CJSValue> sectionNum, JSSmart<CJSValue> bIsRepeat, JSSmart<CJSValue> type)
{
    m_pInternal->DrawFooterEdit(yPos->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::DrawLockParagraph (JSSmart<CJSValue> lock_type, JSSmart<CJSValue> x, JSSmart<CJSValue> y1, JSSmart<CJSValue> y2)
{
    m_pInternal->DrawLockParagraph();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::DrawLockObjectRect(JSSmart<CJSValue> lock_type, JSSmart<CJSValue> x, JSSmart<CJSValue> y,  JSSmart<CJSValue> w, JSSmart<CJSValue> h)
{
    m_pInternal->DrawLockObjectRect();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::DrawEmptyTableLine(JSSmart<CJSValue> x1, JSSmart<CJSValue> y1, JSSmart<CJSValue> x2, JSSmart<CJSValue> y2)
{
    m_pInternal->DrawEmptyTableLine(x1->toDouble(), y1->toDouble(), x2->toDouble(), y2->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::DrawSpellingLine  (JSSmart<CJSValue> y0, JSSmart<CJSValue> x0, JSSmart<CJSValue> x1, JSSmart<CJSValue> w)
{
    m_pInternal->DrawSpellingLine(y0->toDouble(), x0->toDouble(), x1->toDouble(), w->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::drawHorLine (JSSmart<CJSValue> align, JSSmart<CJSValue> y, JSSmart<CJSValue> x, JSSmart<CJSValue> r, JSSmart<CJSValue> penW)
{
    m_pInternal->drawHorLine(align->toInt32(), y->toDouble(), x->toDouble(), r->toDouble(), penW->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::drawHorLine2(JSSmart<CJSValue> align, JSSmart<CJSValue> y, JSSmart<CJSValue> x, JSSmart<CJSValue> r, JSSmart<CJSValue> penW)
{
    m_pInternal->drawHorLine2(align->toInt32(), y->toDouble(), x->toDouble(), r->toDouble(), penW->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::drawVerLine (JSSmart<CJSValue> align, JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> b, JSSmart<CJSValue> penW)
{
    m_pInternal->drawVerLine(align->toInt32(), x->toDouble(), y->toDouble(), b->toDouble(), penW->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::drawHorLineExt(JSSmart<CJSValue> align, JSSmart<CJSValue> y, JSSmart<CJSValue> x, JSSmart<CJSValue> r, JSSmart<CJSValue> penW, JSSmart<CJSValue> leftMW, JSSmart<CJSValue> rightMW)
{
    m_pInternal->drawHorLineExt(align->toInt32(), y->toDouble(), x->toDouble(), r->toDouble(), penW->toDouble(), leftMW->toDouble(), rightMW->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::rect     (JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> w, JSSmart<CJSValue> h)
{
    m_pInternal->rect(x->toDouble(), y->toDouble(), w->toDouble(), h->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::TableRect(JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> w, JSSmart<CJSValue> h)
{
    m_pInternal->TableRect(x->toDouble(), y->toDouble(), w->toDouble(), h->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::AddClipRect(JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> w, JSSmart<CJSValue> h)
{
    m_pInternal->AddClipRect(x->toDouble(), y->toDouble(), w->toDouble(), h->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::RemoveClipRect()
{
    m_pInternal->RemoveClipRect();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::SetClip(JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> w, JSSmart<CJSValue> h)
{
    m_pInternal->SetClip(x->toDouble(), y->toDouble(), w->toDouble(), h->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::RemoveClip()
{
    m_pInternal->RemoveClip();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::drawCollaborativeChanges(JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> w, JSSmart<CJSValue> h, JSSmart<CJSValue> r, JSSmart<CJSValue> g, JSSmart<CJSValue> b, JSSmart<CJSValue> a)
{
    m_pInternal->drawCollaborativeChanges(x->toDouble(), y->toDouble(), w->toDouble(), h->toDouble(), r->toInt32(), g->toInt32(), b->toInt32(), a->toInt32());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::drawMailMergeField(JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> w, JSSmart<CJSValue> h)
{
    m_pInternal->drawMailMergeField(x->toDouble(), y->toDouble(), w->toDouble(), h->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::drawSearchResult  (JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> w, JSSmart<CJSValue> h)
{
    m_pInternal->drawSearchResult(x->toDouble(), y->toDouble(), w->toDouble(), h->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::drawFlowAnchor    (JSSmart<CJSValue> x, JSSmart<CJSValue> y)
{
    m_pInternal->drawFlowAnchor(x->toDouble(), y->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::SavePen()
{
    m_pInternal->SavePen();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::RestorePen()
{
    m_pInternal->RestorePen();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::SaveBrush()
{
    m_pInternal->SaveBrush();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::RestoreBrush()
{
    m_pInternal->RestoreBrush();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::SavePenBrush()
{
    m_pInternal->SavePenBrush();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::RestorePenBrush()
{
    m_pInternal->RestorePenBrush();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::SaveGrState()
{
    m_pInternal->SaveGrState();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::RestoreGrState()
{
    m_pInternal->RestoreGrState();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::StartClipPath()
{
    m_pInternal->StartClipPath();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::EndClipPath()
{
    m_pInternal->EndClipPath();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::StartCheckTableDraw()
{
    m_pInternal->StartCheckTableDraw();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::EndCheckTableDraw(JSSmart<CJSValue> bIsRestore)
{
    m_pInternal->EndCheckTableDraw(bIsRestore->toBool());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::SetTextClipRect(JSSmart<CJSValue> _l, JSSmart<CJSValue> _t, JSSmart<CJSValue> _r, JSSmart<CJSValue> _b)
{
    m_pInternal->SetTextClipRect(_l->toDouble(), _t->toDouble(), _r->toDouble(), _b->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::AddSmartRect   (JSSmart<CJSValue> x,  JSSmart<CJSValue> y,  JSSmart<CJSValue> w,  JSSmart<CJSValue> h, JSSmart<CJSValue> pen_w)
{
    m_pInternal->AddSmartRect(x->toDouble(), y->toDouble(), w->toDouble(), h->toDouble(), pen_w->toDouble());
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::CheckUseFonts2 (JSSmart<CJSValue> _transform)
{
    m_pInternal->CheckUseFonts2();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::UncheckUseFonts2()
{
    m_pInternal->UncheckUseFonts2();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::Drawing_StartCheckBounds(JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> w, JSSmart<CJSValue> h)
{
    m_pInternal->Drawing_StartCheckBounds();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::Drawing_EndCheckBounds()
{
    m_pInternal->Drawing_EndCheckBounds();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::DrawPresentationComment(JSSmart<CJSValue> type, JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> w, JSSmart<CJSValue> h)
{
    m_pInternal->DrawPresentationComment();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::DrawPolygon(JSSmart<CJSValue> oPath, JSSmart<CJSValue> lineWidth, JSSmart<CJSValue> shift)
{
    m_pInternal->DrawPolygon();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::DrawFootnoteRect(JSSmart<CJSValue> x, JSSmart<CJSValue> y, JSSmart<CJSValue> w, JSSmart<CJSValue> h)
{
    m_pInternal->DrawFootnoteRect();
    return NULL;
}
JSSmart<CJSValue> CGraphicsEmbed::toDataURL(JSSmart<CJSValue> type)
{
    return CJSContext::createString(m_pInternal->toDataURL(type->toStringW()));
}
