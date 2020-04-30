/*

	HEADER FILE : cdt_gpoint
	
	class < GPoint > : point that has coordinate x and y
	
*/

#ifndef CDT_GPOINT_H
#define CDT_GPOINT_H

#include <stdexcept>
#include <Windows.h>
#include "cdt_object_i.h"

namespace cdt {
namespace graphic {

class GPoint : virtual public Object_i {
protected:
	
	int x_;
	int y_;
	// field ( x , y ) : coordinate x , y
	
	virtual bool equalsInner(const Object_i* obj) const override {
		auto objPoint = dynamic_cast<const GPoint*>(obj);
		return x_ == objPoint->x_ && y_ == objPoint->y_;
	}
	// virtual method < equalsInner(Object_i*) > : override
	
public:
	
	GPoint()
	 : Object_i(301), x_(0), y_(0) {}	 
	 
	GPoint(int x, int y)
	 : Object_i(301), x_(x), y_(y) {}
	// constructor - 2
	
	inline int getX() const {	return this->x_;	}
	inline int getY() const {	return this->y_;	}
	inline GPoint getLocation() const {	return *this;	}
	// method < get >	
	
	inline void setX(int x) {	(x<0) ? throw out_of_range("error : x must not be negative") : this->x_ = x;	}
	inline void setY(int y) {	(y<0) ? throw out_of_range("error : y must not be negative") : this->y_ = y;	}
	inline void setLocation(int x, int y) {
		setX(x);
		setY(y);
	}
	inline void setLocation(GPoint p) {
		setX(p.x_);
		setY(p.y_);
	}
	// method < set >
	// - constraint : x >=0 & y>=0
	
	inline void move(int x, int y) {	setLocation(x,y);	}
	// method < move(int,int) >
	// - same as method < setLocation(int,int) >
		
	inline void translate(int dx, int dy) {
		setX(x_+dx);
		setY(y_+dy);
	}
	// method < translate(int,int) >
	// - relocate this GPoint object by parameter < dx , dy >
	
	inline operator COORD() const {	return COORD{x_,y_};	}
	// type conversion < COORD >
	
	virtual string toString() const override {	return "("+to_string(x_)+","+to_string(y_)+")";	}
	//	virtual method < toString() > : override
	
};	
	
}	
}

#endif
