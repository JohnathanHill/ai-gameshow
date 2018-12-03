
#include "questions.h"
#include "MDP.h"
#include<iostream>
#include<string>
#include<windows.h>
#include<algorithm>
#include<random>
#include<chrono>
#include<iterator>


struct Agent {
	int correct[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int rewards = 1;
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

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //handles console commands
	int timer = 1500;
	int points = 1;
	Agent Bob;
	questions q;
	q.keyVector();		//sets up key,value pair of questions
	//q.printKeyVector();
	q.questionBank();   //sets up vector of questions
	q.answerBank();		//sets up vector of answers

	gameStage *que = new gameStage[10];  //initilize array of structs

	for (int i = 0; i < 10; i++) {
		std::string temp = q.getQuestion();
		que[i].question = temp; //stores questions into array 
		que[i].checkAnswer = q.getRightAnswer(temp); // stores correct answer
		for (int j = 0; j < 10; j++) {
			que[i].a[j] = q.getAllAnswer(); //stores all the answers
		}
	}
	std::string answerB[10]; //stores answer bank into another array for shuffling
	std::random_device rd;
	std::mt19937 g(rd());
	for (int i = 0; i < 10; i++) {
		answerB[i] = que[0].a[i];
	}
	std::shuffle(answerB, answerB + 10, g);

	//for(int i = 0; i < 10; i++) {
	//	std::cout << answerB[i] << std::endl;
	//}
	int i = 0; //counter
	while(i < 10){ //loops thru the array of structs
		//Sleep(1000);
		int qtemp = i + 1; //used to output question number in console
		std::cout << qtemp << ") " << que[i].question << "\n";
		//std::cout << que[i].a[Bob.correct[i]] << "\n";
		for (int j = 0; j < 10; j++) {
			if (Bob.correct[i] == j && (answerB[Bob.correct[i]] == que[i].checkAnswer)) //if angent answers correctly
			{
				//SetConsoleTextAttribute(hConsole, 10); // colors what agent picks green
				std::cout << answerB[j] << std::endl;

			}
			else if (Bob.correct[i] == j && (answerB[Bob.correct[i]] != que[i].checkAnswer)) //if agent answers incorrectly
			{
				
				//SetConsoleTextAttribute(hConsole, 4); //colors what agent picks red
				std::cout << answerB[j] << std::endl;
			}
			else if (answerB[j] == que[i].checkAnswer){ //if answer stored answer is the correct answer
				SetConsoleTextAttribute(hConsole, 14); //highlights correct answer
				std::cout << answerB[j] << std::endl;
			}
			
			else //wrong answers
			{
			
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << answerB[j] << std::endl;
			}
		}
		Sleep(timer);
		system("CLS"); //clears console screen
		SetConsoleTextAttribute(hConsole, 15);
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
		Sleep(timer);
		SetConsoleTextAttribute(hConsole, 15);
		system("CLS");
		if (answerB[Bob.correct[i]] == que[i].checkAnswer) {
			Bob.rewards *= 2; //doubles the rewards for each question right
			std::cout << "You Won " << floor(sqrt(Bob.rewards)) << " reward points" << std::endl;
			std::cout << "Reward points:" << Bob.rewards << std::endl;
			Sleep(1000);
			system("CLS");
			i++;

		}
		else {
			Bob.correct[i]++; //value gets inserted but index gets resetted
			Bob.rewards = 1; //reset back to 1
			i = 0;
			std::cout << "You lost" << std::endl;
			std::cout << "Reward points: " << Bob.rewards << std::endl;
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