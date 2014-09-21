#include "scanner.hpp"
#include <stdio.h>

Scanner::Scanner() {

	picture_1.delay = 50000;

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < mainLength; j++) {

			picture_1.m_face[j][i].r = 200;

		}
	}

}

const Frame* Scanner::getNextFrame() {

	if(picture_1.m_face[0][0].r != 0) {
		y = 1;
	}

	if(picture_1.m_face[0][mainHeight-1].r != 0) {
		y = -1;
	}

	shift(&picture_1, 0, y);
	return &picture_1;

}
