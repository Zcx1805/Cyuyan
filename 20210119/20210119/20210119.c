#include<windows.h>
#include<stdio.h>
typedef int Data;
typedef struct heap{
	Data* _data;
	int _size;
	int _capacity;
}heap;


//选择排序
void selectsort(int* arr, int size){
	for (int i = 0; i < size; i++){
		int idx = i;
		for (int j = i+1; j < size; j++){
			if (arr[j] < arr[idx]){
				int tmp = arr[j];
				arr[j] = arr[idx];
				arr[idx] = tmp;
			}
		}	
	}
}

//选择排序2,同时记录前后
void selectsort2(int* arr, int size){
	
		int idx = 0;
		int end = size - 1;
		while (idx < end){
			for (int j = idx+1; j < end; j++){
				if (arr[j] < arr[idx]){
					int tmp = arr[j];
					arr[j] = arr[idx];
					arr[idx] = tmp;
				}
				if (arr[j]>arr[end]){
					int tmp2 = arr[end];
					arr[end] = arr[j];
					arr[j] = tmp2;
				}
			}
			idx++;
			end--;
		}
		
	


}


//插入排序
void insert(int* arr,int size){
	for (int i = 0; i < size; i++){//用来遍历每一个
		int end = i-1;//排过序的最后一个
		int data = arr[i];
		while (arr[end]&&data < arr[end]){
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = data;
	}
}
//希尔排序
void shellsort(int* arr, int size){
	int gap = size;
	while (gap > 1){
		gap = gap / 3 + 1;
		for (int i = gap; i < size; i++){
			int end = i - gap;
			int data = arr[i];
			while (arr[end]>data){
				arr[end + gap] = arr[end];
				end = end - gap;
			}
			arr[end + gap] = data;
		}
	}
}

void shiftdown(int* data, int size, int a){
	int child = a * 2 + 1;
	while (child < size){
		if (child + 1 < size&&data[child + 1] > data[child]){
			child++;
		}
		if (data[child]>data[a]){
			int tmp = data[a];
			data[a] = data[child];
			data[child] = tmp;
			a = child;
			child = a * 2 + 1;
		}
		else{
			break;
		}
	}
}
//堆排序
void heapsort(int* arr, int size){
	for (int i = (size - 2) / 2; i >=0; i--){
		shiftdown(arr,size,i);
	}//完成建堆
	//下一步是
	int end = size - 1;
	while (end>0){
		
		int tmp = arr[end];
		arr[end] = arr[0];
		arr[0] = tmp;
		shiftdown(arr, end, 0);
		
		--end;
	}
}
int main(){
	int arr[5] = { 2, 5, 1, 3, 4 }; 
	bubbleSort(arr, 5);
	//selectsort(arr, 5);
	//heapsort(arr, 5);
	//shellsort(arr, 5);
	//change(arr, 5);
	//insert(arr, 5);
	for (int i = 0; i < 5; i++){
		printf("%d", arr[i]);
	}
	system("pause");
	return 0;
}