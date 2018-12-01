#ifndef QUESTIONS_H
#define QUESTIONS_H
#include<fstream>
#include<iostream>
#include<vector>
#include<string>



class questions{

	private:
		std::vector<std::pair<std::string, std::string>> qaVect; //stores both question and answer
		std::string ques, answ;
		std::ifstream myfile;
		
	public:
		std::vector<std::string> questionVect;
		std::vector<std::string> answerVector;

		void keyVector(); 
		void printKeyVector();
		void questionBank();
		void answerBank();





};
#endif // !QUESTIONS_H
