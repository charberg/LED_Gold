#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>

extern "C" {
#include "ledscape.h"
}

#include "bonelib/nunchuck.hpp"

using namespace BeagleBone;
//
//Two 2-d arrays, one visual, one actual, based on LEN/WID parameters FIND TYPE

//LED struct


	int width = 23;
	int height = 4;
	int width_a = 46;
	int height_a = 2;

typedef struct light {
	int r = 0;
	int g = 0;
	int b = 0;
	float brite = 1;	//Multiplier for brightness
	int ch = NULL;	//Default, each pixel ch must be intialized individually
}LIGHT;

void light_init(LIGHT** visual) {

	for(int i = 0; i < 23; i++) {

		visual[i][0].ch = 19;
		visual[i][1].ch = 19;

	}

	for(int i = 0; i < 23; i++) {

		visual[i][2].ch = 12;
		visual[i][3].ch = 12;

	}

}

void visToAct(LIGHT** actual, LIGHT** visual) {
	
	for(int i = 0; i < 2; i++) {	//Bottom/"Right" Half
		for(int j = 0; j < 23; j++) {
			
			if(i%2==0) {	//If even visual row

				actual[45 - j][0] = visual[j][i];
			}

			else {
				actual[j][0] = visual[j][i];
			}
		}
	}
	for(int i = 2; i < 4; i++) {	//Top/"Left Side"
		for(int j = 0; j < 23; j++) {

			if(i%2 == 0) {	//If even row

				actual[j][1] = visual[j][i];

			}

			else {

				actual[45-j][1] = visual[j][i];

			}
		}
	}	
}

void helm_draw(LIGHT** actual, LIGHT** visual, ledscape_t * const leds, ledscape_frame_t *frame[],int use_frame) {

	for(int i = 0; i < 46; i++) {
	
		ledscape_set_color(frame[use_frame],19,i,actual[i][0].r,actual[i][0].g,actual[i][0].b);
		ledscape_set_color(frame[use_frame],12,i,actual[i][1].r,actual[i][1].g,actual[i][1].b);
	
	}
		(void) ledscape_wait(leds);
		ledscape_draw(leds, use_frame);
		use_frame = (use_frame + 1)%2;
		usleep(20000);		
}


/////////////////////////ANIMATION FUNCTIONS///////////////////////////
//

void test(LIGHT** visual) {
	//rhok text
	if(visual[0][0].b == 0 && visual[0][0].r == 0 && visual[0][0].g == 0) {
		visual[0][0].b = 30;
	}
	if(visual[0][0].r !=0) {
		visual[0][0].b = 30;
		visual[0][1].b = 30;
		visual[1][2].b = 30;
		visual[2][2].b = 30;
		visual[4][0].b = 30;
		visual[4][1].b = 30;
		visual[4][2].b = 30;
		visual[5][1].b = 30;
		visual[6][1].b = 30;
		visual[6][0].b = 30;
		visual[8][1].b = 30;
		visual[9][0].b = 30;
		visual[9][2].b = 30;
		visual[10][1].b = 30;
		visual[12][0].b = 30;
		visual[12][1].b = 30;
		visual[12][2].b = 30;
		visual[13][1].b = 30;
		visual[14][0].b = 30;
		visual[14][2].b = 30;
		visual[0][0].r = 0;
		visual[0][1].r = 0;
		visual[1][2].r = 0;
		visual[2][2].r = 0;
		visual[4][0].r = 0;
		visual[4][1].r = 0;
		visual[4][2].r = 0;
		visual[5][1].r = 0;
		visual[6][1].r = 0;
		visual[6][0].r = 0;
		visual[8][1].r = 0;
		visual[9][0].r = 0;
		visual[9][2].r = 0;
		visual[10][1].r = 0;
		visual[12][0].r = 0;
		visual[12][1].r = 0;
		visual[12][2].r = 0;
		visual[13][1].r = 0;
		visual[14][0].r = 0;
		visual[14][2].r = 0;
		usleep(80000);
		return;
	}

	if(visual[0][0].b !=0) {
		visual[0][0].g = 30;
		visual[0][1].g = 30;
		visual[1][2].g = 30;
		visual[2][2].g = 30;
		visual[4][0].g = 30;
		visual[4][1].g = 30;
		visual[4][2].g = 30;
		visual[5][1].g = 30;
		visual[6][1].g = 30;
		visual[6][0].g = 30;
		visual[8][1].g = 30;
		visual[9][0].g = 30;
		visual[9][2].g = 30;
		visual[10][1].g = 30;
		visual[12][0].g = 30;
		visual[12][1].g = 30;
		visual[12][2].g = 30;
		visual[13][1].g = 30;
		visual[14][0].g = 30;
		visual[14][2].g = 30;
		visual[0][0].b = 0;
		visual[0][1].b = 0;
		visual[1][2].b = 0;
		visual[2][2].b = 0;
		visual[4][0].b = 0;
		visual[4][1].b = 0;
		visual[4][2].b = 0;
		visual[5][1].b = 0;
		visual[6][1].b = 0;
		visual[6][0].b = 0;
		visual[8][1].b = 0;
		visual[9][0].b = 0;
		visual[9][2].b = 0;
		visual[10][1].b = 0;
		visual[12][0].b = 0;
		visual[12][1].b = 0;
		visual[12][2].b = 0;
		visual[13][1].b = 0;
		visual[14][0].b = 0;
		visual[14][2].b = 0;
		usleep(80000);
		return;

	}
	if(visual[0][0].g !=0) {
		visual[0][0].r = 30;
		visual[0][1].r = 30;
		visual[1][2].r = 30;
		visual[2][2].r = 30;
		visual[4][0].r = 30;
		visual[4][1].r = 30;
		visual[4][2].r = 30;
		visual[5][1].r = 30;
		visual[6][1].r = 30;
		visual[6][0].r = 30;
		visual[8][1].r = 30;
		visual[9][0].r = 30;
		visual[9][2].r = 30;
		visual[10][1].r = 30;
		visual[12][0].r = 30;
		visual[12][1].r = 30;
		visual[12][2].r = 30;
		visual[13][1].r = 30;
		visual[14][0].r = 30;
		visual[14][2].r = 30;
		visual[0][0].g = 0;
		visual[0][1].g = 0;
		visual[1][2].g = 0;
		visual[2][2].g = 0;
		visual[4][0].g = 0;
		visual[4][1].g = 0;
		visual[4][2].g = 0;
		visual[5][1].g = 0;
		visual[6][1].g = 0;
		visual[6][0].g = 0;
		visual[8][1].g = 0;
		visual[9][0].g = 0;
		visual[9][2].g = 0;
		visual[10][1].g = 0;
		visual[12][0].g = 0;
		visual[12][1].g = 0;
		visual[12][2].g = 0;
		visual[13][1].g = 0;
		visual[14][0].g = 0;
		visual[14][2].g = 0;
		usleep(80000);
		return;
	}

}

void draw(LIGHT** actual, LIGHT** visual, ledscape_t * const leds, ledscape_frame_t *frame[], int use_frame) {

	test(visual);
	visToAct(actual,visual);
	helm_draw(actual, visual, leds, frame, use_frame);

}



int main (void){	

	const unsigned num_pixels = 46;
	ledscape_t * const leds = ledscape_init(num_pixels);

	unsigned char C_or_Z = 0;
	float brightness = 0.2;

        ledscape_frame_t *frame[2];
	frame[0] = ledscape_frame(leds, 0);
	frame[1] = ledscape_frame(leds, 1);	//Leave above alone, set up

	uint8_t rgb[3];
	rgb[0] = 255;
	rgb[1] = 255;
	rgb[2] = 255;

	unsigned use_frame = 0;
	unsigned ball = num_pixels/2;
	unsigned speed = 1;
	
	LIGHT** actual = new LIGHT*[46];
	for(int i = 0; i < 46; i++) {
		actual[i] = new LIGHT[2];
	}
	LIGHT** visual = new LIGHT*[23];
	for(int i = 0; i < 23; i++) {
		visual[i] = new LIGHT[4];
	}
	light_init(visual);
			
	while (1)
	{
		draw(actual, visual, leds, frame, use_frame);
		
		// Read the Nunchuck
		nunchuck::sample();

		// Stop if both buttons are pressed
		if (nunchuck::Z() && nunchuck::C()) break;
		/*
                // Move the ball
		signed short daX = nunchuck::daX();
		// Horizontal position is at 25
		daX -= 25;

		if      (daX < -25) {
		        ball++;
		        if (ball >= num_pixels) ball = 0;
		}
		else if (daX >  25) {
			if (ball == 0) ball = num_pixels;
			ball--;
		}

		daX = abs(daX);
		if      (daX >  126) speed = 3;
		else if (daX >   75) speed = 2;
                else                 speed = 1;

		// Set the color of the ball
		float dX = ((float) nunchuck::dX()) / 100.0;
		float dY = ((float) nunchuck::dY()) / 100.0;
		if (dY < 0) {
			rgb[0] = 255 + (255*dY);
			rgb[1] = 255;
			rgb[2] = 255;
		} else {
			rgb[0] = 255;
			if (dX < 0) {
				rgb[1] = 255 - (255 * sqrtf(dX*dX+dY*dY)/sqrtf(2.0));
				rgb[2] = 255;
			} else {
				rgb[1] = 255;
				rgb[2] = 255 - (255 * sqrtf(dX*dX+dY*dY)/sqrtf(2.0));
			}

		}

		// Brightness
		if (nunchuck::Z()) {
			if (!C_or_Z && brightness > 0.0) brightness -= .05;
			C_or_Z = 5;
		} else if (nunchuck::C()) {
			if (!C_or_Z && brightness < 1.0) brightness += .05;
			C_or_Z = 5;
		} else if (C_or_Z) C_or_Z--;
		
// Draw the ball
		for (unsigned p = 0 ; p < num_pixels; p++) {
			ledscape_set_color(frame[use_frame], 12, p,
				(p == ball) ? (uint8_t) ((float) rgb[0] * brightness) : 0,
				(p == ball) ? (uint8_t) ((float) rgb[1] * brightness) : 0,
				(p == ball) ? (uint8_t) ((float) rgb[2] * brightness) : 0);
			ledscape_set_color(frame[use_frame], 19, p,
				(p == ball) ? (uint8_t) ((float) rgb[0] * brightness) : 0,
				(p == ball) ? (uint8_t) ((float) rgb[1] * brightness) : 0,
				(p == ball) ? (uint8_t) ((float) rgb[2] * brightness) : 0);
		}
		
		
		(void) ledscape_wait(leds);
		ledscape_draw(leds, use_frame);

		// Switch frame
		use_frame = (use_frame + 1) % 2;

		// Slow down play!
		usleep((4-speed)*10000);
	*/
	
	}
	
	// Turn off all LEDs
	for (unsigned p = 0 ; p < num_pixels; p++) {
	       ledscape_set_color(frame[use_frame], 12, p, 0, 0, 0);
	       ledscape_set_color(frame[use_frame], 19, p, 0, 0, 0);
	}
	(void) ledscape_wait(leds);
	ledscape_draw(leds, use_frame);

	ledscape_close(leds);

	return EXIT_SUCCESS;
	
}
