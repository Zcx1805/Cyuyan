#include<stdio.h>
#include<stdlib.h>
int missingNumber(int* nums, int numsSize){

	int size = numsSize;
	int sum = 0;
	int sum1 = 0;
	for (int a = 0; a < size; a++){
		sum = sum + nums[a];
	}
	for (int i = 0; i < size; i++){
		sum1 = sum + i;
	}
	int data = sum1 - sum;
	return data;
	printf("%d", data); 
}
int main(){
	//数组nums包含从0到n的所有整数，但其中缺了一个。请
	//编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
	/*int arr[3] = {0, 1, 3};
	int size = sizeof(arr)/sizeof(arr[0]);
	int sum = 0;
	int sum1 = 0;
	for (int a = 0; a < size; a++){
		sum = sum + arr[a];
	}
	for (int i = 0; i < size; i++){
		sum1 = sum + i;
	}
	int data = sum1 - sum;
	printf("%d", data);*/
	int arr[3] = { 0, 1, 3 };
	missingNumber(arr[3], 3);

	system("pause");
	return 0;
}