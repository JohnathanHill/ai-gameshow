#ifndef QUESTIONS_H
#define QUESTIONS_H

class questions{

	private:
		vector<pair<string, string>> qaVect; //stores both question and answer
		string ques, answ;
		ifstream myfile;
		
	public:
		vector<string> questionVect;
		vector<string> answerVector;

		void keyVector(); 
		void printKeyVector();
		void questionBank();
		void answerBank();





};
#endif // !QUESTIONS_H
