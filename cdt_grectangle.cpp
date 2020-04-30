#include "cdt_grectangle.h"
#include "cdt_comparison.h"
using namespace cdt::graphic;

GRectangle* GRectangle::getIntersection(const GRectangle& r) const {
	if(intersects(r)) {
		int startX = cmp::bigger(x_,r.x_);
		int startY = cmp::bigger(y_,r.y_);
		int endX = cmp::smaller(x_+width_,r.x_+r.width_);
		int endY = cmp::smaller(y_+height_,r.y_+r.height_);
		return new GRectangle(startX,startY,endX-startX,endY-startY);	
	}
	else return nullptr;
}
	
GRectangle* GRectangle::getUnion(const GRectangle& r) const {
	int startX = cmp::smaller(x_,r.x_);
	int startY = cmp::smaller(y_,r.y_);
	int endX = cmp::bigger(x_+width_,r.x_+r.width_);
	int endY = cmp::bigger(y_+height_,r.y_+r.height_);	
	return new GRectangle(startX,startY,endX-startX,endY-startY);		
}
