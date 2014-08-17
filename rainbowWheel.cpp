#include "rainbowWheel.hpp"
#include <stdio.h>

RainbowWheel::RainbowWheel() {

	for(int i = 0; i < sideHeight; i++) {

		wings[i] = 0;	//Set all side lights to off

	}

	direction = 1;	//Load
	directionChange = 0;

	picture_1.delay = 50000;

}

const Frame* RainbowWheel::getNextFrame() {
	
	if(directionChange == 1) {

		direction = direction*(-1);	//Flip direction sign
		directionChange = 0;

	}

	if(direction == 1) {	//Rainbow "Load"
		
		bool wedgeShift = 0;

		for(int i = sideHeight - 1; i > 0; i--) {

			if(wings[i] == 1 && wings[i-1] == 0) {
				//If room to shift a wedge
				wings[i] = 0;
				wings[i-1] = 1;
				wedgeShift = 1;
				break;
			}
		}

		if (wedgeShift == 0) {	//If no shift, then new wedge
				
			wings[sideHeight - 1] = 1;
			
			if(wings[6] == 1 && wings[5] == 1) {
				//If full, then start unloading next pass
				directionChange = 1;

			}

		}


	}


	if(direction == -1) {	//Rainbow "Unload"


		if (wings[sideHeight - 1] == 1) {	

			wings[sideHeight - 1] = 0;

			//If no shift, but top wedge is lit, remove	
			
			if(wings[0] == 0) {
				//If no more wedges to remove, then load next pass
				directionChange = 1;

			}

		}

		else {

			for(int i = sideHeight - 1; i > 0; i--) {

				if(wings[i] == 0 && wings[i-1] == 1) {
				
					//If room to shift a wedge
					wings[i] = 1;
					wings[i-1] = 0;
					break;
				}
			}
		}

	}

	if(wings[0] == 1) {

		for(int i = 0; i < sideLength; i++) {
			picture_1.m_side[i][0].r = 255;
		}

	}


	if(wings[1] == 1) {

		for(int i = 0; i < sideLength; i++) {
			picture_1.m_side[i][1].r = 255;
			picture_1.m_side[i][1].g = 127;
		}

	}
	if(wings[2] == 1) {

		for(int i = 0; i < sideLength; i++) {
			picture_1.m_side[i][2].r = 255;
			picture_1.m_side[i][2].g = 255;
		}

	}
	if(wings[3] == 1) {

		for(int i = 0; i < sideLength; i++) {
			picture_1.m_side[i][3].g = 255;
		}

	}
	if(wings[4] == 1) {

		for(int i = 0; i < sideLength; i++) {
			picture_1.m_side[i][4].b = 255;
		}

	}
	if(wings[5] == 1) {

		for(int i = 0; i < sideLength; i++) {
			picture_1.m_side[i][5].r = 75;
			picture_1.m_side[i][5].b = 130;
		}

	}
	if(wings[6] == 1) {

		for(int i = 0; i < sideLength; i++) {
			picture_1.m_side[i][6].r = 143;
			picture_1.m_side[i][6].b = 255;
		}

	}

	for(int i = 0; i < sideHeight; i++) {	//Check for lines to be turned off

		if(wings[i] == 0) {

			for(int j = 0; j < sideLength; j++) {

	
				picture_1.m_side[j][i].r = 0;
				picture_1.m_side[j][i].g = 0;
				picture_1.m_side[j][i].b = 0;

			}

		}

	}

	return &picture_1;
	
}	
