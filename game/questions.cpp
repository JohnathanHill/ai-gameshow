#include "questions.h"


using namespace std;

void questions::readToVector(){
	ifstream myfile ("questionsAnswers.txt");
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			if (myfile.getline == "question") {
				qVect.push_back(myfile.getline);
			}
		}
	}
}

void questions::printVector(){
	for (int i = 0; i < qVect.size(); i++) {
		cout << qVect[i] << " ";
	}
}
