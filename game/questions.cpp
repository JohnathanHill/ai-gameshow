#include "questions.h"

void questions::keyVector(){ //stores questions and answer into key/value vector
	int i = 0;
	myfile.open("C:/Users/leeni/Documents/CSCI Classes/CSCI 166/Project/gameShow/gameShow/questionsAnswers.txt");
	if (myfile.is_open()) {
		while (getline(myfile, ques) && i < 10) { //stores all questions/answers into vector
			getline(myfile, answ);
			qaVect.push_back(std::make_pair(ques, answ));
			//cout << ques << endl << answ << endl;
			i++;
		}
	}
	else {
		std::cerr << "Cannot open the file";
	}
	myfile.close();
}


void questions::printKeyVector() { //prints key/value vector pair
	for (int i = 0; i < qaVect.size(); i++) {
		std::cout << qaVect[i].first << "-->" << qaVect[i].second << std::endl;
	}
}

void questions::questionBank(){//stores questions only into vector
	int i = 0;
	myfile.open("C:/Users/leeni/Documents/CSCI Classes/CSCI 166/Project/gameShow/gameShow/questionsAnswers.txt");
	if (myfile.is_open()) {
		while (getline(myfile, ques) && i < 10) { //stores all questions into vector
			if (ques.find("Answer:")) {
				questionVect.push_back(ques);
				//cout << ques << endl;
				i++;
			}
		}
	}
	else {
		std::cerr << "Cannot open the file";
	}
	myfile.close();
}

void questions::answerBank(){ //stores answers only into vector
	int i = 0;
	myfile.open("C:/Users/leeni/Documents/CSCI Classes/CSCI 166/Project/gameShow/gameShow/questionsAnswers.txt");
	if (myfile.is_open()) {
		while (getline(myfile, answ) && i < 10) { //stores all answers into vector
			if (answ.find("Question:")) {
				questionVect.push_back(answ);
				//cout << answ << endl;
				i++;
			}
		}
	}
	else {
		std::cerr << "Cannot open the file";
	}
	myfile.close();

}
