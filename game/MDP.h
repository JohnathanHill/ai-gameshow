#ifndef MDP_H
#define MDP_H

#include<string>
#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<cstdlib>

using namespace std;

class MDP {
    private:
		int action = 2;
		int state = 10;
		double gamma;
        double compute_max_value(int);

		vector<vector<vector<double>>> R;
		vector<vector<vector<double>>> T;
		vector<int> policy;
		vector<double> vStar;
		vector<double>(s);
    
    public:
		void display_MDP();
		void value_iterations(double);
};


#endif // !MDP_H
