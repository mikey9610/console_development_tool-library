#include "cdt_gcontainer.h"
using namespace cdt::graphic;

GComponent_i* GContainer_i::getComponentAt(GPoint p) const {
	for(auto& c : components_) {
		if(c->getAbsBounds()->contains(p))
			return c;
	}
	return (GComponent_i*)this;
}

GComponent_i* GContainer_i::add(GComponent_i* comp) {
	this->components_.push_back(comp);
	comp->setParent(getAbsBounds());
	return comp;
}

GComponent_i* GContainer_i::add(GComponent_i* comp, int index) {
	if(index > components_.size() || index < 1)
		return add(comp);
	
	components_.push_back(nullptr);
	for(int i=components_.size();i>index-1;i--) {
		components_[i] = components_[i-1];
	}
	components_[index-1] = comp;
	comp->setParent(getAbsBounds());
	return comp;
}
