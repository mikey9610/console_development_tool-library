/*

	HEADER FILE : cdt_color
	
	enum < color >
		
*/

#ifndef CDT_COLOR_H
#define CDT_COLOR_H

namespace cdt {

enum Color {
	C_BLACK			= 0,
	C_BLUE			= 1,
	C_GREEN			= 2,
	C_CYAN			= 3,
	C_RED			= 4,
	C_MAGENTA		= 5,
	C_BROWN			= 6,
	C_WHITE			= 7,
	C_BRIGHT		= 8,
	C_GRAY			= 8,
	C_BRIGHT_BLACK	= 8,
	C_BRIGHT_BLUE	= 9,
	C_BRIGHT_GREEN	= 10,
	C_BRIGHT_CYAN	= 11,
	C_BRIGHT_RED	= 12,
	C_BRIGHT_MAGENTA= 13,
	C_BRIGHT_BROWN	= 14,
	C_YELLOW		= 14,
	C_BRIGHT_WHITE	= 15
};

inline Color mix(const Color c1, const Color c2) {	return (Color)(c1|c2);	}
//	method < mix(Color,Color) >
//	- mix two Color values into one

inline Color brighten(const Color c) {	return (Color)(c|C_BRIGHT);	}
//	method < brighten(Color) >
//	- brighten Color value

inline Color darken(const Color c) {	return (Color)(c&~C_BRIGHT);	}
//	method < darken(Color) >
//	- darken Color value

}

#endif
