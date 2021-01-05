#include<stdio.h>
#include<windows.h>
int removeDuplicates(int arr[], int numsSize){//剔除重复元素返回个数
	if (numsSize <= 1){
		return numsSize;
	}
	int i = 0;
	int j = 1;
	int idx = 0;
	while (j < numsSize){
		arr[idx] = arr[i];
		idx++;
		if (arr[i] == arr[j]){
			while (j < numsSize&&arr[i] == arr[j]){
				j++;
			}
			i = j;
			j++;
		}
		else{
			++i;
			++j;
		}
	}
	if (i < numsSize){
		arr[idx++] = arr[i];
	}
	return idx;
}





int main(){
	/*int arr[] = { 0, 0, 1, 1, 1, 2, 2, 3 };
	int a = removeDuplicates(arr, 8);
	printf("%d", a);*/

	system("pause");
	return 0;

}