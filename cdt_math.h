/*

	HEADER FILE : cdt_math
	
	static class < math >
	
*/

#ifndef CDT_MATH_H
#define CDT_MATH_H

namespace cdt {

class math {
private:

	math() {}
	// constructor (concealed)

public:
	
	inline static int div_in_row(int total, int denom) {	return (total%denom==0) ? total/denom : total/denom+1;	}
	// static method < div_in_row(int,int) >
	// - return rows which has denom
	
};
	
}

#endif
