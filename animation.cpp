#include "animation.hpp"

void Animation::shift(Frame* picture, int x, int y) {

	if(x == 1) {	//Right shift

		pixel_t temp[mainHeight];

		for(int i = 0; i < mainHeight; i++) {

			temp[i] = picture->m_face[mainLength-1][i];
			//Temporary hold for right-most column

		}

		for(int i = mainLength - 1; i > 0; i--) {

			for(int j = 0; j < mainHeight; j++) {

				picture->m_face[i][j] = picture->m_face[i-1][j];

			}
		}

		for(int i = 0; i < mainHeight; i++) {

			picture->m_face[0][i] = temp[i];

		}

	}	

	if(x == -1) {	//Left shift

		pixel_t temp[mainHeight];

		for(int i = 0; i < mainHeight; i++) {

			temp[i] = picture->m_face[0][i];
			//Temporary hold for left-most column

		}

		for(int i = 0; i < mainLength-1; i++) {

			for(int j = 0; j < mainHeight; j++) {

				picture->m_face[i][j] = picture->m_face[i+1][j];

			}
		}

		for(int i = 0; i < mainHeight; i++) {

			picture->m_face[mainLength - 1][i] = temp[i];

		}

	}

	
	if(y == 1) {	//Up shift

		pixel_t temp[mainLength];

		for(int i = 0; i < mainLength; i++) {

			temp[i] = picture->m_face[i][mainHeight - 1];
			//Temporary hold for top row

		}

		for(int i = mainHeight - 1; i > 0; i--) {

			for(int j = 0; j < mainLength; j++) {

				picture->m_face[j][i] = picture->m_face[j][i-1];

			}
		}

		for(int i = 0; i < mainLength; i++) {

			picture->m_face[i][0] = temp[i];

		}

	}
	
	if(y == -1) {	//Down shift

		pixel_t temp[mainLength];

		for(int i = 0; i < mainLength; i++) {

			temp[i] = picture->m_face[i][0];
			//Temporary hold for bottom row

		}

		for(int i = 0; i < mainHeight - 1; i++) {

			for(int j = 0; j < mainLength; j++) {

				picture->m_face[j][i] = picture->m_face[j][i+1];

			}
		}

		for(int i = 0; i < mainLength; i++) {

			picture->m_face[i][mainHeight - 1] = temp[i];

		}

	}

	return;

}
