#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#define size 5

//void bubbleSort1(int arr[],int size) {//˳��
//	for (int a = 0; a < size-1; a++){//���size-1�ֱȽ�
//		for (int b = 0; b < size - 1 - a; b++){
//			if (arr[b ]>arr[b+1]){
//				int c = arr[b ];
//				arr[b] = arr[b+1];
//				arr[b+1] = c;
//			}
//		}
//	}	
//}
//
//void bubbleSort2(int arr[], int size) {//����
//	for (int a = 0; a < size-1; a++) {
//		for (int b = size - 1; b > a; b--) {
//			if (arr[b - 1] > arr[b]) {
//				int tmp = arr[b - 1];
//				arr[b - 1] = arr[b];
//				arr[b] = tmp;
//			}
//		}
//	}
//}

int init(int arr[size]){
	for (int a = 0; a < size; a++){
		 arr[a]=0;
	}
}
char reverse(int arr[size]){
	int a = 0;
	int b = size-1;
	for (; a < size/2,b>size/2; a++,b--){
		int c = arr[a];
		arr[a] = arr[b];
		arr[b] = c;
	}
}

char reverse1(int arr[size]){
	for (int a = size - 1; a >= 0; a--){
		printf("%d ", arr[a]);
	}
}
int main(){
	//int arr[] = { 2, 5, 8, 3 ,7, 9};
	//bubbleSort2(arr,sizeof(arr)/sizeof (arr[0]));
	//for (int a = 0; a < sizeof(arr) / sizeof (arr[0]); a++){
	//	printf(" %d", arr[a]);
	//	//2 5 8 3 7 9--2 3 5 7 8 9;
	//}

	/*����һ���������飬��ɶ�����Ĳ���
		ʵ�ֺ���init() ��ʼ������Ϊȫ0
		ʵ��print()  ��ӡ�����ÿ��Ԫ��
		ʵ��reverse()  �����������Ԫ�ص����á�
		Ҫ���Լ�������Ϻ����Ĳ���������ֵ��*/
	/*int arr[size];
	init(arr);
	for (int a = 0; a < size; a++){
		printf("%d ", arr[a]);
	}*/
	
	int arr1[size] = { 1, 2, 3,4,5 };
	reverse(arr1);
	for (int i = 0; i < size; i++){
		printf("%d ", arr1[i]);
	}


	//��������
	/*int arr1[] = { 1, 2, 3 };
	int arr2[] = { 4, 5, 6 };
	int size = sizeof(arr1) / sizeof(arr1[0]);
	for (int a = 0; a < size; a++){
		int b = arr1[a];
		arr1[a] = arr2[a];
		arr2[a] = b;
	}
	for (int n = 0; n < size; n++){
		printf("arr1=");
		printf("%d ", arr1[n]);	
	}
	printf("\n");
	for (int n = 0; n < size; n++){
		printf("arr2=");
		printf("%d ", arr2[n]);
	}*/

	system("pause");
	return 0;
}