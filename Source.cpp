#include<iostream>
#include<ctime>
#include<random>
#include<algorithm>
#include<string>
#include<cmath>
#include<Windows.h>

int main() {
	srand(time(NULL));

	std::string message;
	std::string gridCode;
	bool EDSwitch;

	char letters[25] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	char gridArray[5][5];

	std::cout << "Enter '0' to encode a message, '1' to decode: ";
	std::cin >> EDSwitch;

	if (EDSwitch == 0) { //grid creation, only when encoding
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				int letter = rand() % 25;
				while (letters[letter] == NULL) {
					letter = rand() % 25;
				}
				//std::cout << letter << "\n";
				gridArray[i][j] = letters[letter];
				letters[letter] = NULL;
				//std::cout << gridArray[i] << "\n";
			}
		}
	}
	else if (EDSwitch == 1) {
		std::cout << "Enter your Grid Code: ";
		std::cin >> gridCode;
		int gridCodeIter = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				gridArray[i][j] = gridCode[gridCodeIter];
				gridCodeIter++;
			}
		}
	}

	std::cout << "\nYour grid: \n\n";

	for (int i = 0; i < 5; i++) {
		//std::cout << "(" << i + 1 << ")";
		for (int j = 0; j < 5; j++) {
			std::cout << gridArray[i][j] << " ";
			//std::cout << gridArray[j + (5 * i)] << "(" << j + 1 << ")" << " ";
		}
		std::cout << "\n";
	}

	if (EDSwitch == 0) {
		std::cout << "\nYour grids' code: ";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++)
			std::cout << gridArray[i][j];
		}
	}

	std::cout << "\n\n";

	if (EDSwitch == 0) {
		std::cout << "Enter your message to be encoded: ";
		std::cin >> message;
	}
	else if (EDSwitch == 1) {
		std::cout << "Enter your message to be decoded: ";
		std::cin >> message;
	}

	int messageSize = message.size();

	int tocryptX[255];
	int tocryptY[255];
	int toCrypt[500];
	char newMessage[500];

	//std::cout << messageSize << "\n";

	if (EDSwitch == 0) { //encoding
		for (int k = 0; k < message.size(); k++) { //k is character in message
			for (int i = 0; i < 5; i++) { //i = y
				for (int j = 0; j < 5; j++) { //j = x
					if (message[k] == gridArray[i][j]) {
						std::cout << "\n" << message[k] << " = ";
						int l2nX = j + 1;
						int l2nY = i + 1;
						std::cout << l2nY << ", " << l2nX;
						tocryptX[k] = l2nX;
						tocryptY[k] = l2nY;
					}
				}
			}
		}
		std::cout << "\n\n";
		for (int i = 0; i < messageSize; i++) {
			toCrypt[i] = tocryptY[i];
			//std::cout << codedYArray[i];
		}
		for (int i = 0; i < messageSize; i++) {
			toCrypt[i + messageSize] = tocryptX[i];
			//std::cout << codedXArray[i];
		}
		for (int i = 0; i < messageSize * 2; i++) {
			std::cout << toCrypt[i];
		}

		std::cout << std::endl << std::endl;

		//Making numbers into letters--------------------------------------------------------------------
		int iter = 0;
		for (int k = 0; k < messageSize * 2; k+=2) { //k is character in message
			std::cout << toCrypt[k] << ", " << toCrypt[k + 1] << " = ";
			std::cout << gridArray[(toCrypt[k]) - 1][(toCrypt[k + 1]) - 1] << "\n";
			message[iter] = gridArray[(toCrypt[k]) - 1][(toCrypt[k + 1]) - 1];
			iter++;
		}
		std::cout << "\n";
	}
	//------------------------------------------------------------------------------------------------------

	if (EDSwitch == 1) { //decoding
		for (int k = 0; k < message.size(); k++) { //k is character in message
			for (int i = 0; i < 5; i++) { //i = y
				for (int j = 0; j < 5; j++) { //j = x
					if (message[k] == gridArray[i][j]) {
						std::cout << "\n" << message[k] << " = ";
						int l2nX = j + 1;
						int l2nY = i + 1;
						std::cout << l2nY << ", " << l2nX;
						tocryptX[k] = l2nX;
						tocryptY[k] = l2nY;
					}
				}
			}
		}

		std::cout << "\n\n";

		int iter = 0;
		for (int k = 0; k < messageSize * 2; k += 2) { //k is character in message
			toCrypt[k] = tocryptY[iter];
			toCrypt[k + 1] = tocryptX[iter];
			iter++;
		}

		for (int i = 0; i < messageSize * 2; i++) {
			std::cout << toCrypt[i];
		}

		for (int k = 0; k < messageSize; k++) {
			message[k] = gridArray[toCrypt[k] - 1][toCrypt[k + messageSize] - 1];
		}
	}

	std::cout << "\n\n";

	if (EDSwitch == 0) {
		std::cout << "Your coded message: " << message;

		std::cout << "\n";
	}
	else if (EDSwitch == 1) {
		std::cout << "Your coded message: " << message;

		std::cout << "\n";
	}
	

	system("PAUSE");
}