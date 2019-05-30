#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <vector>
#include <time.h>

using namespace std;

int main(){
	vector<int> test;

	for(int i = 0; i < 10; ++i){
		test.push_back(i);
	}

	for(unsigned int i = 0; i < test.size(); ++i){
		cout << test[i] << endl;
	}

	test.erase(test.begin() + 5);

	for(unsigned int i = 0; i < test.size(); ++i){
		cout << test[i] << endl;
	}

	cout << test.size() << endl;
}