#include "fullColor.hpp"
#include <stdio.h>
#include <cstdlib>
#include <ctime>

//Full face is a random colour, to be changed on key click
//For random at each franme, simply move RNG within getNextFrame

FullColor::FullColor() {

	std::srand(std::time(0));	//Seed the RNG

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

	picture_1.delay = 10000;

}

const Frame* FullColor::getNextFrame() {

	for(int i = 0; i < mainLength; i++) {
		for(int j = 0; j < mainHeight; j++) {

			picture_1.m_face[i][j].r = red;
			picture_1.m_face[i][j].g = green;
			picture_1.m_face[i][j].b = blue;

		}
	}

	return &picture_1;

}
