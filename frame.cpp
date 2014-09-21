#include "frame.hpp"

Frame::Frame() {

	for(int i = 0; i < mainLength; i++) {
		for(int j = 0; j < mainHeight; j++) {

			m_face[i][j].r = 0;
			m_face[i][j].g = 0;
			m_face[i][j].b = 0;
		}
	}

	for(int i = 0; i < sideLength; i++) {
		for(int j = 0; j < sideHeight; j++) {

			m_side[i][j].r = 0;
			m_side[i][j].g = 0;
			m_side[i][j].b = 0;
		}
	}
}
