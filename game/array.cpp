#include "array.h"
#include<string>
#include<iostream>

using namespace std;

template<typename T>
level<T>::level() {}

template<typename T>
level<T>::level(vector<string> question, vector<string> answer, int n){//creates an array with each index as [question/answer]
	sizeArray = n;
	arrSize = new T[sizeArray];
	for (int i = 0; i < n, i++) {
		arrSize[i] = vector<string> question;
	}

}
