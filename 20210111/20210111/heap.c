#include<stdio.h>
#include<stdbool.h>
//堆的实现和基本操作
//利用顺序表实现的二叉树堆
typedef int Data;
typedef struct heap{
	Data* _data;
	int _size;
	int _capacity;
}heap;

//堆的初始化
void initheap(heap* hp){
	if (hp->_data == NULL){
		return;
	}
	hp->_capacity = hp->_size = 0;
	hp->_data = NULL;
}

void checkcapacity(heap* hp){
	if (hp->_capacity == hp->_size){
		int newcapacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		Data* newdata = (Data*)malloc(sizeof(Data)*newcapacity);
		hp->_data = newdata;
		hp->_capacity = newcapacity;
	}
}

//小堆
//向上调整(小数字向上走)
void shiftup(Data* data, int size, int a){
	int parent = (a - 1) / 2;//找到父节点的下标(0开始的)
	while (a){
		if (data[a] < data[parent]){
			int tmp = data[a];
			data[a] = data[parent];
			data[parent] = tmp;
			a = parent;
			parent = (a - 1) / 2;
		}
		else{
			break;
		}
	}
}

//向下调整
void shiftdown(int* data, int size, int a){
	int child = a * 2 + 1;
	while (child < size){
		if (child + 1 < size&&data[child + 1] < data[child]){
			child++;
		}
		if (data[a]>data[child]){
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

//小堆放入一个数据(顺序表尾插->向上调整)
void push(heap* hp, Data data){
	if (hp->_data == NULL){
		return;
	}
	checkcapacity(hp);
	hp->_data[hp->_size - 1] = data;
	shiftup(hp->_data, hp->_size, hp->_size - 1);
}

//删除堆顶(和最后一个交换后尾删,0向下调整)
void pop(heap* hp){
	if (hp->_size > 0){
		int tmp = hp->_data[0];
		hp->_data[0] = hp->_data[hp->_size - 1];
		hp->_data[hp->_size - 1] = tmp;
		hp->_size--;
		shiftup(hp->_data, hp->_size, 0);
	}
}

//获取堆顶
Data gettop(heap* hp){
	if (hp->_data == NULL){
		return;
	}
	return hp->_data[0];
}

//判空
bool getempty(heap* hp){
	if (hp->_size = NULL || hp == NULL){
		return false;
	}
	return true;
}

//堆的应用之---打印一个不规则数组的前n个最小数
//打印前n个最小数字
void ntopprint(int* arr, int size, int n){
	heap* hp;
	initheap(hp);
	for (int i = 0; i < size; i++){
		push(hp, arr[i]);
	}//建堆

	for (int i = 0; i < n; i++){
		printf("%d", gettop(hp));
		pop(hp);
	}
}


