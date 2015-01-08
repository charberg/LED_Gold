#include "ledscape.h"
#include "bonelib/kbdio.hpp"
//Animation include files//
#include "smiley.hpp"
#include "blank.hpp"
#include "fullColor.hpp"
#include "colorSquare.hpp"
#include "colorSquareRapid.hpp"
#include "scanner.hpp"
#include "pinwheel.hpp"
#include "upvote.hpp"
#include "stars.hpp"
#include "rainbowWheel.hpp"
#include "stringScroll.hpp"
#include "shootingStars.hpp"
#include "rainbowRoad.hpp"

static unsigned int use_frame = 0;
static ledscape_frame_t *frame[2];
const unsigned num_pixels = 170;
ledscape_t* const leds = ledscape_init(num_pixels);

void draw(const Frame* picture) {

	int counter = 0;


	for(int i = 0; i < sideHeight; i++) {
		for(int j = 0; j < sideLength; j++) {

			ledscape_set_color(frame[use_frame],22,counter,picture->m_side[j][sideHeight - 1 - i].r,picture->m_side[j][sideHeight - 1 - i].g,picture->m_side[j][sideHeight - 1 - i].b);	//Left Rainbow Drawing

			ledscape_set_color(frame[use_frame],10,counter,picture->m_side[j][sideHeight - 1 - i].r,picture->m_side[j][sideHeight - 1 - i].g,picture->m_side[j][sideHeight - 1 - i].b);	//Right Rainbow Drawing

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
	printf("BEFORE %d\n", picture->delay);
	if (picture->delay > 0) usleep(picture->delay);
	printf("AFTER\n");	

	return;
}

int main(void) {

	frame[0] = ledscape_frame(leds, 0);
	frame[1] = ledscape_frame(leds, 1);
	int nextAnimation;

	Animation* new_drawing = new Smiley();

	BeagleBone::kbdio::echo(0);

	Animation* drawing = NULL;
	const Frame *frame;
	bool quit = 0;
	while(!quit) {
		if (drawing != new_drawing) {
			delete drawing;
			drawing = new_drawing;
			frame = drawing->getNextFrame();
			draw(frame);
		} else if (frame->delay > 0) {
			frame = drawing->getNextFrame();
			draw(frame);
		}
		
		if(BeagleBone::kbdio::kbhit() > 0) {

			nextAnimation = BeagleBone::kbdio::getch();

			//Keyboard Mapping

			switch (nextAnimation) {
			case 's':
				new_drawing = new Smiley();
				break;
			case 'q':
				new_drawing = new Blank();
				break;
			
			case 'd':
			case 'f':
				new_drawing = new FullColor();
				break;

			case 'w':
				new_drawing = new ColorSquare();
				break;

			case 'W':
				new_drawing = new ColorSquareRapid();
				break;

			case 'e':
				new_drawing = new Scanner();
				break;

			case 'r':
				new_drawing = new Pinwheel();
				break;
			
			case 't':
				new_drawing = new Upvote();
				break;

			case 'z':
				new_drawing = new Stars();
				break;

			case 'Z':
				new_drawing = new ShootingStars();
				break;

			case 'x':
				new_drawing = new RainbowWheel();
				break;

			case 'X':
			       	new_drawing = new RainbowRoad();
				break;

			case 'p':
				new_drawing = new StringScroll("SPACE ROCKS");
				break;	
		
			case 'l':
				new_drawing = new StringScroll("CULT");
				break;

			case 'Q':
				quit = 1;
				break;
			}
		}	
	}

	BeagleBone::kbdio::echo(1);
}
