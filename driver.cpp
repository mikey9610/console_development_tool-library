/*

	CPP FILE : driver
	
*/
#include "cdt_gbutton.h"
#include "cdt_gpanel.h"
using namespace cdt;
using namespace cdt::graphic;

#include "cdt_ds_set.cpp"
#include "cdt_ds_set.h"
using namespace cdt::data_structure;

int main(int argc, char** argv) {
	/*
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
	*/
	
	CDT_Set<int> s1;
	CDT_Set<int> s2;
	
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(5);
	s1.insert(5);
	s1.insert(6);
	
	s2.insert(1);
	s2.insert(3);
	s2.insert(5);
	s2.insert(7);
	s2.insert(9);
	
	auto u = s1.union_s(s2);
	auto i = s1.intersection_s(s2);
	auto d = s1.difference_s(s2);
	
	cout << "s1 : ";
	for(const auto& v : s1)
		cout << v << " ";
	cout << endl;
	
	cout << "s2 : ";
	for(const auto& v : s2)
		cout << v << " ";
	cout << endl;
	
	cout << "s1 + s2 : ";
	for(const auto& v : u)
		cout << v << " ";
	cout << endl;
	
	cout << "s1 * s2 : ";
	for(const auto& v : i)
		cout << v << " ";
	cout << endl;
	
	cout << "s1 - s2 : ";
	for(const auto& v : d)
		cout << v << " ";
	cout << endl;
	
	cout << "s2 - s1 : ";
	for(const auto& v : s2-s1)
		cout << v << " ";
	cout << endl;
	
	return 0;
}
