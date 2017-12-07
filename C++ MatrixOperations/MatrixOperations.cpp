#include <iostream>
#include <vector>
#include <algorithm>
#include "Operations.h"
using namespace std;

int main() {
	srand(0);
	//Play field to test the matrix operations
	vector<vector<int>> x_10 = generateRandomMatrix(10, 10);
	vector<vector<int>> y_10 = generateRandomMatrix(10, 10);

	vector<vector<int>> x_50 = generateRandomMatrix(50, 50);
	vector<vector<int>> y_50 = generateRandomMatrix(100, 50);

	vector<vector<int>> x_100 = generateRandomMatrix(100, 100);
	vector<vector<int>> y_100 = generateRandomMatrix(100, 100);

	Operations a = Operations();

	/*Test Adding*/
	// printMatrix(x_10);
	// printMatrix(y_10);
	// printMatrix(a.Add(x_10, y_10));

	/*Test Transpose*/
	// printMatrix(x_50);
	// printMatrix(a.Transpose(x_50));

	/*Test Multiplication*/
	// printMatrix(x_10);
	// printMatrix(y_10);
	// printMatrix(a.Multiply(x_10, y_10));

}

vector<vector<int>> generateRandomMatrix(int x, int y) {
	vector<vector<int>> ret_val = vector<vector<int>>(x, vector<int>(y));
	for (int i = 0; i < ret_val.size(); i++ ) {
		generate(ret_val[0].begin(), ret_val[0].end(), rand);
	}
	return ret_val;
}

void printMatrix(vector<vector<int>> x) {
	for (int i = 0; i < x.size(); i++) {
		cout << "[ ";
		for (int j = 0; x[i].size(); j++) {
			cout << x[i][j] << ", ";
		}
		cout << endl;
	}
}