#include "animation.hpp"

Animation::Animation() {

	frameCount = 1;

}

pixel_t** Animation::LEDLetter(char letter) {

	pixel_t** LEDMatrix = new pixel_t*[mainLength];

	for(int i = 0; i < mainLength; i++) {

		LEDMatrix[i] = new pixel_t[letterHeight];

	}

	for(int i = 0; i < mainLength; i++) {

		for(int j = 0; j < letterHeight; j++) {

			LEDMatrix[i][j].r = 0;
			LEDMatrix[i][j].g = 0;
			LEDMatrix[i][j].b = 0;
		}

	}

	//NOTE: Letters should be drawn 5x7, but are designed as 6x7 to be functional with shift(), defined below

	//Letter library

	switch(letter) {

		case 'a':
		case 'A':
			
			for(int i = 0; i < letterHeight - 1; i++) {

				LEDMatrix[1][i].r = 200;
				LEDMatrix[5][i].r = 200;

			}

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][2].r = 200;
				LEDMatrix[i][6].r = 200;

			}

			break;

		case 'b':
		case 'B':

			for(int i = 0; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;

			}

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][6].r = 200;
				LEDMatrix[i][3].r = 200;
				LEDMatrix[i][0].r = 200;

			}

			LEDMatrix[5][1].r = 200;
			LEDMatrix[5][2].r = 200;
			LEDMatrix[5][4].r = 200;
			LEDMatrix[5][5].r = 200;

			break;

		case 'c':
		case 'C':

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][6].r = 200;

			}	

			for(int i = 1; i < 6; i++) {

				LEDMatrix[1][i].r = 200;

			}

			LEDMatrix[5][1].r = 200;
			LEDMatrix[5][5].r = 200;

			break;

		case 'd':
		case 'D':
	
			for(int i = 0; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;
				LEDMatrix[5][i].r = 200;

			}	

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][6].r = 200;

			}

			LEDMatrix[5][6].r = 0;
			LEDMatrix[5][0].r = 0;

			break;

		case 'e':
		case 'E':

		
			for(int i = 2; i < 6; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][6].r = 200;

				if(i != 5) {
					LEDMatrix[i][3].r = 200;
				}

			}	

			for(int i = 0; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;

			}	

			break;

		case 'f':
		case 'F':

			
			for(int i = 2; i < 6; i++) {

				LEDMatrix[i][6].r = 200;

				if(i != 5) {
					LEDMatrix[i][3].r = 200;
				}

			}	

			for(int i = 0; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;

			}	

			break;

		case 'g':
		case 'G':

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][6].r = 200;
				LEDMatrix[i+1][2].r = 200;

			}

			for(int i = 1; i < 6; i++) {

				LEDMatrix[1][i].r = 200;

			}

			LEDMatrix[5][1].r = 200;
			LEDMatrix[5][5].r = 200;

			break;

		case 'h':
		case 'H':

			for(int i = 0; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;
				LEDMatrix[5][i].r = 200;

			}

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][3].r = 200;

			}

			break;

		case 'i':
		case 'I':

			for(int i = 1; i < 6; i++) {

				LEDMatrix[3][i].r = 200;

			}

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][6].r = 200;

			}

			break;

		case 'j':
		case 'J':

			for(int i = 1; i < letterHeight; i++) {

				LEDMatrix[5][i].r = 200;

			}

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][0].r = 200;

			}

			LEDMatrix[1][1].r = 200;
			LEDMatrix[1][2].r = 200;
			
			break;

		case 'k':
		case 'K':
			
			for(int i = 0; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;

			}

			for(int i = 0; i < 4; i++) {

				LEDMatrix[i + 2][3 + i].r = 200;
				LEDMatrix[i + 2][3 - i].r = 200;

			}

			break;

		case 'l':
		case 'L':

	
			for(int i = 0; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;

			}

			for(int i = 1; i < mainLength; i++) {

				LEDMatrix[i][0].r = 200;

			}	

			break;	

		case 'm':
		case 'M':

			for(int i = 0; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;
				LEDMatrix[5][i].r = 200;

			}

			LEDMatrix[2][5].r = 200;
			LEDMatrix[3][4].r = 200;
			LEDMatrix[4][5].r = 200;

			break;

		case 'n':
		case 'N':

			for(int i = 0; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;
				LEDMatrix[5][i].r = 200;

			}

			LEDMatrix[2][4].r = 200;
			LEDMatrix[3][3].r = 200;
			LEDMatrix[4][2].r = 200;

			break;

		case 'o':
		case 'O':

	
			for(int i = 1; i < 6; i++) {

				LEDMatrix[1][i].r = 200;
				LEDMatrix[5][i].r = 200;

			}

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][6].r = 200;

			}	

			break;	

		case 'p':
		case 'P':

			for(int i = 0; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;

			}

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][2].r = 200;
				LEDMatrix[i][6].r = 200;
				LEDMatrix[5][i+1].r = 200;

			}

			break;

		case 'q':
		case 'Q':

			for(int i = 1; i < 6; i++) {

				LEDMatrix[1][i].r = 200;
				LEDMatrix[5][i].r = 200;

			}

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][6].r = 200;

			}

			LEDMatrix[3][2].r = 200;
			LEDMatrix[4][1].r = 200;
			LEDMatrix[5][0].r = 200;

			break;

		case 'r':
		case 'R':

			for(int i = 0; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;

			}


			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][2].r = 200;
				LEDMatrix[i][6].r = 200;

			}

			for(int i = 0; i < 6; i++) {

				if(i != 2) {

					LEDMatrix[5][i].r = 200;
				
				}
			}

			break;

		case 's':
		case 'S':

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][3].r = 200;
				LEDMatrix[i][6].r = 200;

			}

			for(int i = 1; i < 6; i++) {

				if(i != 3) {
				
					LEDMatrix[1][i].r = 200;
					LEDMatrix[5][i].r = 200;

				}

			}

			LEDMatrix[1][2].r = 0;
			LEDMatrix[5][4].r = 0;

			break;

		case 't':
		case 'T':

			for(int i = 0; i < 6; i++) {

				LEDMatrix[3][i].r = 200;

			}

			for(int i = 1; i < mainLength; i++) {

				LEDMatrix[i][6].r = 200;

			}

			break;

		case 'u':
		case 'U':

			for(int i = 1; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;
				LEDMatrix[5][i].r = 200;

			}

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][0].r = 200;

			}

			break;

		case 'v':
		case 'V':

			for(int i = 2; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;
				LEDMatrix[5][i].r = 200;

			}

			LEDMatrix[2][1].r = 200;
			LEDMatrix[3][0].r = 200;
			LEDMatrix[4][1].r = 200;

			break;

		case 'w':
		case 'W':

			for(int i = 0; i < letterHeight; i++) {

				LEDMatrix[1][i].r = 200;
				LEDMatrix[5][i].r = 200;

			}

			LEDMatrix[2][1].r = 200;
			LEDMatrix[3][2].r = 200;
			LEDMatrix[4][1].r = 200;

			break;
		
		case 'x':
		case 'X':

			for(int i = 0; i < 2; i++) {

				LEDMatrix[1][i].r = 200;
				LEDMatrix[1][i+5].r = 200;
				LEDMatrix[5][i].r = 200;
				LEDMatrix[5][i+5].r = 200;

			}

			LEDMatrix[2][2].r = 200;
			LEDMatrix[3][3].r = 200;
			LEDMatrix[4][4].r = 200;
			LEDMatrix[2][4].r = 200;
			LEDMatrix[4][2].r = 200;

			break;

		case 'y':
		case 'Y':

			for(int i = 0; i < 3; i++) {

				LEDMatrix[1][4 + i].r = 200;
				LEDMatrix[5][4 + i].r = 200;
				LEDMatrix[3][i].r = 200;

			}

			LEDMatrix[2][3].r = 200;
			LEDMatrix[4][3].r = 200;

			break;

		case 'z':
		case 'Z':

			for(int i = 1; i < mainLength; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][6].r = 200;
				LEDMatrix[i][i].r = 200;

			}

			break;

		case '0':

			for(int i = 1; i < mainLength; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][6].r = 200;
				LEDMatrix[1][i].r = 200;
				LEDMatrix[5][i].r = 200;

			}	

			break;

		case '1':

			for(int i = 0; i < letterHeight; i++) {

				LEDMatrix[3][i].r = 200;

			}

			LEDMatrix[2][5].r = 200;

			break;
		
		case '2':

			for(int i = 1; i < mainLength; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][3].r = 200;
				LEDMatrix[i][6].r = 200;

			}

			LEDMatrix[1][1].r = 200;
			LEDMatrix[1][2].r = 200;
			LEDMatrix[5][4].r = 200;
			LEDMatrix[5][5].r = 200;

			break;

		case '3':

			for(int i = 1; i < mainLength; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][3].r = 200;
				LEDMatrix[i][6].r = 200;
				LEDMatrix[5][i].r = 200;

			}

			break;

		case '4':

			for(int i = 0; i < letterHeight; i++) {
				
				LEDMatrix[5][i].r = 200;

				if(i > 2) {

					LEDMatrix[1][i].r = 200;

				}

			}

			for(int i = 2; i < 5; i++) {

				LEDMatrix[i][3].r = 200;

			}

			break;

		case '5':

			for(int i = 1; i < mainLength; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][3].r = 200;
				LEDMatrix[i][6].r = 200;

			}

			LEDMatrix[5][1].r = 200;
			LEDMatrix[5][2].r = 200;
			LEDMatrix[1][4].r = 200;
			LEDMatrix[1][5].r = 200;

			break;

		case '6':

			for(int i = 1; i < mainLength; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][3].r = 200;
				LEDMatrix[i][6].r = 200;

			}

			for(int i = 1; i < 3; i++) {

				LEDMatrix[1][i].r = 200;
				LEDMatrix[1][i+3].r = 200;
				LEDMatrix[5][i].r = 200;

			}

			break;

		case '7':

			for(int i = 1; i < mainLength; i++) {

				LEDMatrix[i][6].r = 200;

			}

			for(int i = 0; i < 3; i++) {

				LEDMatrix[3][i].r = 200;
				LEDMatrix[5][i+4].r = 200;

			}

			LEDMatrix[4][4].r = 200;

			break;

		case '8':

			for(int i = 1; i < 6; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][3].r = 200;
				LEDMatrix[i][6].r = 200;
				LEDMatrix[1][i].r = 200;
				LEDMatrix[5][i].r = 200;
			}

			break;

		case '9':

			for(int i = 1; i < mainLength; i++) {

				LEDMatrix[i][0].r = 200;
				LEDMatrix[i][3].r = 200;
				LEDMatrix[i][6].r = 200;

			}

			for(int i = 1; i < 3; i++) {

				LEDMatrix[5][i].r = 200;
				LEDMatrix[5][i+3].r = 200;
				LEDMatrix[1][i+3].r = 200;

			}

			break;

		case '!':

			for(int i = 0; i < letterHeight; i++) {
				
				if(i != 1) {
					LEDMatrix[3][i].r = 200;
				}
			}

			break;

		case '?':

			LEDMatrix[3][0].r = 200;
			LEDMatrix[3][2].r = 200;
			LEDMatrix[4][3].r = 200;
			LEDMatrix[5][4].r = 200;
			LEDMatrix[5][5].r = 200;
			LEDMatrix[4][6].r = 200;
			LEDMatrix[3][6].r = 200;
			LEDMatrix[2][6].r = 200;
			LEDMatrix[1][5].r = 200;
			
			break;

		case '+':

			for(int i = 1; i < 6; i++) {

				LEDMatrix[3][i].r = 200;
				LEDMatrix[i][3].r = 200;

			}
		
			break;

		case '#':

			for(int i = 1; i < letterLength; i++) {

				LEDMatrix[i][1].r = 200;
				LEDMatrix[i][3].r = 200;

			}

			for(int i = 0; i < 5; i++) {

				LEDMatrix[2][i].r = 200;
				LEDMatrix[4][i].r = 200;

			}

			break;

		case ' ':

			for(int i = 0; i < letterLength; i++) {
				for(int j = 0; j < letterHeight; j++) {
			
					LEDMatrix[i][j].r = 0;
					LEDMatrix[i][j].g = 0;
					LEDMatrix[i][j].b = 0;
				}
			}

			break;
	}				

	return LEDMatrix;

}

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
