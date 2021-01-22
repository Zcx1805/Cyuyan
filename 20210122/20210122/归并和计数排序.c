#include<stdio.h>
#include<windows.h>
//一次归并排序的过程
void merge(int* arr, int begin, int mid, int end,int* tmp){
	//begin mid     mid+1   end
	int idx = begin;
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	while (begin1 <= end1&&begin2<=end2){
		if (arr[begin1] < arr[begin2]){
			tmp[idx++] = arr[begin1++];
		}
		else{
			tmp[idx++] = arr[begin2++];
		}
	}
	if (begin1<=end1){
		memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1 + 1));
	}
	if (begin2 <= end2){
		memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2 + 1));
	}
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));

}
//递归过程
void _mergesort(int *arr, int begin, int end,int* tmp){
	int mid = (end - begin) / 2 + begin;
	if (begin >= end){
		return;
	}
	_mergesort(arr, begin, mid, tmp);
	_mergesort(arr, mid + 1, end, tmp);
	merge(arr, begin, mid, end, tmp);
}
//开辟辅助空间过程
void mergesort(int* arr, int size){
	int* tmp = (int*)malloc(sizeof(int)*size);
	_mergesort(arr, 0, size - 1, tmp);
	free(tmp);
}

//非递归实现
void mergesort1(int* arr, int size){
	int* tmp = (int*)malloc(sizeof(int)*size);
	int step = 1;
	while (step < size){
		for (int idx = 0; idx < size; idx += 2 * step){
			int begin = idx;
			int mid = idx + step - 1;
			if (mid >= size - 1){
				continue;//先放这,等步长起来了就可算到不完整的右边序列
			}
			int end = idx + 2*step - 1;
			if (end>=size){
				end = size - 1;
			}
			merge(arr, begin, mid,end,tmp);
		}
		step = step * 2;
	}
}


//计数排序
void countsort(int* arr, int size){
	int max = 0;
	int min = 0;
	for (int i = 0; i < size; i++){
		if (arr[i]>max){
			max = arr[i];
		}
		if (arr[i] < min){
			min = arr[i];
		}
	}
	int tmpsize = max - min + 1;
	int* tmp = (int*)calloc(tmpsize,sizeof(int));
	for (int i = 0; i < size; i++){
		tmp[arr[i] - min]++;
	}
	int idx = 0;
	for (int i = 0; i < tmpsize; i++){
		while (tmp[i]--){
			arr[idx++] = i + min;
		}
	}
	free(tmp);

}

int main(){
	int arr[10] = { 3, 4, 5, 2, 6,8,9,7,1 };
	//mergesort1(arr, 9);
	countsort(arr, 9);
	for (int i = 0; i < 9; i++){
		printf("%d", arr[i]);
	}
	system("pause");
	return 0;
}