/*

	HEADER FILE : cdt_glabel_i
	
	interface < GLabel_i > : graphic interface that has label
	
*/

#ifndef CDT_GLABEL_I_H
#define CDT_GLABEL_I_H

#include <iostream>
using namespace std;
#include "cdt_math.h"

namespace cdt {
namespace graphic {
	
class GLabel_i {
protected:

	const int PREFERRED = -1;
	
	string label_;
	// field < label >
	
	int lines_;
	// field < lines >
	
	int length_;
	// field < length >
	
	void render(GRectangle* confines) {
		if(confines == nullptr)
			return;
			
		if(this->lines_ > confines->getHeight())
			this->lines_ = confines->getHeight();
			
		if(this->length_ > confines->getWidth() || this->length_ == PREFERRED)
			this->length_ = confines->getWidth();
		
		if(this->lines_ == PREFERRED) {
			if(this->label_.length() > confines->getWidth()*confines->getHeight()) 
				this->lines_ = confines->getHeight();
			else {
				this->lines_ = math::div_in_row(this->label_.length(),this->length_);
			}
		}
		else {
			this->length_ = math::div_in_row(this->label_.length(),this->lines_);
		}
		
		for(int row=0;row<lines_;row++) {
			renderer.setPos(confines->getX()+(confines->getWidth()-length_)/2 , confines->getY()+(confines->getHeight()-lines_)/2+row);
			for(int col=0;col<length_&&row*length_+col<label_.length();col++)
				cout << label_[row*length_+col];
		}
	
	}
	
	GLabel_i() 
	 :	label_(""),
	 	lines_(PREFERRED),
	 	length_(PREFERRED) {}
	// constructor (concealed)

public:
		
	inline string getLabel() const {	return this->label_;	}
	inline void setLines(int lines) {	this->lines_ = (lines<1) ? PREFERRED : lines;	}
	inline void setLength(int length) {	this->length_ = (length<1) ? PREFERRED : length;	}
	// method < get >
	
	inline void setLabel(string label) {	this->label_ = label;	}
	// method < set >
	
	
	
};

}
}

#endif
