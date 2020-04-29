/*

	HEADER FILE : cdt_gdimension
	
	class < GDimension > : dimension that has width and height
	
*/

#ifndef CDT_GDIMENSION_H
#define CDT_GDIMENSION_H

#include <stdexcept>
#include "cdt_object_i.h"

namespace cdt {
namespace graphic {

class GDimension : virtual public Object_i {
protected:
	
	int width_;
	int height_;
	// field ( width , height ) : width , height
		
	virtual bool equalsInner(const Object_i* obj) const override {
		auto objDimension = dynamic_cast<const GPoint*>(obj);
		return width_ == objDimension->width_ && height_ == objDimension->height_;
	}
	// virtual method < equalsInner(cosnt Object_i*) > : override
	
public:
	
	GDimension()
	 : Object_i(302), width_(0), height_(0) {}	 
	GDimension(int width, int height)
	 : Object_i(302), width_(width), height_(height) {}
	// constructor - 2
	
	inline int getWidth() const {	return this->width_;	}
	inline int getHeight() const {	return this->height_;	}
	inline GDimension getSize() const {	return *this;	}
	// method < get >	
	
	inline void setWidth(int width) {	(width<0) ? throw out_of_range("error : width must not be negative") : this->width_ = width;	}
	inline void setHeight(int height) {	(height<0) ? throw out_of_range("error : height must not be negative") : this->height_ = height;	}
	inline void setSize(int width, int height) {
		setWidth(width);
		setHeight(height);
	}
	inline void setSize(GDimension d) {
		setWidth(d.width_);
		setHeight(d.height_);
	}
	inline void setSize(GDimension* d) {
		setX(d->width_);
		setY(d->height_);
	}
	// method < set >
	// - constraint : width>=0 & height>=0
	
	virtual string toString() const override {	return "w"+to_string(width_)+"/"+"h"+to_string(height_);	}
	//	virtual method < toString() > : override
	
};	
	
}	
}

#endif
