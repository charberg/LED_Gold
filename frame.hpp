#include <stdint.h>

#define mainLength 6
#define mainHeight 19
#define sideLength 3
#define sideHeight 7

typedef struct pixel_m {

	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;

} pixel_t;

class Frame {

	public:

	pixel_t m_face[mainLength][mainHeight];
	pixel_t m_side[sideLength][sideHeight];
	
	unsigned int delayUSec;	

};
