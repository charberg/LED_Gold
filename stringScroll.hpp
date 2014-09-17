#ifndef STRINGSCROLL_HPP
#define STRINGSCROLL_HPP

#include "animation.hpp"
#include <string>

class StringScroll:public Animation {

	private:
		Frame picture_1;
		std::string word;
		int charCount;
		int rowCount;
		pixel_t** letter;
		bool clear;
	public:
		StringScroll(std::string word_input);
		const Frame* getNextFrame();

};

#endif
