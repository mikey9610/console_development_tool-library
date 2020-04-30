/*

	HEADER FILE : cdt_gcomponent_i
	
	interface < GComponent_i > : super class of all derived graphic classes
	
*/

#ifndef CDT_GCOMPONENT_I_H
#define CDT_GCOMPONENT_I_H

#include "cdt_graphic.h"

namespace cdt {
namespace graphic {
	
class GComponent_i : public GRectangle {

protected:
	
	string name_;
	// field < name >
	
	Color foreground_;
	Color background_;
	// field < foreground , background > : foreground and background Color 
	
	bool enabled_;
	// field < enabled > 
	
	bool visible_;
	// field < visible >	
		
	GRectangle* parent_;
	// field < confines > : parent bounds	

	virtual bool equalsInner(const Object_i* obj) const override {	return this == obj;	}
	// virtual method < equalsInner(Object_i*) > : override
	
	GComponent_i(string name="gcomponent")
	 :	Object_i(310),
		name_(name),
		foreground_(C_BRIGHT_WHITE),
		background_(C_BLACK),
		enabled_(true),
		visible_(true),
		parent_(nullptr) {}	 
	// constructor (concealed)
	
	GRectangle* getAbsBounds() const;	
	// method < getAbsbounds() >
	// - get absolute boundary
	
	virtual void setParent(GRectangle* parent) {
		if(parent_ != nullptr)	delete parent_;
		parent_ = parent;
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
	
	inline string getName() const {	return this->name_;	}
	inline Color getForeground() const {	return this->foreground_;	}
	inline Color getBackground() const {	return this->background_;	}
	inline bool isEnabled() const {	return this->enabled_;	}
	inline bool isVisible() const {	return this->visible_;	}
	// method < get >
	
//	GRectangle& getBounds(GRectangle&) const;
	/*
		get methods
	*/
	
	inline void setName(string name) {	this->name_ = name;	}
	inline void setForeground(Color foreground) {	this->foreground_ = foreground;	}
	inline void setBackground(Color background) {	this->background_ = background;	}
	inline void setEnabled(bool enabled) {	this->enabled_ = enabled;	}
	inline void setVisible(bool visible) {	this->visible_ = visible;	}
	// method < set >

	
//	virtual void notify(GEvent*);
	

	virtual void render() {
		GRectangle* confines = getAbsBounds();
		if(confines == nullptr)	return;
					
		renderer.setColor(foreground_,background_);
		for(int h=0; h<confines->getHeight(); h++) {
			renderer.setPos(confines->getX(),confines->getY()+h);
			for(int w=0; w<confines->getWidth(); w++)	cout << " ";			
		}
	}
	// method < render() >

	virtual string toString() const override {	return this->name_;	}
	//	virtual method < toString() > : override
	
};

}
}

#endif
