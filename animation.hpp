#include "frame.hpp"

class Animation {

	protected:
		int frameCount = 1;

	public:
		const virtual Frame* getNextFrame() = 0; 

};
