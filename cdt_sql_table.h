/*

	HEADER FILE : cdt_sql_table
	
*/

#ifndef CDT_SQL_TABLE_H
#define CDT_SQL_TABLE_H

#include <iostream>
#include <vector>
using namespace std;
#include "cdt_sql_datatype.h"

namespace cdt {

class CDT_SQL_Table {

friend class CDT_SQL;
	
protected:
	
	string name_;
	// field < name >
	
	
	
	CDT_SQL_Table(string name)
	 : name_(name) {}
	// constructor (concealed)

public:
	
	deque<
	
	
};

}

#endif
