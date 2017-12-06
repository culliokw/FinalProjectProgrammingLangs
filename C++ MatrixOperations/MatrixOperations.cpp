#include <iostream>
#include <vector>
#include "Operations.h"
using namespace std;
int main() {
	static const int arr[] = {{16},{2},{77},{29}};

	vector<vector<int>> vec(2, vector<int>(4));
	
	for (int j = 0; j < vec[0].size(); j++) {
		for (int k = 0; k < vec.size(); k++) {
			(vec[k])[j] = arr[j];
			//vec.push_back(vector <int>());
			//vec[i].push_back(arr[j]);
		}
		
	}
	vec[1][3] = 34;
	Operations m = Operations();
	vector<vector<int>> retval = m.Add(vec, vec);
	vector<vector<int>> g = m.Transpose(vec);
	vector<vector<int>> j = m.Multiply(vec, m.Transpose(vec));
	/*for (int i = 0; i < retval.size(); i++) {
		for (int k = 0; k < retval[i].size(); k++) {
			cout << "Position" << " " << k << " " << retval[i][k] << endl;
		}
	}*/
	/*for (int i = 0; i < g.size(); i++) {
		for (int k = 0; k < g[i].size(); k++) {
			cout << "Position" << " " << k << " " << g[i][k] << endl;
		}
	}*/
	for (int i = 0; i < j.size(); i++) {
		for (int k = 0; k < j[i].size(); k++) {
			cout << "Position" << " " << k << " " << j[i][k] << endl;
		}
	}

}