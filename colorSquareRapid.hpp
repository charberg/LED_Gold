#ifndef COLORSQUARERAPID_HPP
#define COLORSQUARERAPID_HPP

#include "animation.hpp"

class ColorSquareRapid : public Animation {

	private:

		Frame picture_1;
		Frame picture_2;
		int red;
		int blue;
		int green;
		int counter;

	public:

		ColorSquareRapid();
		const Frame* getNextFrame();

};

#endif
