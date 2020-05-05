/*

	CPP FILE : driver
	
*/

#include "cdt_gbutton.h"
#include "cdt_gpanel.h"
using namespace cdt;
using namespace cdt::graphic;

int main(int argc, char** argv) {
	
	GPanel p1("myPanel");
	p1.setBounds(4,4,20,15);
	p1.setBackground(C_BRIGHT_WHITE);
	
	GButton b1("button1");
	b1.setBounds(4,2,6,4);
	b1.setForeground(C_BLACK);
	b1.setBackground(C_YELLOW);
	b1.setLabel("button");
	
	GButton b2("button2");
	b2.setBounds(6,3,10,5);
	b2.setBackground(C_CYAN);
	
	GButton b3("intersection");
	b3.setBounds(*b1.getIntersection(b2));
	b3.setBackground(C_WHITE);
	
	p1.add(&b1);
	p1.add(&b2);
	p1.add(&b3);
	p1.render();
	
	getchar();
	
	return 0;
}
