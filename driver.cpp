/*

	CPP FILE : driver
	
*/

#include "cdt_gbutton.h"
#include "cdt_gpanel.h"
using namespace cdt::graphic;

#include "cdt_sql.h"
using namespace cdt;

int main(int argc, char** argv) {
	CDT_SQL_Table* table = CDT_SQL::create("myTable");
	
	CDT_SQL_Attribute* a;
	attributeA<int>* b = new attributeA<int>();
	a = b;
	
	cout << b->getValue();
	
	return 0;
}
