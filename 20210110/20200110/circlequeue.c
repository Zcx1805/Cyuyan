#include<stdio.h>
#include<stdbool.h>
//利用不带头单链表(带尾节点)实现循环队列
//在逻辑上是环状
typedef struct{
	int* _data; //动态开辟的数组,仅仅用来存储数据
	int _head;  //头节点的位置
	int _rear;  //尾节点的位置
	int size;   //最大有效数字(可存放)
}circlequeue;

//创造并初始化
circlequeue* createinit(int size){
	circlequeue* cq = (circlequeue*)malloc(sizeof(circlequeue));
	//开辟的一个环
	cq->_data = (int*)malloc(sizeof(int)*size + 1);
	//开辟的数据存储空间
	cq->_head = cq->_rear = 0;//data[0];
	cq->size = size;
	return cq;
}

//判定满
bool isfull(circlequeue* cq){
	if ((cq->_rear + 1) % (cq->size + 1) == cq->_head){
		return true;
	}
	else{
		return false;
	}
}

//判空
bool isempty(circlequeue* cq){
	if (cq->_head == cq->_rear){
		return true;
	}
	else{
		return false;
	}
}

//入队列
bool pushqueue(circlequeue* cq, int val){
	if (isfull(cq)){
		return false;
	}
	cq->_data[cq->_rear++] = val;
	if (cq->_rear > (cq->size)){
		cq->_rear = 0;
		//在开辟的data为了避免越界并形成环
	}
	return true;
}

//出队列
bool popqueue(circlequeue* cq){
	if (isempty){
		return false;
	}
	cq->_head++;
	if (cq->_head > cq->size){
		cq->_head = 0;
		//仅仅为了满足成环
	}
	return true;
}

//返回头,尾元素
int queuehead(circlequeue* cq){
	return cq->_data[cq->_head];
}
int queuerear(circlequeue* cq){
	return cq->_data[cq->_rear];
}
//销毁
void distory(circlequeue* cq){
	free(cq->_data);
	free(cq);
}