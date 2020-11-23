#include <stdio.h>
int main()
{
	char arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//tofind表示要找的数字
	int tofind = 7;
	//数组最左边元素的下标
	int left = 0;
	//数组最右边元素的下标
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	//sizeof(arr)是计算arr的字节
	//sizeof(arr[0])是计算数组中第一个的字节
	//两者相除就是数组长度
	while (left <= right){
		int mid = (left + right) / 2;
		if (tofind > arr[mid]){
			//说明你要查找的数在mid 的右边，
			//因此需要向右递归查找
			left = mid + 1;
		}
		else if (tofind < arr[mid]){
			right = mid - 1;
		}
		else{
			printf("找到了，下标是：%d\n", mid);
			break;
		}
	}
	if (left>right){
		printf("找不到");
	}
	system("pause");
	return 0;
}
