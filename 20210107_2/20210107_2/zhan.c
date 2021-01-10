#include<stdio.h>
//顺序表实现栈
typedef int Data;
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
	if (stack->_capacity==stack->_size){
		int newcapacity = stack->_capacity == 0 ? 1 : stack->_capacity * 2;
		stack->_data = (Data*)realloc(stack->_data,sizeof(Data)*newcapacity);
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
void stacktop(stack* stack){
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

int size(stack* stack){
	if (stack == NULL){
		return 0;
	}
	return stack->_size;
}




