/*

	HEADER FILE : cdt_gcontainer_i
	
	interface < GContainer_i > : graphic class that includes other graphic objects
	
*/

#ifndef CDT_GCONTAINER_I_H
#define CDT_GCONTAINER_I_H

#include <vector>
#include "cdt_gcomponent_i.h"

namespace cdt {
namespace graphic {
	
class GContainer_i : public GComponent_i {

protected:
	
	vector<GComponent_i*> components_;
	//	field < components > : list of graphic objects which this contains
		
	GContainer_i(string name="gcontainer")
	 :	Object_i(320),
		GComponent_i(name) {}
	// constructor (concealed)
	
	virtual void setParent(GRectangle* parent) override {
		GComponent_i::setParent(parent);
		for(auto& comp : components_)
			comp->setParent(getAbsBounds());
	}
	// method < setParent(GRectangle*) >
	// - reset parent boundary

	virtual void render(GPoint p) {	
		if(getAbsBounds()->contains(p)) {
			renderer.setColor(foreground_,background_);
			renderer.setPos(p);
			cout << " ";
		}
	}
	inline virtual void render(int x, int y) {	GComponent_i::render(GPoint(x,y));	}
	// method < render(GPoint) >
	// - render specified location	

public:	
	
	inline GComponent_i* getComponent(int n) const {	return (components_.size()>n)?this->components_[n-1]:nullptr;	}
	// method < getComponent(int) >
	// - return nth component
	
	GComponent_i* getComponentAt(GPoint) const;
	inline GComponent_i* getComponentAt(int x, int y) const {	return getComponentAt(GPoint(x,y));	}
	// method < getComponent() >
	// - return component in specified location

	GComponent_i* add(GComponent_i*);
	GComponent_i* add(GComponent_i*,int);
	// method < add(GComponent*) >
	// - add graphic object
	
	virtual void render() override {
		GComponent_i::render();
		for(auto& comp : components_)
			comp->render();
	}
	// virtual method < render() > : override

	virtual string toString() const override {
		string str;	
		str = "[ " + name_ + " : ";
		for(auto& comp : components_)
			str = str + comp->toString() + " ";
		return str + "]";
	}
	// virtual method < toString() > : override

};

}
}

#endif
