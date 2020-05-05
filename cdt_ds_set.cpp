#include "cdt_ds_set.h"
using namespace cdt::data_structure;

template <typename T>
void CDT_Set<T>::insert(T value) {
	if(!isMember(value))	value_.push_back(value);
}

template <typename T>
void CDT_Set<T>::remove(T value) {
	for(auto iter=value_.begin();iter!=value_.end();iter++) {
		if(*iter == value) {
			value_.erase(iter);
			return;
		}
	}
}

template <typename T>
bool CDT_Set<T>::isMember(const T value) const {
	for(const auto v : value_)
		if(v == value)
			return true;
	return false;
}

template <typename T>
bool CDT_Set<T>::isSubset(const CDT_Set& opr) const {
	for(const auto& v : opr)
		if(!isMemer(v))
			return false;
	return true;
}

template <typename T>
bool CDT_Set<T>::isEqual(const CDT_Set& opr) const {
	return isSubset(opr) && opr.isSubset(*this);
}

template <typename T>
CDT_Set<T> CDT_Set<T>::union_s(const CDT_Set& opr) const {
	CDT_Set<T> union_set(opr);
	for(const auto& v : value_)
		union_set.insert(v);
	return union_set;
}

template <typename T>
CDT_Set<T> CDT_Set<T>::intersection_s(const CDT_Set& opr) const {
	CDT_Set<T> intersection_set;
	for(const auto& v : value_)
		if(opr.isMember(v))
			intersection_set.insert(v);	
	return intersection_set;
}

template <typename T>
CDT_Set<T> CDT_Set<T>::difference_s(const CDT_Set& opr) const {
	CDT_Set<T> difference_set;
	for(const auto& v : value_)
		if(!opr.isMember(v))
			difference_set.insert(v);	
	return difference_set;
}
