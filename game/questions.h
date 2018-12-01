#ifndef QUESTIONS_H
#define QUESTIONS_H
#include<fstream>
#include<iostream>
#include<vector>

using namespace std;

class questions{

	private:
		vector<string> qVect;
	public:
		void readToVector();
		void printVector();




};
#endif // !QUESTIONS_H
