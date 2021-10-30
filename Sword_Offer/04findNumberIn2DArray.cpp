#include"functions.h"
//��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ����Ч�ĺ���������������һ����ά�����һ���������ж��������Ƿ��и�������


bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	int n = matrix.size();
	if (n == 0) return false;
	int m = matrix[0].size();
	int i = n - 1, j = 0;
	while (i >= 0 && j < m) {
		if (matrix[i][j] > target) --i;
		else if (matrix[i][j] < target) ++j;
		else return true;
	}
	return false;
}