#include "fullColor.hpp"
#include <stdio.h>
#include <cstdlib>
#include <ctime>

//Full face is a random colour, to be changed on key click
//For random at each franme, simply move RNG within getNextFrame

FullColor::FullColor() {

	red = std::rand() % 256;	//Generates number 0-255
	blue = std::rand() % 256;	//Note that 0 is twice as common
	green = std::rand() % 256;	//Should fix later..

	for(int i = 0; i < sideLength; i++) {
		
		picture_1.m_side[i][0].r = 255;	//Side Rainbows
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

	for(int i = 0; i < mainLength; i++) {
		for(int j = 0; j < mainHeight; j++) {

			picture_1.m_face[i][j].r = red;
			picture_1.m_face[i][j].g = green;
			picture_1.m_face[i][j].b = blue;

		}
	}

	picture_1.delay = 0;

}

const Frame* FullColor::getNextFrame() {

	return &picture_1;

}
