#ifndef FRAME__HPP
#define FRAME__HPP

#include <stdint.h>

#define mainLength 6
#define mainHeight 19
#define sideLength 4
#define sideHeight 7

typedef struct pixel_m {

	uint8_t r;
	uint8_t g;
	uint8_t b;

} pixel_t;

class Frame {

	public:

	pixel_t m_face[mainLength][mainHeight];
	pixel_t m_side[sideLength][sideHeight];
	
	unsigned int delay;	

	Frame();

};

#endif
