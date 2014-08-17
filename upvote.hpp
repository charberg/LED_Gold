#ifndef UPVOTE_HPP
#define UPVOTE_HPP

#include "animation.hpp"

class Upvote:public Animation {

	private:
		Frame picture_1;
	public:
		Upvote();
		const Frame* getNextFrame();

};

#endif
