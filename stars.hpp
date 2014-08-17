#ifndef STARS_HPP
#define STARS_HPP

#include "animation.hpp"

class Stars:public Animation {

	private:
		Frame picture_1;

	public:
		Stars();
		const Frame* getNextFrame();

};

#endif
