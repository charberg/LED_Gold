#ifndef RAINBOWWHEEL_HPP
#define RAINBOWWHEEL_HPP

#include "animation.hpp"

class RainbowWheel : public Animation {

	private:
		bool wings[7];
		int direction;
		bool directionChange;
		Frame picture_1;

	public :
		RainbowWheel();
       		const Frame* getNextFrame();

};

#endif
