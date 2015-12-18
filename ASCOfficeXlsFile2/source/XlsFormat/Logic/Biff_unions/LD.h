#pragma once

#include <Logic/CompositeObject.h>

namespace XLS
{

// Logical representation of LD union of records 
class LD: public CompositeObject
{
	BASE_OBJECT_DEFINE_CLASS_NAME(LD)
public:
	LD();
	~LD();

	BaseObjectPtr clone();

	virtual const bool loadContent(BinProcessor& proc);
	int serialize (std::wostream & _stream, const std::wstring & entries);

	static const ElementType	type = typeLD;

	BaseObjectPtr m_Legend;
	BaseObjectPtr m_ATTACHEDLABEL;
	BaseObjectPtr m_Pos;
	BaseObjectPtr m_FRAME;
	BaseObjectPtr m_TEXTPROPS;

//-----------------------------------------------
	int m_countSeries;
};

} // namespace XLS

