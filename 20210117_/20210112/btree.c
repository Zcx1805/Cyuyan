#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
//二叉树的实现和基本操作
typedef char Data;
typedef struct btree{
	Data _data;
	struct btree* _left;
	struct btree* _right;
}btree;

//必须是指定的#->代表空
//创建二叉树
//将arr数组的字符写在二叉树  idx为arr的索引 =0
//这个函数是错的,因为在返回root的时候,内嵌函数的idx++后的结果也释放掉了
//上一个函数的idx依旧是没++之前的idx,所以所得到的二叉树不正确
//idx必须为全局变量,不能被函数的结束而消散,或者利用指针来操作
btree* createbtree1(Data*arr, int idx){
	if (arr[idx] == '#'){
		idx++;
		return NULL;
	}
	else{
	//创建根
		btree* root = (btree*)malloc(sizeof(btree));
		root->_data = arr[idx];
		idx++;
		root->_left = createbtree1(arr, idx);
		root->_right = createbtree1(arr, idx);
		return root;
	}
}

btree* createbtree2(Data* arr, int *idx){
	if (arr[*idx] == '#'){//解引用
		(*idx)++;
		return NULL;
	}
	else{
		//创建根
		btree* root = (btree*)malloc(sizeof(btree));
		root->_data = arr[*idx];
		(*idx)++;
		root->_left = createbtree1(arr, idx);
		root->_right = createbtree1(arr, idx);
		return root;
	}
}

//前中后序遍历打印
void preorder(btree* tree){
	if (tree){
		printf("%d", tree->_data);
		preorder(tree->_left);
		preorder(tree->_right);
	}
}
void inorder(btree* tree){
	if (tree){
		
		preorder(tree->_left);
		printf("%d", tree->_data);
		preorder(tree->_right);
	}
}
void postorder(btree* tree){
	if (tree){
		
		preorder(tree->_left);
		preorder(tree->_right);
		printf("%d", tree->_data);
	}
}
//返回结点数
int size1(btree* tree){
	if (tree == NULL){
		return 0;
	}	
		return size(tree->_left) + size(tree->_right) + 1;
		//1是自身
}

//叶子结点
int leafsize(btree* tree){
	if (tree == NULL){
		return 0;
	}
	if (tree->_left == NULL&&tree->_right == NULL){
		return 1;
	}
	return 
	leafsize(tree->_left)+
	leafsize(tree->_right);
}

//第k层的节点数
int ksize(btree* tree,int k){
	if (tree == NULL){
		return 0;
	}
	if (k == 1){
		return 1;
	}
	return ksize(tree->_left, k - 1) + ksize(tree->_right, k - 1);
}

//找节点
btree* findtree(btree* tree, Data data){
	if (tree->_data == data){
		return tree;
	}
	if (tree == NULL){
		return NULL;
	}
	btree* node=findtree(tree->_left, data);
	if (node){//因为返回值要么是呢个节点要么空
		return node;
	}
	return findtree(tree->_right, data);
}

//二叉树销毁
//不是二级指针的话,销毁得是拷贝,并不是原数据
void xdistory(btree* a){
	distory(a->_left);
	distory(a->_right);
	free(a);
	a = NULL;
}

void distory(btree** a){
	if (a == NULL){
	//非法
	return;
	}
	if (*a == NULL){
	//空树
		 return;
	}
	distory(&((*a)->_left));
	distory(&((*a)->_right));
	free(*a);
	*a = NULL;//根节点将根节点指向空，防止成为野指针
}






//实现增序遍历需要队列
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
	queuenode* newqueue = createqe(data);
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



//层序遍历
void btreelevelorder(btree* root){
	queue* qe;
	init(qe);
	if (root){
		push(qe,root);
	}
	while (qe != NULL){
		btree* qenode = top(qe);
		pop(qenode);
		printf("%d", qenode->_data);
		if (root->_left)
			push(qe, root->_left);
		if (root->_right)
			push(qe, root->_right);
	}
}

//判断是不是完全二叉树
bool judje(btree* root){
	queue* qe;
	init(qe);
	if (root){
		push(qe, root);
	}
	while (qe != NULL){
		btree* front = top(root);
		pop(front);
		if (front){
			push(qe, front->_left);
			push(qe, front->_right);
		}
		else{
			break;
		}
	}
	//判断剩下的队列里是否有非空
	while (qe){
		btree* front = top(qe);
		pop(qe);
		if (front != NULL){
			return false;
		}
	}
	return true;
}

