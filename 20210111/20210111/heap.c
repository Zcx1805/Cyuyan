#include<stdio.h>
#include<stdbool.h>
//�ѵ�ʵ�ֺͻ�������
//����˳���ʵ�ֵĶ�������
typedef int Data;
typedef struct heap{
	Data* _data;
	int _size;
	int _capacity;
}heap;

//�ѵĳ�ʼ��
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

//С��
//���ϵ���(С����������)
void shiftup(Data* data, int size, int a){
	int parent = (a - 1) / 2;//�ҵ����ڵ���±�(0��ʼ��)
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

//���µ���
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

//С�ѷ���һ������(˳���β��->���ϵ���)
void push(heap* hp, Data data){
	if (hp->_data == NULL){
		return;
	}
	checkcapacity(hp);
	hp->_data[hp->_size - 1] = data;
	shiftup(hp->_data, hp->_size, hp->_size - 1);
}

//ɾ���Ѷ�(�����һ��������βɾ,0���µ���)
void pop(heap* hp){
	if (hp->_size > 0){
		int tmp = hp->_data[0];
		hp->_data[0] = hp->_data[hp->_size - 1];
		hp->_data[hp->_size - 1] = tmp;
		hp->_size--;
		shiftup(hp->_data, hp->_size, 0);
	}
}

//��ȡ�Ѷ�
Data gettop(heap* hp){
	if (hp->_data == NULL){
		return;
	}
	return hp->_data[0];
}

//�п�
bool getempty(heap* hp){
	if (hp->_size = NULL || hp == NULL){
		return false;
	}
	return true;
}

//�ѵ�Ӧ��֮---��ӡһ�������������ǰn����С��
//��ӡǰn����С����
void ntopprint(int* arr, int size, int n){
	heap* hp;
	initheap(hp);
	for (int i = 0; i < size; i++){
		push(hp, arr[i]);
	}//����

	for (int i = 0; i < n; i++){
		printf("%d", gettop(hp));
		pop(hp);
	}
}


