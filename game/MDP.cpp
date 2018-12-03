#include "MDP.h"

double MDP::compute_max_value(int s){
	double max_value = -9999999.0;

	for (int a = 0; a < action; a++) {
		double exp_value = 0.0;

		for (int newState = 0; newState < state; newState++) {
			exp_value = exp_value + T[s][a][newState] * (R[s][a][newState] + gamma * vStar[newState]);
		}

		if (exp_value > max_value) {
			max_value = exp_value;
			policy[s] = a;
		}
	}

	vStar[s] = max_value;
	return max_value;
	return 0.0;
}

void MDP::display_MDP(){


}

void MDP::value_iterations(double eph) {
	bool converged = false;
	double max_diff;
	int itr = 0;
	while (!converged) {
		max_diff = -1.0;

		for (int s = 0; s < state; s++) {
			double old_value = vStar[s];
			double new_value = compute_max_value(s);  /* V vector is updated with the new value inside the function */

			if (abs(new_value - old_value) > max_diff) {
				max_diff = abs(new_value - old_value);
			}
		}

		// cout<<"max diff "<<max_diff<<"\n";
		if (max_diff <= eph) {
			converged = true;
		}

		itr++;
	}
}
