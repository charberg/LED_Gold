#ifndef BLANK_HPP
#define BLANK_HPP

#include "animation.hpp"

class Blank : public Animation {

	private:

		Frame picture_1;

	public :

		Blank();
		const Frame* getNextFrame();

};

#endif
