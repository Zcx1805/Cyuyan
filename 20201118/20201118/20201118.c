#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#include<assert.h>

int cmp1(const void* a, const void* b)
{
	assert(a);
	assert(b);
	return (*(unsigned char *)a - *(unsigned char *)b);
}
int cmp2(const void* a, const void* b)
{
	assert(a);
	assert(b);
	return (*(unsigned int *)a - *(unsigned int *)b);
}

//void bubblesort(int arr[],int size){//´íÎó´úÂë
//	//(a-size]ÒÑÅÅĞò
//	//(b-a)´ıÅÅĞò
//	int a = size - 1;
//	int b = 0;
//	for ( a ; ????; a--){
//		for (b ; b < a; b++){
//			if (arr[b]>arr[b + 1]){
//				int c = arr[b];
//				arr[b] = arr[b + 1];
//				arr[b + 1] = c;
//			}
//		}
//	}
//}
//typedef int(*Cmp)(int a, int b);
//void bubblesort(int arr[], int size,Cmp cmp) {//Ë³Ğò
//	for (int a = 0; a < size - 1; a++){//×î¶àsize-1ÂÖ±È½Ï
//		for (int b = 0; b < size - 1 - a; b++){
//			if (cmp(arr[b], arr[b+1]) == 1) {
//				int c = arr[b];
//				arr[b] = arr[b + 1];
//				arr[b + 1] = c;
//			}
//		}
//	}
//}
//int less(int a, int b) {
//	if (a == b) {
//		return 0;
//	}
//	if (a < b) {
//		return -1;
//	}
//	return 1;
//}

int main(){
	char arr1[] = "acdb";
	int arr2[4] = { 2, 4, 1, 3 };
	qsort(arr1, 4, sizeof(char), cmp1);
	qsort(arr2, 4, sizeof(int), cmp2);
	for (int i = 0; i < 4; i++)
	{
		printf("%c ", arr1[i]);
	}
	printf("\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");

	/*int arr[] = { 8, 3, 5, 2, 6 };
	bubblesort(arr,5,less);
	for (int i = 0; i < 5; i++){
		printf("%d ", arr[i]);
	}*/




	system("pause");
	return 0;

}