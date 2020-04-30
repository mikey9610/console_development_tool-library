/*

	CPP FILE : cdt_cursor
	
*/

#include <stdexcept>
#include "cdt_cursor.h"
using namespace cdt;

Cursor* Cursor::useCursor() {
	if(instance_ == nullptr)
		instance_ = new Cursor();
	return instance_;
}

void Cursor::setPos(int x, int y) {
	if(x<0) throw std::out_of_range("error : x must not be negative");
	if(y<0) throw std::out_of_range("error : y must not be negative");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),COORD{x,y});
}

void Cursor::setVisible(bool visible) {
	info_->bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),info_);
}

void Cursor::setSize(DWORD size) {
	info_->dwSize = size;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),info_);
}

void Cursor::setForeground(Color foreground) {
	foreground_ = foreground;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),background_<<4|foreground_);	
}

void Cursor::setBackground(Color background) {
	background_ = background;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),background_<<4|foreground_);	
}

void Cursor::setColor(Color foreground, Color background) {
	foreground_ = foreground;
	background_ = background;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),background_<<4|foreground_);	
}

Cursor* Cursor::instance_ = nullptr;
