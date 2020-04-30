#include <stdexcept>
#include "cdt_renderer.h"
using namespace cdt;

Renderer* Renderer::useRenderer() {
	if(instance_ == nullptr)
		instance_ = new Renderer();
	return instance_;
}

void Renderer::setPos(int x, int y) {
	if(x<0) throw std::out_of_range("error : x must not be negative");
	if(y<0) throw std::out_of_range("error : y must not be negative");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),COORD{x,y});
}

void Renderer::setVisible(bool visible) {
	info_->bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),info_);
}

void Renderer::setSize(DWORD size) {
	info_->dwSize = size;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),info_);
}

void Renderer::setForeground(Color foreground) {
	foreground_ = foreground;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),background_<<4|foreground_);	
}

void Renderer::setBackground(Color background) {
	background_ = background;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),background_<<4|foreground_);	
}

void Renderer::setColor(Color foreground, Color background) {
	foreground_ = foreground;
	background_ = background;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),background_<<4|foreground_);	
}

Renderer* Renderer::instance_ = nullptr;
