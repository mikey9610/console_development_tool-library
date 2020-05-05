/*

	HEADER FILE : cdt_sql_entity
	
*/

#ifndef CDT_SQL_ENTITY_H
#define CDT_SQL_ENTITY_H

#include "cdt_sql_attribute.h"

namespace cdt {

class CDT_SQL_Entity {

friend class CDT_SQL;
	
protected:
	
	vecotr<CDT_SQL_Attribute> attribute_;
		
	CDT_SQL_Entity() {}
	// constructor (concealed)
	
public:
	
	
};

}

#endif
