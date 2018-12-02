#ifndef QUESTIONS_H
#define QUESTIONS_H
#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include "array.h"

class questions {

	private:
		std::vector<std::pair<std::string, std::string> > qaVect; //stores both question and answer
		std::string ques, answ;
		std::ifstream myfile;
		int increment = 0;
		int aIncrement = 0;
		
	public:
		std::vector<std::string> questionVect; //question vector
		std::vector<std::string> answerVector; //answer vector

		void keyVector(); 
		void printKeyVector();
		void questionBank();
		void answerBank();
		std::string getQuestion(); //return questions
		std::string getAllAnswer(); //return all 10 answers
		std::string getRightAnswer(std::string);






};
#endif // !QUESTIONS_H
