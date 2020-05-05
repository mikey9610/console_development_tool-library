/*

	HEADER FILE : cdt_sql_attribute
	
*/

#ifndef CDT_SQL_ATTRIBUTE_H
#define CDT_SQL_ATTRIBUTE_H

#include <iostream>
using namespace std;

namespace cdt {

class CDT_SQL_Attribute {

friend class CDT_SQL;
	
protected:
	
	
public:
	
	inline auto getValue() const {}
};

template <typename data_type>
class attributeA : public CDT_SQL_Attribute {
protected:
	
	data_type value_;

public:
	attributeA() : value_(1) {}
	
	inline auto getValue() const {	return this->value_;	}
};

}

#endif
