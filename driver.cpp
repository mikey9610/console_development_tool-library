/*

	CPP FILE : driver
	
*/

#include "cdt_gbutton.h"
using namespace cdt;
using namespace cdt::graphic;

int main(int argc, char** argv) {
	
	GButton b1("button1");
	b1.setBounds(4,2,6,4);
	b1.setBackground(C_YELLOW);
	
	GButton b2("button2");
	b2.setBounds(6,3,10,5);
	b2.setBackground(C_CYAN);
	
	GButton b3("intersection");
	b3.setBounds(*b1.getIntersection(b2));
	b3.setBackground(C_WHITE);
	
	b1.render();
	b2.render();
	b3.render();
	getchar();
	
	return 0;
}
