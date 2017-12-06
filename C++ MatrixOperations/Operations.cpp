#include "Operations.h"
#include <iostream>
#include <vector>
using namespace std;

bool AddChecker(vector<vector<int>> x, vector<vector<int>> y) {
	if (x.size() == y.size()) {
		if (x[0].size() == y[0].size()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool MultiplyChecker(vector<vector<int>> x, vector<vector<int>> y) {
	if (x[0].size() == y.size()) {
		return true;
	}
	else {
		return false;
	}
}

vector<vector<int>> Operations::Add(vector<vector<int>> x, vector<vector<int>> y) {
	vector<vector<int>> retval = vector< vector<int>>(x.size(), vector<int>(x[0].size()));
	if (AddChecker (x, y)) {
		for (int i = 0; i < x.size(); i++) {
			for (int k = 0; k < y[i].size(); k++) {
				if (!y[i].empty()) {
					if (y[i][k]) {
						retval[i][k] = x[i][k] + y[i][k];
					}
					else {
						cout << "Try Again";
						return vector<vector<int>>();
					}
				}
				else {
					cout << "Try Again";
					return vector<vector<int>>();
				}
			}
		}
	}
	else {
		cout << "Try Again";
		return vector<vector<int>>();
	}

	return retval;

}

vector<vector<int>> Operations::Transpose(vector<vector<int>> x) {
	vector<vector<int>> retval = vector<vector<int>>(x[0].size(), vector<int>(x.size()));
	int m = 0;

	for (int i = 0; i < x[0].size(); i++) {
		for (int k = 0; k < x.size(); k++) {
			retval[i][k] = x[k][i];
		}
	}
	return retval;
}

vector<vector<int>> Operations::Multiply(vector<vector<int>> x, vector<vector<int>> y) {
	if (MultiplyChecker(x, y)) {
		return vector<vector<int>>();
	}
	vector< vector<int>> retval = vector<vector<int>>(x.size(), vector<int>(y[0].size()));
	vector<vector<int>> temp = Transpose(y);
	for (int i = 0; i < retval.size(); i++) {
		for (int m = 0; m < retval[0].size(); m++) {
			for (int l = 0; l < x[i].size(); l++) { 

				retval[i][m] += x[i][l] * temp[m][l];
			}
		}
	}
	return retval;
}