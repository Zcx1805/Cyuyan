#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<stdlib.h>
//模拟实现strncat
char *Mystrncat( char* arr1,const  char* arr2, int n){
	char* end = arr1;
	assert(arr1);
	assert(arr2);
	//将arr2内容复制到arr1中n个
	
	while (*arr1 != '\0'){//没加解引用！wc
		arr1++;
	}
	while(n--){
		*arr1 = *arr2;
		arr1++;
		arr2++;
	}
	*arr1 = '\0';
	return end;

}
//模拟实现strncpy
char* Mystrncpy(char* arr1, const char* arr2, int n){
	assert(arr1);
	assert(arr2);
	char* p = arr1;
	for (int i = 0; i < n; i++){
		*arr1 = *arr2;
		arr1++;
		arr2++;
	}
	*arr1 = '\0';
	return p;
}

void bubbleSort(int arr[], int size) {//顺序
	for (int a = 0; a < size - 1; a++){//最多size-1轮比较
		for (int b = 0; b < size - 1 - a; b++){
			if (arr[b]>arr[b + 1]){
				int c = arr[b];
				arr[b] = arr[b + 1];
				arr[b + 1] = c;
			}
		}
	}
}

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
int findlone(int* arr1,int size){
	assert(arr1);
	bubbleSort(arr1, size);
	int *one = arr1;
	int* two = arr1 + 1;
	while (two){
		if (*one == *two){
			one += 2;
			two += 2;
		}
		else{
			return *one;
		}
	}
	return 0;

}
void test(){
	//char arr[32] = "I am a";
	//char arr1[] = " good student!";
	int arr3[5] = { 3,2,3,1,2 };
	printf("%d", findlone(arr3,5));
	
	//Mystrncat(arr, arr1, 10);
	//Mystrncpy(arr, arr1, 10);
	//printf("%s", arr);
}


int main(){
	//test();
	int *arr = (int*)malloc(5 * sizeof(int));
	int *arr1 = (int*)calloc(5, sizeof(int));
	system("pause");
	return 0;
}

