#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
//��������ʵ�ֺͻ�������
typedef char Data;
typedef struct btree{
	Data _data;
	struct btree* _left;
	struct btree* _right;
}btree;

//������ָ����#->�����
//����������
//��arr������ַ�д�ڶ�����  idxΪarr������ =0
//��������Ǵ��,��Ϊ�ڷ���root��ʱ��,��Ƕ������idx++��Ľ��Ҳ�ͷŵ���
//��һ��������idx������û++֮ǰ��idx,�������õ��Ķ���������ȷ
//idx����Ϊȫ�ֱ���,���ܱ������Ľ�������ɢ,��������ָ��������
btree* createbtree1(Data*arr, int idx){
	if (arr[idx] == '#'){
		idx++;
		return NULL;
	}
	else{
	//������
		btree* root = (btree*)malloc(sizeof(btree));
		root->_data = arr[idx];
		idx++;
		root->_left = createbtree1(arr, idx);
		root->_right = createbtree1(arr, idx);
		return root;
	}
}

btree* createbtree2(Data* arr, int *idx){
	if (arr[*idx] == '#'){//������
		(*idx)++;
		return NULL;
	}
	else{
		//������
		btree* root = (btree*)malloc(sizeof(btree));
		root->_data = arr[*idx];
		(*idx)++;
		root->_left = createbtree1(arr, idx);
		root->_right = createbtree1(arr, idx);
		return root;
	}
}

//ǰ�к��������ӡ
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
//���ؽ����
int size1(btree* tree){
	if (tree == NULL){
		return 0;
	}	
		return size(tree->_left) + size(tree->_right) + 1;
		//1������
}

//Ҷ�ӽ��
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

//��k��Ľڵ���
int ksize(btree* tree,int k){
	if (tree == NULL){
		return 0;
	}
	if (k == 1){
		return 1;
	}
	return ksize(tree->_left, k - 1) + ksize(tree->_right, k - 1);
}

//�ҽڵ�
btree* findtree(btree* tree, Data data){
	if (tree->_data == data){
		return tree;
	}
	if (tree == NULL){
		return NULL;
	}
	btree* node=findtree(tree->_left, data);
	if (node){//��Ϊ����ֵҪô���ظ��ڵ�Ҫô��
		return node;
	}
	return findtree(tree->_right, data);
}

//����������
//���Ƕ���ָ��Ļ�,���ٵ��ǿ���,������ԭ����
void xdistory(btree* a){
	distory(a->_left);
	distory(a->_right);
	free(a);
	a = NULL;
}

void distory(btree** a){
	if (a == NULL){
	//�Ƿ�
	return;
	}
	if (*a == NULL){
	//����
		 return;
	}
	distory(&((*a)->_left));
	distory(&((*a)->_right));
	free(*a);
	*a = NULL;//���ڵ㽫���ڵ�ָ��գ���ֹ��ΪҰָ��
}






//ʵ�����������Ҫ����
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
	queuenode* newqueue = createqe(data);
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



//�������
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

//�ж��ǲ�����ȫ������
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
	//�ж�ʣ�µĶ������Ƿ��зǿ�
	while (qe){
		btree* front = top(qe);
		pop(qe);
		if (front != NULL){
			return false;
		}
	}
	return true;
}

