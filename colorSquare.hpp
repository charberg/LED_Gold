#ifndef COLORSQUARE_HPP
#define COLORSQUARE_HPP

#include "animation.hpp"

class ColorSquare : public Animation {

	private:

		Frame picture_1;
		int red;
		int blue;
		int green;

	public:

		ColorSquare();
		const Frame* getNextFrame();

};

#endif
