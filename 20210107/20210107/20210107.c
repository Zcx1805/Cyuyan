#define N 10
#include<stdio.h>
typedef int Data;
typedef struct lists{//˳�����������
	Data* _data;//��̬��������ֻ��֪������ĵ�ַ
	size_t _size;
	size_t _capacity;
}lists;

typedef struct lists2{
	Data _data[N];
	size_t _size;
	size_t _capacity;
}lists2;


void init(lists* list){//˳����ʼ��
	list->_data = NULL;
	list->_capacity = list->_size = 0;
}

void checkcapacity(lists* list){
	if (list == NULL){
		return;
	}
	if (list->_capacity == list->_size){//��ЧԪ��=���Ԫ�ؾ�����
		int newcapacity = list->_capacity == 0 ? 1 : list->_capacity * 2;
		//���_capacity=0˵����������,��1���ռ�,���ǵĻ���2��

		//������realloc���������(free)��3��		
		//list->_data = (Data*)realloc(list->_data, sizeof(Data)*newcapacity);
		
		Data* newdata = (Data*)malloc(sizeof(Data)*newcapacity);
		//�޸Ķ�̬���ٵ�data���͵Ĵ�С
		memcpy(newdata, list->_data, sizeof(Data)*list->_size);
		//����Ч�����ݷ����µ�����
		free(list->_data);
		list->_data = newdata;
		list->_capacity = newcapacity;
	}
}

//β��
void weicha(lists* list,Data data){
	checkcapacity(list);
	list->_data[list->_size] = data;
	++list->_size;
}

//βɾ
void weishan(lists* list){
	if (list == NULL||list->_size==0){
		return;
	}
	if (list->_size > 0){
		list->_size--;
	}
}

//ͷ��
void toucha(lists* list,Data data){
	if (list == NULL){
		return;
	}
	checkcapacity(list);
	int end = list->_size;//ȫ�����λ��
	while(end > 0){
		list->_data[end] = list->_data[end - 1];
		--end;
	}
	list->_data[0] = data;
	list->_size++;
}

//ͷɾ
void toushan(lists* list){
	if (list == NULL || list->_size == 0){
		return;
	}
	int i = 1;//�ӵ�һ����ʼ��ǰ�ƶ�һ��
	while (i < list->_size){
		list->_data[i - 1] = list->_data[i];
		i++;
	}
	list->_size--;
}

//������λ��(pos)λ�ò���
//˼·��[pos,end)���λ��,��pos��������
void insert(lists* list, int pos, Data data){
	if (list == NULL){
		return;
	}
	if (pos >= 0 && pos < list->_size){
		checkcapacity(list);
		int end = list->_size;//endΪ��,���һ����data[end-1]
		if (end > pos){//��Ҫ�ƶ�����[pos,end)
			list->_data[end] = list->_data[end - 1];
			end--;
		}
		list->_data[pos] = data;
		list->_size++;
	}
}

//������(pos)λ��ɾ��
//˼·��(pos,size)��ǰ��һ��
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

//�鿴��������
void size(lists* list){
	if (list == NULL){
		return 0;
	}
	else{
		return list->_size;
	}
}

//����ĳ����
void find(lists* list, int a){
	for (int i = 0; i < size; i++){
		if (list->_data[i] == a){
			return i;
		}
	}
	return -1;
}

//����˳���
void destory(lists* list){
	if (list){//��������
		if (list->_data){//���������
			free(list->_data);
			list->_data = NULL;
		}
	}
}
