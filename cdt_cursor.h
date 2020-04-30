/*

	HEADER FILE : cdt_cursor
	
	class < Cursor > : singletone class that renders console screen
	
*/

#ifndef CDT_RENDERER_H
#define CDT_RENDERER_H

#include <iostream>
#include <Windows.h>
#include "cdt_color.h"

namespace cdt {

typedef COORD CurPos;
typedef CONSOLE_CURSOR_INFO CurInfo;
// type define

class Cursor {
protected:
	
	CONSOLE_CURSOR_INFO* info_;
	// field ( width , height ) : width , height
		
	Color foreground_;
	Color background_;
	// field < foreground , background > : foreground and background Color 
	
	static Cursor* instance_;
	// singletone pointer
	
	Cursor()
	 :	info_(new CurInfo{true,10}),
	 	foreground_(C_BRIGHT_WHITE),
	 	background_(C_BLACK) {}
	// constructor (concealed)
	
public:
	
	static Cursor* useCursor();
	// static method < useCursor() >
	// - get singletone instance
	
	void setPos(int,int);
	inline void setPos(COORD pos) {	setPos(pos.X,pos.Y);	}
	// method < setPos >
	// - move cursor position into specified location
	
	void setVisible(bool);
	// method < setVis(bool) >
	// - set whether cursor is visible and apply
	
	void setSize(DWORD);
	// method < setSize(DWORD) >
	// - set cursor size and apply
	
	void setForeground(Color);
	void setBackground(Color);
	void setColor(Color,Color);
	// method < setColor >
	// - set foreground and background color and apply
	
};

static Cursor& renderer = *Cursor::useCursor();

}

#endif
