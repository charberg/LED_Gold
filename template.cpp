#include "name.hpp"
#include <stdio.h>

Name::Name() {

	picture_1.delay = 25000;

}

const Frame* Name::getNextFrame() {

	return &picture_1;

}
