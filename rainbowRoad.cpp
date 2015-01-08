#include "rainbowRoad.hpp"
#include <stdio.h>

RainbowRoad::RainbowRoad() {

	picture_1.delay = 25000;

	for(int i = 0; i < mainLength; i++) {

		for(int j = 0; j < 3; j++) {

			picture_1.m_face[i][j].r = 255;

		}

	}

	for(int i = 0; i < mainLength; i++) {

		for(int j = 3; j < 6; j++) {

			picture_1.m_face[i][j].r = 255;
			picture_1.m_face[i][j].g = 127;

		}

	}
	for(int i = 0; i < mainLength; i++) {

		for(int j = 6; j < 9; j++) {

			picture_1.m_face[i][j].r = 255;
			picture_1.m_face[i][j].g = 255;

		}

	}
	for(int i = 0; i < mainLength; i++) {

		for(int j = 9; j < 12; j++) {

			picture_1.m_face[i][j].g = 255;

		}

	}
	for(int i = 0; i < mainLength; i++) {

		for(int j = 12; j < 15; j++) {

			picture_1.m_face[i][j].b = 255;

		}

	}
	for(int i = 0; i < mainLength; i++) {

		for(int j = 15; j < mainHeight; j++) {

			picture_1.m_face[i][j].r = 143;
			picture_1.m_face[i][j].b = 255;

		}

	}

	for(int i = 0; i < sideLength; i++) {

		picture_1.m_side[i][0].r = 255;

	}

	for(int i = 0; i < sideLength; i++) {

		picture_1.m_side[i][1].r = 255;
		picture_1.m_side[i][1].g = 127;

	}
	for(int i = 0; i < sideLength; i++) {

		picture_1.m_side[i][2].r = 255;
		picture_1.m_side[i][2].g = 255;

	}
	for(int i = 0; i < sideLength; i++) {

		picture_1.m_side[i][3].g = 255;

	}
	for(int i = 0; i < sideLength; i++) {

		picture_1.m_side[i][4].b = 255;

	}
	for(int i = 0; i < sideLength; i++) {

		picture_1.m_side[i][5].r = 75;
		picture_1.m_side[i][5].b = 130;

	}
	for(int i = 0; i < sideLength; i++) {

		picture_1.m_side[i][6].r = 143;
		picture_1.m_side[i][6].b = 255;

	}

}

const Frame* RainbowRoad::getNextFrame() {

	pixel_t temp[4];

	temp[0] = picture_1.m_side[0][0];
	temp[1] = picture_1.m_side[1][0];
	temp[2] = picture_1.m_side[2][0];
	temp[3] = picture_1.m_side[3][0];

	for(int i = 0; i < sideHeight - 1; i++) {

		for(int j = 0; j < sideLength; j++) {

			picture_1.m_side[j][i] = picture_1.m_side[j][i + 1];

		}

	}

	for(int i = 0; i < sideLength; i++) {

		picture_1.m_side[i][sideHeight - 1] = temp[i];

	}

	shift(&picture_1,0,1);

	return &picture_1;

}
