#include<stdio.h>
#include<windows.h>
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

