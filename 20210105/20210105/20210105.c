#include<stdio.h>
#include<windows.h>
typedef int Data;        //��������
typedef struct lists{    //�Զ��嵥����ṹ��
	Data _data;
	struct lists* _next;
}lists;

//�Զ���ͷ���
typedef struct firstlist{//�����ҵ�����������,�����ͷ��ʼ
	struct lists* _head;
}firstlist;

//�ṹ���ʼ��
void init(firstlist* flist){
	if (flist == NULL){
		return flist;
	}
	flist->_head = NULL;   //������Ϊ��
}

lists* xinzeng(Data _data){//��һ�����ݴ���һ��������,����������ĵ�ַ
	lists* newlist = (lists*)malloc(sizeof(lists));
	newlist->_data = _data;
	newlist->_next = NULL;
	return newlist;
}

//β��
void weicha(firstlist* lit,Data data){//��dataβ�嵽lit������
	//��firstlist����Ϊ֪��ͷ����ַ�Ϳ��Բ���������
	if (lit == NULL){//����ǿ�����ֱ�ӷ���null
		return;
	}
	//����������һ������
	if (lit->_head == NULL){
		lit->_head = xinzeng(data);
	}
	else{//���ǿ���������Ҫ����
		lists* list = lit->_head;
		//��Ϊ_head�ǵ�һ��Ԫ�صĵ�ַ,����Ҫlists*
		if (list->_next != NULL){
			list = list->_next;
		}
		list->_next = xinzeng(data);
	}
}

//βɾ
void weishan(firstlist* flist){
	if (flist == NULL||flist->_head==NULL){
		return;
	}
	//����������one ��two������
	lists* one = flist->_head;
	lists* two = NULL;
	if (one->_next != NULL){
		two = one;
		one = one->_next;
	}
	free(one);
	if (two == NULL){//������ֻ��ͷ�ڵ�,two��û��
		flist->_head = NULL;
	}
	else{
		two->_next = NULL;
	}
}

//ͷ��
void toucha(firstlist* flist,Data data){
	if (flist == NULL){
		return;
	}
	if (flist->_head == NULL){
		flist->_head = xinzeng(data);
	}
	else{
		lists* b = xinzeng(data);
		b->_next = flist->_head;
		flist->_head = b;	
	}
}

//ͷɾ
void toushan(firstlist* list){
	if (list==NULL){
		return;
	}
	if (list->_head == NULL){
		return;
	}
	else{
		struct lists* next = list->_head->_next;
		free(list->_head);
		list->_head = next;
	}
}

//��������һ���ڵ�
void jiaru(lists* a,Data data){//�ò���ͷ�ڵ�����ֱ�Ӳ���
	lists* list = xinzeng(data);
	list->_next = a->_next;
	a->_next = list;
}

//ɾ���Ǹ�λ�õ���һ��
void shanchu(lists* a,Data data){
	lists* next = a->_next;
	if (next == NULL){
		return;
	}
	lists* next2 = a->_next->_next;
	next = next2;
	free(next);
}

//�ҵ�ĳ����
lists* find(firstlist* flist, Data data){
	if (flist == NULL || flist->_head == NULL){
		return;
	}
	while (flist->_head){
		if (flist->_head->_data == data){
			return flist->_head;
		}
		else{
			flist->_head = flist->_head->_next;//˼·������ͷɾ,��û��free�Ͳ���ɾ��
		}
	return NULL;//һֱû�ҵ����ؿ�
	}
}

//��������
void xiaohui(firstlist* flist){
	if (flist == NULL || flist->_head == NULL){
		return;
	}
	while (flist->_head){//ѭ��ͷɾ
		flist->_head = flist->_head->_next;
		free(flist->_head);
	}
	flist->_head = NULL;
}




int main(){
	system("pause");
	return 0;
}