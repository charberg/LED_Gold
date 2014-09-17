#include "stringScroll.hpp"
#include <stdio.h>

StringScroll::StringScroll(std::string word_input) {

	charCount = 0;
	rowCount = 0;
	word = word_input;
	picture_1.delay = 100000;

}

const Frame* StringScroll::getNextFrame() {

	if(charCount != -1) {
		letter = LEDLetter(word[charCount]);
	}

	else {

		letter = LEDLetter(' ');

	}	

	shift(&picture_1,0,1);

	if(rowCount < letterHeight) {

		for(int i = 0; i < mainLength; i++) {

			picture_1.m_face[i][0] = letter[i][letterHeight - 1 - rowCount];

		}

	}

	if(rowCount == letterHeight) {	//If all letter rows already printed

		for(int i = 0; i < mainLength; i++) {

			picture_1.m_face[i][0].r = 0;
			picture_1.m_face[i][0].g = 0;
			picture_1.m_face[i][0].b = 0;
		}

		rowCount = -1;	//Reset to bottom of character
		charCount++;	//Move on to next character

	}

	rowCount++;

	if(charCount == word.length()) {	//If at end of word

		charCount = -1;

	}

	return &picture_1;

}

