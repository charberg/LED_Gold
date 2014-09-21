#include "smiley.hpp"
#include <stdio.h>

const Frame* Smiley::getNextFrame() {

	for(int i = 0; i < mainLength; i++) {
	
		for(int j = 0; j < mainHeight; j++) {

			picture_1.m_face[i][j].r = 255;
			picture_1.m_face[i][j].g = 255;
			
		}

	}

	picture_1.m_face[1][9].r = 50;
	picture_1.m_face[1][10].r = 50;
	picture_1.m_face[1][11].r = 50;
	picture_1.m_face[1][9].g = 0;
	picture_1.m_face[1][10].g = 0;
	picture_1.m_face[1][11].g = 0;
	
	picture_1.m_face[4][9].r = 50;
	picture_1.m_face[4][10].r = 50;
	picture_1.m_face[4][11].r = 50;
	picture_1.m_face[4][9].g = 0;
	picture_1.m_face[4][10].g = 0;
	picture_1.m_face[4][11].g = 0;
		
	picture_1.m_face[0][4].r = 50;
	picture_1.m_face[1][3].r = 50;
	picture_1.m_face[2][2].r = 50;
	picture_1.m_face[3][2].r = 50;
	picture_1.m_face[4][3].r = 50;
	picture_1.m_face[5][4].r = 50;
	picture_1.m_face[0][4].g = 0;
	picture_1.m_face[1][3].g = 0;
	picture_1.m_face[2][2].g = 0;
	picture_1.m_face[3][2].g = 0;
	picture_1.m_face[4][3].g = 0;
	picture_1.m_face[5][4].g = 0;

	for(int i = 0; i < sideLength; i++) {

		picture_1.m_side[i][0].r = 255;
		picture_1.m_side[i][1].r = 255;
		picture_1.m_side[i][1].g = 127;
		picture_1.m_side[i][2].r = 255;
		picture_1.m_side[i][2].g = 255;
		picture_1.m_side[i][3].g = 255;
		picture_1.m_side[i][4].b = 255;
		picture_1.m_side[i][5].r = 75;
		picture_1.m_side[i][5].b = 130;
		picture_1.m_side[i][6].r = 143;
		picture_1.m_side[i][6].b = 255;
	}

	picture_1.delay = 0;

	return &picture_1;
	
}	
