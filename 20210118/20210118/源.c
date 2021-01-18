#include<stdio.h>
//˳���ʵ��ջ
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}treeNode;
typedef struct TreeNode* Data;
typedef struct stack{
	Data* _data;
	int _size;
	int _capacity;
}stack;

void init(stack* stack){
	if (stack == NULL){
		return;
	}
	stack->_data = NULL;
	stack->_capacity = stack->_size = 0;
}

void checkcapacity(stack* stack){
	if (stack->_capacity == stack->_size){
		int newcapacity = stack->_capacity == 0 ? 1 : stack->_capacity * 2;
		stack->_data = (Data*)realloc(stack->_data, sizeof(Data)*newcapacity);
		stack->_capacity = newcapacity;
	}
}

//��ջ(�Ƚ����)(�൱��β��)
void push(stack* stack, Data data){
	if (stack == NULL){
		return;
	}
	checkcapacity(stack);
	stack->_data[stack->_size] = data;
	stack->_size++;
}

//��ջ(�൱��βɾ)
void pop(stack* stack){
	if (stack == NULL){
		return;
	}
	if (stack->_size > 0){
		stack->_size--;
	}
}

//�õ�ջ��Ԫ��
stack* stacktop(stack* stack){
	//���Ϊ�յĻ����ؿ�,�����ж�
	return stack->_data[stack->_size - 1];
}

//�ж��Ƿ�Ϊ��ջ
int empty(stack* stack){
	if (stack->_size == 0){
		return 1;
	}
	else if (stack = NULL){
		return 1;
	}
	else{
		return 0;
	}
}









//ʵ�ֶ�������ǰ�����,��������ͺ������
//�ݹ�ͷǵݹ����,�ǵݹ���ջʵ��

//1.ǰ�����
//a.���ʸ��ڵ㿪ʼ������·��,�����ʵ�ÿһ���ڵ���ջ
//b.����·��������ɺ�,��ȡջ��Ԫ��,��ջ��Ԫ���ҽڵ�Ϊ���ڵ�ִ�е�һ��
//c.��������:ջΪ��||������Ϊ��

int getSize(struct TreeNode* root){
	 if (root){
		 return getSize(root->left) + getSize(root->right) + 1;
	 }
	 return 0;
}


int* predrder(struct TreeNode* root, int* returnSize){
	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int)*sz);
	int idx = 0;
	stack st;
	//��������:ջΪ��||������Ϊ��
	while (root || !empty(&st)){
		while (root){
			arr[idx++] = root->val;
			push(&st, root);
			root = root->left;
		}
		root=stacktop(&st);
		pop(&st);
		root = root->right;
	}
	*returnSize = idx;
	return arr;
 }


//2.�������
//a.���ڵ�������·��,����ջ,������
//b.��ȡջ��Ԫ��,����ջ��Ԫ��
//c.��ȡջ��Ԫ�ص�������,ִ��a
//����:ջΪ��&&������Ϊ��
int* inorder(struct TreeNode* root, int* returnSize){
	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int)*sz);
	int idx = 0;
	stack st;
	
	while (root || !empty(&st)){
		while (root){
			root = root->left;
		}
		root=stacktop(&st);
		arr[idx++] = root->val;
		pop(&st);
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}


//3.�������
//1.�Խڵ㿪ʼ������·��,��ջ
//2.��ȡջ��Ԫ��:
//				1.û��������,����
//				2.��������������,����
//				3.������û����,�ȷ���������
//����ִ�е�һ��
//3.�ڵ�Ϊ��&&ջΪ��
int* inorder(struct TreeNode* root, int* returnSize){
	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int)*sz);
	int idx = 0;
	stack st;
	struct TreeNode* prev = NULL;
	while (root || !empty(&st)){
		while (root){
			root = root->left;
		}
		struct TreeNode* top = stacktop(&st);
		if (top->right == NULL || top->right == prev){
			arr[idx++] = top->val;
			pop(&st);
			prev = top;
		}
		else{
			root = top->right;
		
		}
		
	}
	*returnSize = idx;
	return arr;
}