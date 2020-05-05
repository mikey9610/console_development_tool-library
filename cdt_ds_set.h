/*

	HEADER FILE : cdt_ds_set
		
*/

#ifndef CDT_DS_SET_H
#define CDT_DS_SET_H

#include <vector>
using namespace std;

namespace cdt {
namespace data_structure {

template <typename T>
class CDT_Set {
protected:
	
	vector<T> value_;
	
public:
	
	void insert(T);
	
	void remove(T);
	
	bool isMember(const T) const;
	
	bool isSubset(const CDT_Set&) const;
	inline bool operator>(const CDT_Set& opr) const {	return isSubset(opr);	}
	inline bool operator<(const CDT_Set& opr) const {	return opr.isSubset(*this);	}
	
	bool isEqual(const CDT_Set&) const;
	inline bool operator==(const CDT_Set& opr) const {	return isEqual(opr);	}
	
	CDT_Set union_s(const CDT_Set&) const;
	inline CDT_Set operator+(const CDT_Set& opr) const {	return union_s(opr);	}
	inline CDT_Set operator|(const CDT_Set& opr) const {	return union_s(opr);	}
	
	CDT_Set intersection_s(const CDT_Set&) const;
	inline CDT_Set operator&(const CDT_Set& opr) const {	return intersection_s(opr);	}
	
	CDT_Set difference_s(const CDT_Set&) const;
	inline CDT_Set operator-(const CDT_Set& opr) const {	return difference_s(opr);	}
	
	inline typename vector<T>::iterator begin() {	return value_.begin();	}
	inline typename vector<T>::iterator begin() const {	return value_.begin();	}
	
	inline typename vector<T>::iterator end() {	return value_.end();	}
	inline typename vector<T>::iterator end() const {	return value_.end();	}
	
};	
	
}	
}

#endif
