#pragma once

#include <Logic/CompositeObject.h>

namespace XLS
{


// Logical representation of SERIESFORMAT union of records 
class SERIESFORMAT: public CompositeObject
{
	BASE_OBJECT_DEFINE_CLASS_NAME(SERIESFORMAT)
public:
	SERIESFORMAT();
	~SERIESFORMAT();

	BaseObjectPtr clone();

	virtual const bool loadContent(BinProcessor& proc);

	static const ElementType	type = typeSERIESFORMAT;

	int serialize_legend(std::wostream & _stream, int idx);

	BaseObjectPtr				m_SS;
	std::vector<BaseObjectPtr>	m_arPtSS;
	std::vector<BaseObjectPtr>	m_arAI;

	BaseObjectPtr				m_Series;
	
	BaseObjectPtr				m_SerToCrt;
	BaseObjectPtr				m_SerParent;

	struct _series_ex
	{
		BaseObjectPtr	legendException;
		BaseObjectPtr	attachedLABEL;
		BaseObjectPtr	textPROPS;
	};
	std::vector<_series_ex>		m_SeriesEx;

//-----------------------------------------------------------------------

	
};
} // namespace XLS

