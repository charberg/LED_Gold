#include "pinwheel.hpp"
#include <stdio.h>

Pinwheel::Pinwheel() {

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < mainLength; j++) {

			picture_1.m_face[j][i].r = 200;

		}
	}


	for(int i = 3; i < 6; i++) {
		for(int j = 0; j < mainLength; j++) {

			picture_1.m_face[j][i].r = 200;
			picture_1.m_face[j][i].g = 200;
			picture_1.m_face[j][i].b = 200;

		}
	}

	for(int i = 6; i < 9; i++) {
		for(int j = 0; j < mainLength; j++) {

			picture_1.m_face[j][i].r = 200;

		}
	}


	for(int i = 9; i < 12; i++) {
		for(int j = 0; j < mainLength; j++) {

			picture_1.m_face[j][i].r = 200;
			picture_1.m_face[j][i].g = 200;
			picture_1.m_face[j][i].b = 200;

		}
	}

	for(int i = 12; i < 15; i++) {
		for(int j = 0; j < mainLength; j++) {

			picture_1.m_face[j][i].r = 200;

		}
	}

	for(int i = 15; i < mainHeight; i++) {
		for(int j = 0; j < mainLength; j++) {

			picture_1.m_face[j][i].r = 200;
			picture_1.m_face[j][i].g = 200;
			picture_1.m_face[j][i].b = 200;

		}
	}

	picture_1.delay = 40000;
}

const Frame* Pinwheel::getNextFrame() {

	shift(&picture_1,0,-1);
	return &picture_1;

}
