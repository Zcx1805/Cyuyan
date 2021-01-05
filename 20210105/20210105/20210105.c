#include<stdio.h>
#include<windows.h>
typedef int Data;        //数据类型
typedef struct lists{    //自定义单链表结构体
	Data _data;
	struct lists* _next;
}lists;

//自定义头结点
typedef struct firstlist{//用来找到并操作链表,必须从头开始
	struct lists* _head;
}firstlist;

//结构体初始化
void init(firstlist* flist){
	if (flist == NULL){
		return flist;
	}
	flist->_head = NULL;   //数据设为空
}

lists* xinzeng(Data _data){//将一个数据传入一个新链表,返回新链表的地址
	lists* newlist = (lists*)malloc(sizeof(lists));
	newlist->_data = _data;
	newlist->_next = NULL;
	return newlist;
}

//尾插
void weicha(firstlist* lit,Data data){//将data尾插到lit链表中
	//传firstlist是因为知道头结点地址就可以操作链表了
	if (lit == NULL){//如果是空链表直接返回null
		return;
	}
	//空链表插入第一个数据
	if (lit->_head == NULL){
		lit->_head = xinzeng(data);
	}
	else{//不是空链表则需要遍历
		lists* list = lit->_head;
		//因为_head是第一个元素的地址,所以要lists*
		if (list->_next != NULL){
			list = list->_next;
		}
		list->_next = xinzeng(data);
	}
}

//尾删
void weishan(firstlist* flist){
	if (flist == NULL||flist->_head==NULL){
		return;
	}
	//用两个变量one 和two来操作
	lists* one = flist->_head;
	lists* two = NULL;
	if (one->_next != NULL){
		two = one;
		one = one->_next;
	}
	free(one);
	if (two == NULL){//这种是只有头节点,two就没变
		flist->_head = NULL;
	}
	else{
		two->_next = NULL;
	}
}

//头插
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

//头删
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

//在哪新增一个节点
void jiaru(lists* a,Data data){//用不到头节点所以直接操作
	lists* list = xinzeng(data);
	list->_next = a->_next;
	a->_next = list;
}

//删除那个位置的下一个
void shanchu(lists* a,Data data){
	lists* next = a->_next;
	if (next == NULL){
		return;
	}
	lists* next2 = a->_next->_next;
	next = next2;
	free(next);
}

//找到某数据
lists* find(firstlist* flist, Data data){
	if (flist == NULL || flist->_head == NULL){
		return;
	}
	while (flist->_head){
		if (flist->_head->_data == data){
			return flist->_head;
		}
		else{
			flist->_head = flist->_head->_next;//思路类似于头删,但没有free就不是删除
		}
	return NULL;//一直没找到返回空
	}
}

//销毁链表
void xiaohui(firstlist* flist){
	if (flist == NULL || flist->_head == NULL){
		return;
	}
	while (flist->_head){//循环头删
		flist->_head = flist->_head->_next;
		free(flist->_head);
	}
	flist->_head = NULL;
}




int main(){
	system("pause");
	return 0;
}