#include"functions.h"


//��дһ��������������һ���޷����������Զ����ƴ�����ʽ��������������Ʊ��ʽ������λ��Ϊ '1' �ĸ�����Ҳ����Ϊ ��������).����
int hammingWeight(uint32_t n) {
	int ret = 0;
	for (int i = 0; i < 32; ++i) {
		if (n & (1 << i)) {
			++ret;
		}
	}
	return ret;


	int cout = 0;
	while (n) {
		n &= n - 1;
		++cout;
	}
	return cout;
}