#ifndef FULLCOLOR_HPP
#define FULLCOLOR_HPP

#include "animation.hpp"

class FullColor : public Animation {

	private:

		Frame picture_1;
		int red;
		int blue;
		int green;

	public:

		FullColor();
		const Frame* getNextFrame();

};

#endif
