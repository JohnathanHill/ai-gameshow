#ifndef ARRAY_H
#define ARRAY_H
#include<string>
#include<iostream>
#include<vector>



class levelarr{

	private:
		int sizeArray;
		levelarr *data;
		std::vector<std::pair<std::string, std::string> > &qaVect;
	
	public:
		levelarr();
		levelarr(int); //fix this function
		~levelarr();


};


#endif // !ARRAY_H
