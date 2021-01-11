#include<stdio.h>
#include<stdbool.h>
//���ò���ͷ������(��β�ڵ�)ʵ��ѭ������
//���߼����ǻ�״
typedef struct{
	int* _data; //��̬���ٵ�����,���������洢����
	int _head;  //ͷ�ڵ��λ��
	int _rear;  //β�ڵ��λ��
	int size;   //�����Ч����(�ɴ��)
}circlequeue;

//���첢��ʼ��
circlequeue* createinit(int size){
	circlequeue* cq = (circlequeue*)malloc(sizeof(circlequeue));
	//���ٵ�һ����
	cq->_data = (int*)malloc(sizeof(int)*size + 1);
	//���ٵ����ݴ洢�ռ�
	cq->_head = cq->_rear = 0;//data[0];
	cq->size = size;
	return cq;
}

//�ж���
bool isfull(circlequeue* cq){
	if ((cq->_rear + 1) % (cq->size + 1) == cq->_head){
		return true;
	}
	else{
		return false;
	}
}

//�п�
bool isempty(circlequeue* cq){
	if (cq->_head == cq->_rear){
		return true;
	}
	else{
		return false;
	}
}

//�����
bool pushqueue(circlequeue* cq, int val){
	if (isfull(cq)){
		return false;
	}
	cq->_data[cq->_rear++] = val;
	if (cq->_rear > (cq->size)){
		cq->_rear = 0;
		//�ڿ��ٵ�dataΪ�˱���Խ�粢�γɻ�
	}
	return true;
}

//������
bool popqueue(circlequeue* cq){
	if (isempty){
		return false;
	}
	cq->_head++;
	if (cq->_head > cq->size){
		cq->_head = 0;
		//����Ϊ������ɻ�
	}
	return true;
}

//����ͷ,βԪ��
int queuehead(circlequeue* cq){
	return cq->_data[cq->_head];
}
int queuerear(circlequeue* cq){
	return cq->_data[cq->_rear];
}
//����
void distory(circlequeue* cq){
	free(cq->_data);
	free(cq);
}