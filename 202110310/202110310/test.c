#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<stdlib.h>
//ģ��ʵ��strncat
char *Mystrncat( char* arr1,const  char* arr2, int n){
	char* end = arr1;
	assert(arr1);
	assert(arr2);
	//��arr2���ݸ��Ƶ�arr1��n��
	
	while (*arr1 != '\0'){//û�ӽ����ã�wc
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
//ģ��ʵ��strncpy
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

void bubbleSort(int arr[], int size) {//˳��
	for (int a = 0; a < size - 1; a++){//���size-1�ֱȽ�
		for (int b = 0; b < size - 1 - a; b++){
			if (arr[b]>arr[b + 1]){
				int c = arr[b];
				arr[b] = arr[b + 1];
				arr[b + 1] = c;
			}
		}
	}
}

//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�
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

