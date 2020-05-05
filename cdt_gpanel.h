/*

	HEADER FILE : cdt_gpanel
	
	class < GPanel > : graphic class that includes other graphic objects
	
*/

#ifndef CDT_GPANEL_H
#define CDT_GPANEL_H

#include "cdt_gcontainer.h"

namespace cdt {
namespace graphic {
	
class GPanel : public GContainer_i {	
protected:
	
	

public:
	
	GPanel(string name="panel")
	 :	Object_i(321),
	 	GContainer_i(name) {}
	// constructor
		
};

}
}

#endif
