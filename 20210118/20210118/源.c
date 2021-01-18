#include<stdio.h>
//顺序表实现栈
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

//入栈(先进后出)(相当于尾插)
void push(stack* stack, Data data){
	if (stack == NULL){
		return;
	}
	checkcapacity(stack);
	stack->_data[stack->_size] = data;
	stack->_size++;
}

//出栈(相当于尾删)
void pop(stack* stack){
	if (stack == NULL){
		return;
	}
	if (stack->_size > 0){
		stack->_size--;
	}
}

//得到栈顶元素
stack* stacktop(stack* stack){
	//如果为空的话返回空,不用判断
	return stack->_data[stack->_size - 1];
}

//判断是否为空栈
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









//实现二叉树的前序遍历,中序遍历和后序遍历
//递归和非递归二种,非递归用栈实现

//1.前序遍历
//a.访问根节点开始的最左路径,将访问的每一个节点入栈
//b.最左路径访问完成后,获取栈顶元素,以栈顶元素右节点为根节点执行第一步
//c.结束条件:栈为空||右子树为空

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
	//结束条件:栈为空||右子树为空
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


//2.中序遍历
//a.根节点走最左路径,先入栈,不访问
//b.获取栈顶元素,访问栈顶元素
//c.获取栈顶元素的右子树,执行a
//结束:栈为空&&右子树为空
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


//3.后序遍历
//1.以节点开始走最左路径,入栈
//2.获取栈顶元素:
//				1.没有右子树,访问
//				2.右子树访问完了,访问
//				3.右子树没访问,先访问右子树
//接着执行第一步
//3.节点为空&&栈为空
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