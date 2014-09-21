#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "frame.hpp"


#define letterLength 6
#define letterHeight 7

class Animation {

	protected:
		int frameCount;
		virtual void shift(Frame* picture, int x, int y);
		virtual pixel_t** LEDLetter(char letter);

	public:
		virtual ~Animation() {};
		const virtual Frame* getNextFrame() = 0;	
		Animation();
		
};

#endif
