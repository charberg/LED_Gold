#include "colorSquare.hpp"
#include <stdio.h>
#include <cstdlib>
#include <ctime>

//Main face draws 2x2 square of  random colour

ColorSquare::ColorSquare() {

	std::srand(std::time(0));	//Seed the RNG

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

	picture_1.delay = 30000;

}

const Frame* ColorSquare::getNextFrame() {
	
	red = std::rand() % 256;	//Generates number 0-255
	blue = std::rand() % 256;	//Note that 0 is twice as common
	green = std::rand() % 256;	//Should fix later..

	int xCorner = red % (mainLength - 1);	//x co-ordinate of corner	
	int yCorner = blue % (mainHeight - 1);	//y co-ordinate of corner

	for(int i = xCorner; i < xCorner + 2; i++) {
		for(int j = yCorner; j < yCorner + 2; j++) {

			picture_1.m_face[i][j].r = red;
			picture_1.m_face[i][j].g = green;
			picture_1.m_face[i][j].b = blue;

		}
	}

	return &picture_1;

}
