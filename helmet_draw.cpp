#include "ledscape.h"
#include "smiley.hpp"

void draw(const Frame* picture) {

	const unsigned num_pixels = 170;
	ledscape_t* const leds = ledscape_init(num_pixels);
	unsigned int use_frame = 0;
	ledscape_frame_t *frame[2];
	frame[0] = ledscape_frame(leds, 0);
	frame[1] = ledscape_frame(leds, 1);
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

					ledscape_set_color(frame[use_frame],14,counter,picture->m_face[i][j].r,picture->m_face[i][j].g,picture->m_face[i][j].b);	//Left Drawing
				}	

				else {
					ledscape_set_color(frame[use_frame],14,counter,picture->m_face[i][mainHeight - j].r,picture->m_face[i][mainHeight - j].g,picture->m_face[i][mainHeight - j].b);	//Left Drawing
				}

				counter++;

			}	
	}

	counter = 0;

	for(int i = 0; i < mainLength/2; i++) {
		for(int j = 0; j < mainHeight; j++) {

				if(i == 1) {

					ledscape_set_color(frame[use_frame],11,counter,picture->m_face[i][j].r,picture->m_face[i][j].g,picture->m_face[i][j].b);	//Left Drawing
				}	

				else {
					ledscape_set_color(frame[use_frame],11,counter,picture->m_face[i][mainHeight - j].r,picture->m_face[i][mainHeight - j].g,picture->m_face[i][mainHeight - j].b);	//Left Drawing
				}
				
				counter++;

			}	
	}

	ledscape_draw(leds, use_frame);
	use_frame = (use_frame + 1)%2;
	usleep(50000);	//Come back, make this class dependant;

	return;
}

int main(void) {

	Animation* drawing = new Smiley();

	while(1) {

		draw(drawing->getNextFrame());

	}

}
