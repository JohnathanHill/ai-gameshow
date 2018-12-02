
#include "questions.h"
//#include "array.h"
#include<iostream>
#include<string>
#include<windows.h>
#include<algorithm>
#include<random>
#include<chrono>
#include<iterator>
//asd
struct Agent {
	int correct[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	//string 2darray to remember wrong answers ==> wrong[question][wrong answers]
	//string array to remember right answer
	//randomize the questions per game
	//
};
/*agent asasdfas class mdp {
	value iteration (prob reward, smething something)
	policy iteration (prob reward)
	q-learning
	approx q learning

}
*/
struct gameStage {
	std::string question;
	std::string a[10];
	std::string checkAnswer;
};

int main() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Agent Bob;
	questions q;
	q.keyVector();
	//q.printKeyVector();
	q.questionBank();
	q.answerBank();


	gameStage *que = new gameStage[10];

	for (int i = 0; i < 10; i++) {
		std::string temp = q.getQuestion();
		que[i].question = temp; //question
		que[i].checkAnswer = q.getRightAnswer(temp); // correct answer
		for (int j = 0; j < 10; j++) {
			que[i].a[j] = q.getAllAnswer(); //bunch of answers
		}
	}
	std::string answerB[10];
	std::random_device rd;
	std::mt19937 g(rd());
	for (int i = 0; i < 10; i++) {
		answerB[i] = que[0].a[i];
	}
	std::shuffle(answerB, answerB + 10, g);

	//for(int i = 0; i < 10; i++) {
	//	std::cout << answerB[i] << std::endl;
	//}
	int i = 0;
	while(i < 10){
		//Sleep(1000);
		int qtemp = i + 1;
		std::cout << qtemp << ") " << que[i].question << "\n";
		//std::cout << que[i].a[Bob.correct[i]] << "\n";
		for (int j = 0; j < 10; j++) {
			if (Bob.correct[i] == j && (answerB[Bob.correct[i]] == que[i].checkAnswer))
			{
				//SetConsoleTextAttribute(hConsole, 10); // colors what agent picks green
				std::cout << answerB[j] << std::endl;

			}
			else if (Bob.correct[i] == j && (answerB[Bob.correct[i]] != que[i].checkAnswer))
			{
				
				//SetConsoleTextAttribute(hConsole, 4); //colors what agent picks red
				std::cout << answerB[j] << std::endl;
			}
			else if (answerB[j] == que[i].checkAnswer){
				SetConsoleTextAttribute(hConsole, 14); //highlights correct answer
				std::cout << answerB[j] << std::endl;
			}
			
			else
			{
			
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << answerB[j] << std::endl;
			}
		}
		Sleep(2000);
		system("CLS");
		std::cout << qtemp << ") " << que[i].question << "\n";
		for (int j = 0; j < 10; j++) {
			if (Bob.correct[i] == j && (answerB[Bob.correct[i]] == que[i].checkAnswer))
			{
				SetConsoleTextAttribute(hConsole, 10); // colors what agent picks green
				std::cout << answerB[j] << std::endl;

			}
			else if (Bob.correct[i] == j && (answerB[Bob.correct[i]] != que[i].checkAnswer))
			{

				SetConsoleTextAttribute(hConsole, 4); //colors what agent picks red
				std::cout << answerB[j] << std::endl;
			}
			else if (answerB[j] == que[i].checkAnswer){
				SetConsoleTextAttribute(hConsole, 14); //highlights correct answer
				std::cout << answerB[j] << std::endl;
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << answerB[j] << std::endl;
			}
		}
		Sleep(2000);
		SetConsoleTextAttribute(hConsole, 15);
		system("CLS");
		if (answerB[Bob.correct[i]] == que[i].checkAnswer) {
			//code here
			std::cout << "You Won" << std::endl;
			Sleep(1000);
			system("CLS");
			i++;

		}
		else {
			Bob.correct[i]++; //value gets inserted but index gets resetted
			//reward code here
			i = 0;
			std::cout << "You lost" << std::endl;
			Sleep(1000);
			system("CLS");
		}
		if (i == 9) {
			std::cout << "win";
		}
	}

	system("pause");
	return 0;
}