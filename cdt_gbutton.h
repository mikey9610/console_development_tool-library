/*

	HEADER FILE : cdt_gbutton
	
	class < GButton > : graphic class that is clickable
	
*/

#ifndef CDT_GBUTTON_H
#define CDT_GBUTTON_H

#include "cdt_gcomponent_i.h"
#include "cdt_glabel_i.h"

namespace cdt {
namespace graphic {
	
class GButton : public GComponent_i, public GLabel_i {	
protected:
	
	

public:
	
	GButton(string name="button")
	 :	Object_i(311),
	 	GComponent_i(name) {}
	// constructor
	
	virtual void render() override {
		GComponent_i::render();
		GLabel_i::render(getAbsBounds());
	}

	virtual string toString() const override {	return this->name_;	}
	//	virtual method < toString() > : override
	
};

}
}

#endif
