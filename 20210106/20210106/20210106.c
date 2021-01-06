#include<stdio.h>
typedef int Data;
typedef struct lists{//���ݽڵ�
	Data _data;
	struct lists* _prev;
	struct lists* _next;
}lists;

typedef struct headlist{//ͷ���
	struct lists* _head;
}headlist;

lists* create(Data data){//�����½ڵ�
	lists* new = (lists*)malloc(sizeof(lists));
	new->_data = data;
	new->_next = NULL;
	new->_prev = NULL;
}

void init(headlist* hlist){
	if (hlist == NULL){
		return;
	}
	hlist->_head = create(0);
	hlist->_head->_next = hlist->_head->_prev = hlist->_head;
}

//β��
void weicha(headlist* hlist, Data data){
	if (hlist == NULL){
		return;
	}
	//_head .....  last + new
	lists* new = create(data);
	lists* last=hlist->_head->_prev;
	last->_next=new;
	new->_prev = last;
	new->_next = hlist->_head;
	hlist->_head->_prev = new;
}

//βɾ
void weishan(headlist* hlist){
	if (hlist == NULL){
		return;
	}
	if (hlist->_head->_next = hlist->_head->_prev = hlist->_head){
		return;
	}
	lists* last = hlist->_head->_prev;//���һ��
	lists* prev=hlist->_head->_prev->_prev;//�����ڶ���
	free(last);
	hlist->_head->_prev = prev;
	prev->_next = hlist->_head;
}

//ͷ��
void toucha(headlist* hlist, Data data){
	if (hlist == NULL){
		return;
	}
	lists* new=create(data);
	lists* old=hlist->_head->_next;
	//_head   (new)   old
	hlist->_head->_next = new;
	new->_prev = hlist->_head;
	new->_next = old;
	old->_prev = new;
}

//ͷɾ
void toushan(headlist* hlist){
	if (hlist->_head->_next = hlist->_head->_prev = hlist->_head){
		return;
	}
	if (hlist == NULL){
		return;
	}
	lists* first = hlist->_head->_next;
	lists* second = hlist->_head->_next->_next;
	//_head  first(ɾ)  second
	second->_prev = hlist->_head;
	hlist->_head->_next = second;
	free(first);
}

//������λ��ɾ��
void anywheredelete(headlist* hlist, lists* list){
	if (hlist->_head = list){
		return;
	}
	if (hlist == NULL){
		return;
	}
	//prev  list(ɾ��)  next
	lists* prev = list->_prev;
	lists* next = list->_next;

	prev->_next = next;
	next->_prev = prev;
	free(list);
}

//������λ������
void anywhereadd(headlist* hlist, lists* list, Data data){
	if (hlist == NULL){
		return;
	}
	//prev new  list
	lists* new = create(data);
	lists* prev = list->_prev;
	prev->_next = new;
	new->_prev = prev;
	new->_next = list;
	list->_prev = new;
}