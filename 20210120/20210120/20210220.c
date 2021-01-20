#include<stdio.h>
#include<windows.h>
void swap(int* arr, int a, int b){
	int data = arr[a];
	arr[a] = arr[b];
	arr[b] = data;
}

void bubblesort1(int *arr, int size){
	for (int i = 0; i < size - 1; i++){
		for (int j = 0; j < size - 1 - i; j++){
			if (arr[j + 1]<arr[j]){
				swap(arr, j + 1, j);
			}
		}
	}
}
void bubblesort2(int *arr, int size){
	for (int i = 0; i < size - 1; i++){
		for (int j = size-1; j >0; j--){
			if (arr[j ]<arr[j-1]){
				swap(arr, j -1, j);
			}
		}
	}
}
void bubblesort3(int* arr, int size){
	int end = size;//end未排序区间尾
	int idx = 0;
	while (end>1){
		for (int j = 0; j < end-1; j++){
			if (arr[j + 1] < arr[j]){
				swap(arr, j + 1, j);
				idx = 1;//没有经过这个if说明已经有序，break了
			}
		}
		if (idx == 0){
			break;
		}
		end--;
	}
}
int partion(int* arr, int begin, int end){
	int start = begin;
	int key = arr[begin];
	while (end > begin){
		while (end>begin&&key<=arr[end]){
			end--;
		}
		while (begin < end&&key >= arr[begin]){
			begin++;
		}
		swap(arr, begin, end);
	}
	swap(arr, end, start);
	return end;
}

int three(int* arr,int start, int end){
	int mid = (end - start)/2 + start;
	if (arr[start] > arr[mid]){
		if (arr[end] < arr[mid]){
			return mid;//start   mind   end
		}
		else if (arr[end]>arr[start]){//end   start   mid
			return start;
		}
		else{
			return end;//start end  mid
		}
	}
	else{//mind  start  end
		//mind   end   start
		//end  mind  start
		if (arr[start] > arr[end]){
			return start;
		}
		else if (arr[mid] >arr[ end]){
			return end;
		}
		else{
			return mid;
		}
	}
}

void quicksort(int* arr, int begin, int end){
	int a=three(arr, begin, end);
	swap(arr, a, begin);
	if (begin >= end){
		return;
	}
	int b = partion(arr, begin, end);
	quicksort(arr, begin, b - 1);
	quicksort(arr, b + 1, end);
}



int main(){
	int arr[5] = { 3, 4, 5, 2, 1 };
	//int a=three(arr, 0, 4);
	//printf("%d", a);
	quicksort(arr, 0, 4);
	//bubblesort1(arr, 5);
	//bubblesort3(arr, 5);
	for (int i = 0; i < 5; i++){
		printf("%d", arr[i]);
	}
	system("pause");
	return 0;
}