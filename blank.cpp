#include "blank.hpp"
#include <stdio.h>

Blank::Blank() {

	picture_1.delay = 0;

}

const Frame* Blank::getNextFrame() {

	return &picture_1;	//Set to default 0 for rgb values

}
