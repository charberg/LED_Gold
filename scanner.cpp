#include "scanner.hpp"
#include <stdio.h>

Scanner::Scanner() {

	picture_1.m_face[3][3].b = 200;
	picture_1.delay = 50000;

}

const Frame* Scanner::getNextFrame() {

	shift(&picture_1, 1, 1);
	return &picture_1;

}
