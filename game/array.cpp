#include "array.h"


level::level(){}

level::level(struct stage, int n){//creates an array with each index as [question/answer]
	sizeArray = n; 
	data = new level[sizeArray];
	for (int i = 0; i < sizeArray; i++) {
		//data[i] = stage ques;
	}


}

level::~level()
{
}
