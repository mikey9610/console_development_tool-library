/*

	HEADER FILE : cdt_object_i
	
	interface < Object_i > : histest super clas of all derived classes in cdt project 
	 
*/

#ifndef CDT_OBJECT_I_H
#define CDT_OBJECT_I_H

#include <iostream>
using namespace std;

namespace cdt {

class Object_i {
protected:
	
	int hashCode_;
	// field ( hashcode ) : integer value which indicates class type
	
	virtual bool equalsInner(const Object_i* obj) const {	return this == obj;	}
	// virtual method < equalsInner(const Object_i*) > : return whether this object is same with parameter object
	
	Object_i(int hc=0)
	 : hashCode_(hc) {}
	// constructor (concealed)
	
public:
	
	inline int getHashCode() const {	return this->hashCode_;	}
	// method < hashCode() >
	// - return hashcode of this class type
	
	inline bool equals(const Object_i* obj) const {	return (this->hashCode_ == obj->getHashCode()) ? equalsInner(obj) : false;	}
	// virtual method < equals(const Object_i*) >
	// - return whether this object is same with parameter one
		
	virtual string toString() const {	return to_string(hashCode_);	}
	// virtual method < toString() >
	// - return string which represent this object
	
};

}

#endif
