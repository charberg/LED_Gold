#include "upvote.hpp"
#include <stdio.h>

Upvote::Upvote() {

	picture_1.delay = 25000;

	for(int i = 1; i < 7; i++) {
		for(int j = 2; j < 4; j++) {
			
			picture_1.m_face[j][i].g = 200;

		}
	}

	for(int i = 0; i < 7; i++) {

		picture_1.m_face[1][i].r = 200;
		picture_1.m_face[4][i].r = 200;

	}

	picture_1.m_face[2][0].r = 200;
	picture_1.m_face[3][0].r = 200;

	for(int i = 1; i < 5; i++) {
		picture_1.m_face[i][7].g = 200;
		picture_1.m_face[i][8].g = 200;
	}	

	picture_1.m_face[0][7].r = 200;
	picture_1.m_face[5][7].r = 200;
	picture_1.m_face[0][8].r = 200;
	picture_1.m_face[5][8].r = 200;

	picture_1.m_face[1][9].r = 200;
	picture_1.m_face[4][9].r = 200;

	picture_1.m_face[2][9].g = 200;
	picture_1.m_face[3][9].g = 200;


	picture_1.m_face[2][10].r = 200;
	picture_1.m_face[3][10].r = 200;



}

const Frame* Upvote::getNextFrame() {

	shift(&picture_1, 0, 1);
	return &picture_1;

}
