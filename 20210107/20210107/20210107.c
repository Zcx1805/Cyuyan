#define N 10
#include<stdio.h>
typedef int Data;
typedef struct lists{//顺序表数据类型
	Data* _data;//动态开辟所以只需知道数组的地址
	size_t _size;
	size_t _capacity;
}lists;

typedef struct lists2{
	Data _data[N];
	size_t _size;
	size_t _capacity;
}lists2;


void init(lists* list){//顺序表初始化
	list->_data = NULL;
	list->_capacity = list->_size = 0;
}

void checkcapacity(lists* list){
	if (list == NULL){
		return;
	}
	if (list->_capacity == list->_size){//有效元素=最大元素就满了
		int newcapacity = list->_capacity == 0 ? 1 : list->_capacity * 2;
		//如果_capacity=0说明是新链表,给1个空间,不是的话开2倍

		//可以用realloc代表下面的(free)外3行		
		//list->_data = (Data*)realloc(list->_data, sizeof(Data)*newcapacity);
		
		Data* newdata = (Data*)malloc(sizeof(Data)*newcapacity);
		//修改动态开辟的data类型的大小
		memcpy(newdata, list->_data, sizeof(Data)*list->_size);
		//将有效地数据放入新的数据
		free(list->_data);
		list->_data = newdata;
		list->_capacity = newcapacity;
	}
}

//尾插
void weicha(lists* list,Data data){
	checkcapacity(list);
	list->_data[list->_size] = data;
	++list->_size;
}

//尾删
void weishan(lists* list){
	if (list == NULL||list->_size==0){
		return;
	}
	if (list->_size > 0){
		list->_size--;
	}
}

//头插
void toucha(lists* list,Data data){
	if (list == NULL){
		return;
	}
	checkcapacity(list);
	int end = list->_size;//全部向后位移
	while(end > 0){
		list->_data[end] = list->_data[end - 1];
		--end;
	}
	list->_data[0] = data;
	list->_size++;
}

//头删
void toushan(lists* list){
	if (list == NULL || list->_size == 0){
		return;
	}
	int i = 1;//从第一个开始都前移动一个
	while (i < list->_size){
		list->_data[i - 1] = list->_data[i];
		i++;
	}
	list->_size--;
}

//在任意位置(pos)位置插入
//思路是[pos,end)向后位移,在pos插入数据
void insert(lists* list, int pos, Data data){
	if (list == NULL){
		return;
	}
	if (pos >= 0 && pos < list->_size){
		checkcapacity(list);
		int end = list->_size;//end为空,最后一个在data[end-1]
		if (end > pos){//需要移动的是[pos,end)
			list->_data[end] = list->_data[end - 1];
			end--;
		}
		list->_data[pos] = data;
		list->_size++;
	}
}

//在任意(pos)位置删除
//思路是(pos,size)的前移一个
void erase(lists* list,int pos){
	if (list == NULL || list->_size == 0){
		return;
	}
	if (pos >= 0 && pos < list->_size){
		int start = pos + 1;
		while (start < list->_size){
			list->_data[start - 1] = list->_data[start];
			start++;
		}
		list->_size--;
	}
}

//查看数据数量
void size(lists* list){
	if (list == NULL){
		return 0;
	}
	else{
		return list->_size;
	}
}

//查找某数据
void find(lists* list, int a){
	for (int i = 0; i < size; i++){
		if (list->_data[i] == a){
			return i;
		}
	}
	return -1;
}

//销毁顺序表
void destory(lists* list){
	if (list){//如果表存在
		if (list->_data){//如果有数据
			free(list->_data);
			list->_data = NULL;
		}
	}
}
