#include<stdio.h>
#include<windows.h>
void swap(int* arr, int a, int b){
	int data = arr[a];
	arr[a] = arr[b];
	arr[b] = data;
}
int partion1(int* arr, int begin, int end){
	int a = three(arr, begin, end);
	swap(arr, a, begin);
	int start = begin;
	int key = arr[begin];
	while (end > begin){
		while (end>begin&&key <= arr[end]){
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

int partion2(int* arr, int begin, int end){
	int a = three(arr, begin, end);
	swap(arr, a, begin);
	int key = arr[begin];
	while (end > begin){
		while (end>begin&&key <= arr[end]){
			end--;	
		}
		arr[begin] = arr[end];
		while (begin < end&&key >= arr[begin]){
			begin++;
		}
		arr[end] = arr[begin];
		
	}
	arr[begin] = key;
	return end;
}

int partion3(int* arr, int begin, int end){
	int a = three(arr, begin, end);
	swap(arr, a, begin);
	int prev = begin;
	int cur = begin + 1;
	int key = arr[begin];
	while (cur <= end){
		if (arr[cur] < key&&++prev != cur){
			swap(arr, prev, cur);
		}
		++cur;
	}
	swap(arr, prev, begin);
	return prev;
}



int three(int* arr, int start, int end){
	int mid = (end - start) / 2 + start;
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
		else if (arr[mid] >arr[end]){
			return end;
		}
		else{
			return mid;
		}
	}
}
//递归
void quicksort(int* arr, int begin, int end){
	
	if (begin >= end){
		return;
	}
	int b = partion(arr, begin, end);
	quicksort(arr, begin, b - 1);
	quicksort(arr, b + 1, end);
}

//非递归顺序表实现
void quicksort2(int* arr, int size){
	seqList sq;
	initseqList(&sq);
	push(sq, size - 1);
	push(sq, 0);
	while (sq){//非空
		//取出一个区间
		int left = seqListback(&sq);//取尾元素
		pop(&sq);
		int right = seqListback(&sq);
		pop(&sq);
		//划分区间
		int div = partion1(arr, left, right);
		if (left < div - 1){
			push(&sq, div - 1);
			push(&sq, left);
		}
		if (div + 1 < right){
			push(&sq, right);
			push(&sq, div + 1);
		}
	}
}

//非递归队列实现
void quicksort2(int* arr, int size){
	Queuelist qe;
	initsqueuelist(&qe);
	push(qe, 0);
	push(qe, size - 1);
	while (qe){//非空
		//取出一个区间
		int left = queuetop(&qe);//取头元素
		pop(&qe);
		int right = seqListback(&qe);
		pop(&qe);
		//划分区间
		int div = partion1(arr, left, right);
		if (left < div - 1){
			push(&qe, left);
			push(&qe, div-1);
		}
		if (div + 1 < right){
			push(&qe, div+1);
			push(&qe, right);
		}
	}
}