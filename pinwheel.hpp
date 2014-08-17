#ifndef PINWHEEL_HPP
#define PINWHEEL_HPP

#include "animation.hpp"

class Pinwheel:public Animation {

	private:
		Frame picture_1;

	public:
		Pinwheel();
		const Frame* getNextFrame();

};

#endif
