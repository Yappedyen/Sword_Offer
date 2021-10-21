#include<iostream>
#include<vector>
#include"functions.h"
using namespace std;


int main(){

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	Solution s;
	int out = s.findRepeatNumber(v);
	cout << out << endl;
	system("pause");
	return 0;
}