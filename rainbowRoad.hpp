#ifndef RAINBOWROAD_HPP
#define RAINBOWROAD_HPP

#include "animation.hpp"

class RainbowRoad:public Animation {

	private:
		Frame picture_1;
	public:
		RainbowRoad();
		const Frame* getNextFrame();

};

#endif
