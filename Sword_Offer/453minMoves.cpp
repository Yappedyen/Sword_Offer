#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。返回让数组所有元素相等的最小操作次数。
//思路和算法
//
//因为只需要找出让数组所有元素相等的最小操作次数，所以我们不需要考虑数组中各个元素的绝对大小，即不需要真正算出数组中所有元素相等时的元素值，只需要考虑数组中元素相对大小的变化即可。
//
//因此，每次操作既可以理解为使n - 1个元素增加1，也可以理解使1个元素减少1(相对而言)。显然，后者更利于我们的计算。
//
//于是，要计算让数组中所有元素相等的操作数，我们只需要计算将数组中所有元素都减少到数组中元素最小值所需的操作数，即计算

//在实现中，为避免溢出，我们可以逐个累加每个元素与数组中元素最小值的差，即计算
//sum(nums[i]-min(nums))

//时间复杂度：O(n)
//空间复杂度：O(1)

int minMoves(vector<int>& nums) {
	//int n = size(nums);
	//int i = 0;
	//sort(nums.begin(), nums.end());
	//while (nums[0] != nums[n - 1]) {
	//	for (int j = 0; j < n-1; j++) {
	//		nums[j]++;
	//	}
	//	i++;
	//}
	//return i;
	int min_nums = *min_element(nums.begin(), nums.end());
	int res = 0;
	for (int num : nums) {
		res += num - min_nums;
	}
	return res;
}