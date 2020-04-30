#include "cdt_gcomponent_i.h"
using namespace cdt::graphic;
/*
GRectangle& GComponent_i::getBounds(GRectangle& rv) const {
	rv.setBounds(GRectangle::getBounds());
	return rv;
}*/

GRectangle* GComponent_i::getAbsBounds() const {
	return (parent_ == nullptr) ?
		new GRectangle(GRectangle::getBounds()) :
		parent_->getIntersection(GRectangle::getBounds().translate(parent_->getX(),parent_->getY()));
}
/*
void GComponent_i::notify(GEvent* event) {
	if(!enabled_)
		return;
	if(mouseListener_!=nullptr) {
		mouseListener_->notify(event);
	}
}*/
