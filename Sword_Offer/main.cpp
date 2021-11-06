#include<iostream>
#include<vector>
#include"functions.h"
#include<array>
using namespace std;


int main(){

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	Solution s;
	int out = s.findRepeatNumber(v);
	cout << out << endl;
	char q = 'a';
	char * w = &q;
	cout << sizeof(w) <<q<< endl;
	int arr[] = { 1,2,3,4,5,6 };
	cout << sizeof(arr) << endl;
	double dval = 0.0;
	bool flag = dval;
	cout << flag << endl;
	array<int, 10> a1 = { 0,1,2,3,4,5,6,7,8,9 };
	array<int, 10> a2 = { 0 };
	a2 = a1;
	for (const auto i : a1)
		cout << i << endl;
	for (auto it = a2.begin(); it != a2.end(); it++)
		cout << *it;
	system("pause");
	return 0;
}