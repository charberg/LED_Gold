#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "animation.hpp"

class Scanner:public Animation {

	private:
		Frame picture_1;

	public:
		Scanner();
		const Frame* getNextFrame();

};

#endif
