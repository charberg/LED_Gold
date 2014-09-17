#ifndef NAME_HPP
#define NAME_HPP

#include "animation.hpp"

class Name:public Animation {

	private:
		Frame picture_1;
	public:
		Name();
		const Frame* getNextFrame();

};

#endif
