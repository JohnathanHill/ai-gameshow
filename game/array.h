#ifndef ARRAY_H
#define ARRAY_H
#include<string>

#include<iostream>


struct stage{
	std::string que;
	std::string a;
	bool check;
};
	
class level{

	private:
		int sizeArray;
		level *data;
	public:
		level();
		level(stage, int); //fix this function
		~level();


};


#endif // !ARRAY_H
