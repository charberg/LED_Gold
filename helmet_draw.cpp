#include "ledscape.h"
#include "bonelib/kbdio.hpp"
//Animation include files//
#include "smiley.hpp"


static unsigned int use_frame = 0;
static ledscape_frame_t *frame[2];
const unsigned num_pixels = 170;
ledscape_t* const leds = ledscape_init(num_pixels);

void draw(const Frame* picture) {

	int counter = 0;


	for(int i = 0; i < sideLength; i++) {
		for(int j = 0; j < sideHeight; j++) {

			ledscape_set_color(frame[use_frame],22,counter,picture->m_side[i][j].r,picture->m_side[i][j].g,picture->m_side[i][j].b);	//Left Rainbow Drawing

			ledscape_set_color(frame[use_frame],10,counter,picture->m_side[i][j].r,picture->m_side[i][j].g,picture->m_side[i][j].b);	//Right Rainbow Drawing

			counter++;

		}
	}

	counter = 0;

	for(int i = 0; i < mainLength/2; i++) {
		for(int j = 0; j < mainHeight; j++) {

				if(i == 1) {

					ledscape_set_color(frame[use_frame],11,counter,picture->m_face[mainLength - 1 - i][j].r,picture->m_face[mainLength - 1 - i][j].g,picture->m_face[mainLength - 1 - i][j].b);	//Left Drawing
				}	

				else {
					ledscape_set_color(frame[use_frame],11,counter,picture->m_face[mainLength/2 - 1 - i][mainHeight -1 - j].r,picture->m_face[mainLength/2 - 1 - i][mainHeight -1 - j].g,picture->m_face[mainLength/2 - 1 - i][mainHeight -1 - j].b);	//Left Drawing
				}

				counter++;

			}	
	}

	counter = 0;

	for(int i = 3; i < mainLength; i++) {
		for(int j = 0; j < mainHeight; j++) {

				if(i == 4) {

					ledscape_set_color(frame[use_frame],14,counter,picture->m_face[i][j].r,picture->m_face[i][j].g,picture->m_face[i][j].b);	//Left Drawing
				}	

				else {
					ledscape_set_color(frame[use_frame],14,counter,picture->m_face[i][mainHeight -1 - j].r,picture->m_face[i][mainHeight -1 - j].g,picture->m_face[i][mainHeight -1 - j].b);	//Left Drawing
				}
				
				counter++;

			}	
	}

	ledscape_draw(leds, use_frame);
	use_frame = (use_frame + 1)%2;
	usleep(200000);	//Come back, make this class dependant;

	return;
}

int main(void) {

	frame[0] = ledscape_frame(leds, 0);
	frame[1] = ledscape_frame(leds, 1);
	int nextAnimation;

	Animation* drawing = new Smiley();

	while(1) {

		draw(drawing->getNextFrame());
		
		if(BeagleBone::kbdio::kbhit() > 0) {

			nextAnimation = BeagleBone::kbdio::getch();
			delete drawing;	//De-allocate previous animationi

			//Keyboard Mapping

			if(nextAnimation == 's') {

				drawing = new Smiley();

			}

			if(nextAnimation == 'q') {

				break;

			}
		}	
	}
}
