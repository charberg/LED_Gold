#include "smiley.hpp"
#include <stdio.h>


const Frame* Smiley::getNextFrame() {

	for(int i = 0; i < mainLength; i++) {
	
		for(int j = 0; j < mainHeight; j++) {

			picture_1.m_face[i][j].r = 255;
			picture_1.m_face[i][j].g = 255;
			
		}

	}

	picture_1.m_face[1][9].r = 0;
	picture_1.m_face[1][10].r = 0;
	picture_1.m_face[1][11].r = 0;
	picture_1.m_face[1][9].g = 0;
	picture_1.m_face[1][10].g = 0;
	picture_1.m_face[1][11].g = 0;
	
	picture_1.m_face[4][9].r = 0;
	picture_1.m_face[4][10].r = 0;
	picture_1.m_face[4][11].r = 0;
	picture_1.m_face[4][9].g = 0;
	picture_1.m_face[4][10].g = 0;
	picture_1.m_face[4][11].g = 0;
		
	picture_1.m_face[0][4].r = 0;
	picture_1.m_face[1][3].r = 0;
	picture_1.m_face[2][2].r = 0;
	picture_1.m_face[3][2].r = 0;
	picture_1.m_face[4][3].r = 0;
	picture_1.m_face[5][4].r = 0;
	picture_1.m_face[0][4].g = 0;
	picture_1.m_face[1][3].g = 0;
	picture_1.m_face[2][2].g = 0;
	picture_1.m_face[3][2].g = 0;
	picture_1.m_face[4][3].g = 0;
	picture_1.m_face[5][4].g = 0;

	for(int i = 0; i < sideLength; i++) {

		for(int j = 0; j < sideHeight; j++) {

			picture_2.m_side[i][j].r = 30;
			picture_2.m_side[i][j].g = 76;
			picture_2.m_side[i][j].b = 58;
		}

	}

	frameCount++;

	if(frameCount%2 == 0) {
		return &picture_1;
	}

	else {
		
		return &picture_2;

	}

	return NULL;	

	
}	
