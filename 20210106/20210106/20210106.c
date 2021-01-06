#include<stdio.h>
typedef int Data;
typedef struct lists{//数据节点
	Data _data;
	struct lists* _prev;
	struct lists* _next;
}lists;

typedef struct headlist{//头结点
	struct lists* _head;
}headlist;

lists* create(Data data){//创造新节点
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

//尾插
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

//尾删
void weishan(headlist* hlist){
	if (hlist == NULL){
		return;
	}
	if (hlist->_head->_next = hlist->_head->_prev = hlist->_head){
		return;
	}
	lists* last = hlist->_head->_prev;//最后一个
	lists* prev=hlist->_head->_prev->_prev;//倒数第二个
	free(last);
	hlist->_head->_prev = prev;
	prev->_next = hlist->_head;
}

//头插
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

//头删
void toushan(headlist* hlist){
	if (hlist->_head->_next = hlist->_head->_prev = hlist->_head){
		return;
	}
	if (hlist == NULL){
		return;
	}
	lists* first = hlist->_head->_next;
	lists* second = hlist->_head->_next->_next;
	//_head  first(删)  second
	second->_prev = hlist->_head;
	hlist->_head->_next = second;
	free(first);
}

//在任意位置删除
void anywheredelete(headlist* hlist, lists* list){
	if (hlist->_head = list){
		return;
	}
	if (hlist == NULL){
		return;
	}
	//prev  list(删掉)  next
	lists* prev = list->_prev;
	lists* next = list->_next;

	prev->_next = next;
	next->_prev = prev;
	free(list);
}

//在任意位置增加
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