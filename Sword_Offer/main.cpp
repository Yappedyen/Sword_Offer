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
	int i = 42;
	int* p1 = &i;
	*p1 = *p1 * *p1;
	cout << *p1 << endl;
	system("pause");
	return 0;
}