/*

	HEADER FILE : cdt_sql
	
*/

#ifndef CDT_SQL_H
#define CDT_SQL_H

#include <iostream>
using namespace std;
#include "cdt_sql_table.h"

namespace cdt {

class CDT_SQL {
public:
	inline static CDT_SQL_Table* create(string name) {	return new CDT_SQL_Table(name);	}
	// static method < craete() >
	// - create new table


};

}

#endif
