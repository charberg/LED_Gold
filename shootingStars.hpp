#ifndef SHOOTINGSTARS_HPP
#define SHOOTINGSTARS_HPP

#include "animation.hpp"

class ShootingStars:public Animation {

	private:
		Frame picture_1;

	public:
		ShootingStars();
		const Frame* getNextFrame();

};

#endif
