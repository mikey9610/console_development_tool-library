/*

	HEADER FILE : cdt_grectangle
	
	class < GRectangle > : rectangle that is expressed by start point and dimension
	
*/

#ifndef CDT_GRECTANGLE_H
#define CDT_GRECTANGLE_H

#include <stdexcept>
#include "cdt_gpoint.h"
#include "cdt_gdimension.h"

namespace cdt {
namespace graphic {

class GRectangle : public GPoint, public GDimension {
protected:
	
	virtual bool equalsInner(const Object_i* obj) const override {
		return (dynamic_cast<const GPoint*>(obj))->equals(&getLocation())
		 && (dynamic_cast<const GDimension*>(obj))->equals(&getSize());
	}
	// virtual method < equalsInner(Object_i*) > : override
	
public:
	
	GRectangle()
	 : Object_i(303), GPoint(0,0), GDimension(0,0) {}	 
	 
	GRectangle(int width, int height)
	 : Object_i(303), GPoint(0,0), GDimension(width,height) {}
	
	GRectangle(GDimension d)
	 : Object_i(303), GPoint(0,0), GDimension(d) {}
	
	GRectangle(int x, int y, int width, int height)
	 : Object_i(303), GPoint(x,y), GDimension(width,height) {}
	
	GRectangle(GPoint p)
	 : Object_i(303), GPoint(p), GDimension(0,0) {}
	
	GRectangle(GPoint p, GDimension d)
	 : Object_i(303), GPoint(p), GDimension(d) {}
	// constructor - 6
	
	inline GRectangle getBounds() const {	return *this;	}
	// method < get >
	
	inline void setBounds(int x, int y, int width, int height) {
		setLocation(x,y);
		setSize(width,height);
	}
	inline void setBounds(GRectangle r) {
		setLocation(r.getLocation());
		setSize(r.getSize());
	}		
	// method < set >
	
	
	inline bool contains(int x, int y) const {
		return x >= x_ && x < x_+width_ &&  y >= y_ && y < y_+height_;
	}
	inline bool contains(GPoint p) const {
		return contains(p.getX(),p.getY());
	}
	inline bool contains(int x, int y, int width, int height) const {
		return contains(x,y) && contains(x+width,y+height);
	}	
	inline bool contains(GRectangle r) const {
		return contains(r.x_,r.y_,r.width_,r.height_);
	}
	// method < contains >
	// - checks whether this GRectangle object contains specified location of GPoint object
	// - checks whether this GRectangle object contains specified bounds of another GRectangle object

	GRectangle& translate(int dx, int dy) {
		GPoint::translate(dx,dy);
		return *this;
	}
	// method < translate(int,int) >
	// - relocate start point of this GRectangle object and return itself
	
	inline bool intersects(const GRectangle r) const {	return contains(r.getLocation()) || r.contains(getLocation());	}
	// method < intersects(GRectangle) >
	// - return whether this GRectangle object and parameter GRectangle object intersect
		
	GRectangle* getIntersection(const GRectangle) const;
	// method < getIntersection(GRectangle)"
	// - return new GRectangle object representing the intersection of this GRectangle object with parameter GRectangle object
	// - return null pointer when there is no intersection between two GRectangle objects
	
	GRectangle* getUnion(const GRectangle) const;
	// method < getUnion(GRectangle) >
	// - return new GRectangle object which is the union of this GRectangle object with parameter GRectangle object

	virtual string toString() const override {	return GPoint::toString() + GDimension::toString();	}
	//	virtual method < toString() > : override

};

}
}

#endif
