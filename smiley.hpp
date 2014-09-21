#ifndef SMILEY__HPP
#define SMILEY__HPP

#include "animation.hpp"

class Smiley : public Animation {

	private:

		Frame picture_1;
		Frame picture_2;

	public :

       		const Frame* getNextFrame();

};

#endif
