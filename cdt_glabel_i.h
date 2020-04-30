/*

	HEADER FILE : cdt_glabel_i
	
	interface < GLabel_i > : graphic interface that has label
	
*/

#ifndef CDT_GLABEL_I_H
#define CDT_GLABEL_I_H

#include <iostream>
using namespace std;

namespace cdt {
namespace graphic {
	
class GLabel_i {
protected:
	
	string label_;
	// field < label >
	
	void render(GRectangle* confines) {
		if(confines == nullptr)
			return;
	}
	
	GLabel_i() {} 
	// constructor (concealed)

public:
		
	inline string getLabel() const {	return this->label_;	}
	// method < get >
	
	inline void setLabel(string label) {	this->label_ = label;	}
	// method < set >
		
};

}
}

#endif
