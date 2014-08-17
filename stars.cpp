#include "stars.hpp"
#include <stdio.h>
#include <cstdlib>
#include <ctime>

Stars::Stars() {

	picture_1.delay = 10;

}

const Frame* Stars::getNextFrame() {

	if(std::rand()%40 == 1) {	//If new star is born

		if((std::rand()%100) % 2 == 0 || std::rand()%100 % 3 == 0) {	//Draw new star to main

			int x = std::rand()%mainLength;
			int y = std::rand()%mainHeight;

			while(picture_1.m_face[x][y].r != 0) {

			x = std::rand()%mainLength;	//Keep changing until unoccupied pixel
			y = std::rand()%mainHeight;

			}			

			picture_1.m_face[x][y].r = 2;
			picture_1.m_face[x][y].g = 2;
			picture_1.m_face[x][y].b = 2;

		}

		else {

			int x = std::rand()%sideLength;
			int y = std::rand()%sideHeight;

			while(picture_1.m_face[x][y].r != 0) {

			x = std::rand()%sideLength;	//Keep changing until unoccupied pixel
			y = std::rand()%sideHeight;

			}			

			picture_1.m_side[x][y].r = 2;
			picture_1.m_side[x][y].g = 2;
			picture_1.m_side[x][y].b = 2;

		}

	}	//End of new star creation	

	for(int i = 0; i < mainLength; i++) {
		for(int j = 0; j < mainHeight; j++) {

			if(picture_1.m_face[i][j].r%2 == 0 && picture_1.m_face[i][j].r != 0) {

				picture_1.m_face[i][j].r++;
				picture_1.m_face[i][j].r++;
				picture_1.m_face[i][j].g++;
				picture_1.m_face[i][j].g++;
				picture_1.m_face[i][j].b++;
				picture_1.m_face[i][j].b++;
			}
	
			if(picture_1.m_face[i][j].r%2 == 1 && picture_1.m_face[i][j].r != 1) {	//Odd on way down
				picture_1.m_face[i][j].r--;
				picture_1.m_face[i][j].r--;
				picture_1.m_face[i][j].g--;
				picture_1.m_face[i][j].g--;
				picture_1.m_face[i][j].b--;
				picture_1.m_face[i][j].b--;
			}

			if(picture_1.m_face[i][j].r == 240) {
				//Set to odd, flag for way down
				picture_1.m_face[i][j].r--;
				picture_1.m_face[i][j].g--;
				picture_1.m_face[i][j].b--;
			}

			if(picture_1.m_face[i][j].r == 1) {
				//Turn off star
				picture_1.m_face[i][j].r--;
				picture_1.m_face[i][j].g--;
				picture_1.m_face[i][j].b--;
			}
		}
	}

	for(int i = 0; i < sideLength; i++) {
		for(int j = 0; j < sideHeight; j++) {

			if(picture_1.m_side[i][j].r%2 == 0 && picture_1.m_side[i][j].r != 0) {

				picture_1.m_side[i][j].r++;
				picture_1.m_side[i][j].r++;
				picture_1.m_side[i][j].g++;
				picture_1.m_side[i][j].g++;
				picture_1.m_side[i][j].b++;
				picture_1.m_side[i][j].b++;
			}
	
			if(picture_1.m_side[i][j].r%2 == 1 && picture_1.m_side[i][j].r != 1) {	//Odd on way down
				picture_1.m_side[i][j].r--;
				picture_1.m_side[i][j].r--;
				picture_1.m_side[i][j].g--;
				picture_1.m_side[i][j].g--;
				picture_1.m_side[i][j].b--;
				picture_1.m_side[i][j].b--;
			}

			if(picture_1.m_side[i][j].r == 240) {
				//Set to odd, flag for way down
				picture_1.m_side[i][j].r--;
				picture_1.m_side[i][j].g--;
				picture_1.m_side[i][j].b--;
			}

			if(picture_1.m_side[i][j].r == 1) {
				//Turn off star
				picture_1.m_side[i][j].r--;
				picture_1.m_side[i][j].g--;
				picture_1.m_side[i][j].b--;
			}
		}
	}

	return &picture_1;

}
