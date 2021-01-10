#include<stdio.h>
//��ͷβָ��ĵ�����ʵ�ֶ���
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

//���(β��)
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

//����(ͷɾ)
void pop(queue* qe){
	if (qe->_end == NULL){
		return;
	}
	queuenode* next = qe->_start->_next;
	free(qe->_start);
	qe->_start = next;
	//ɾ��֮���Ƿ�Ϊ�ձ�
	if (qe->_end == NULL){
		qe->_end = NULL;
		//����end��ΪҰָ��
	}
}

//��ȡ��ͷԪ��
int top(queue* qe){
	return qe->_start->data;
}

int last(queue* qe){
	return qe->_end->data;
}

//��ȡ����
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
