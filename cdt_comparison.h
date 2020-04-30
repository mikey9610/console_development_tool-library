/*

	HEADER FILE : cdt_comparison
	
	static class < cmp > : compare two generic type object
	
*/

#ifndef CDT_COMPARISON_H
#define CDT_COMPARISON_H

namespace cdt {

class cmp {
private:

	cmp() {}
	// constructor (concealed)

public:
	
	template<typename T>
	inline static T smaller(const T& t1, const T& t2) {	return (t1<=t2) ? t1 : t2;	}
	// static method < smaller(T,T) >
	// - return smaller value
	
	template<typename T>
	inline static T bigger(const T& t1, const T& t2) {	return (t1>=t2) ? t1 : t2;	}
	// static method < bigger(T,T) >
	// - return bigger value
	
};
	
}

#endif
