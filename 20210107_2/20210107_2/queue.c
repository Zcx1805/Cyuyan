#include<stdio.h>
//带头尾指针的单链表实现队列
typedef int Data;
typedef struct queuenode{
	Data data;
	struct queue* _next;
}queuenode;

typedef struct queue{
	queuenode* _start;
	queuenode* _end;
}queue;

void init(queue* qe){
	qe->_end = qe->_start = NULL;
}

queuenode* createqe(Data data){
	queuenode* node = (queuenode*)malloc(sizeof(queuenode));
	node->data = data;
	node->_next = NULL;
}

//入队(尾插)
void push(queue* qe, Data data){
	queuenode* newqueue=createqe(data);
	if (qe->_end == qe->_start == NULL){
		qe->_end = qe->_start = newqueue;
	}
	else{
		qe->_end->_next = newqueue;
		qe->_end = newqueue;
	}
}

//出队(头删)
void pop(queue* qe){
	if (qe->_end == NULL){
		return;
	}
	queuenode* next = qe->_start->_next;
	free(qe->_start);
	qe->_start = next;
	//删除之后是否为空表
	if (qe->_end == NULL){
		qe->_end = NULL;
		//避免end变为野指针
	}
}

//获取队头元素
int top(queue* qe){
	return qe->_start->data;
}

int last(queue* qe){
	return qe->_end->data;
}

//获取数量
int size(queue* qe){
	if (qe->_end == NULL){
		return 0;
	}
	int i = 0;
	queuenode* cur = qe->_start;
	while (cur){
		i++;
		cur = cur->_next;
	}
	return i;
}
