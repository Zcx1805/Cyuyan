#include<stdio.h>
#include<windows.h>
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL){
		return pHead;
	}
	ListNode* prev, *start, *end;
	start = pHead;
	end = start->next;
	prev = NULL;
	while (end){
		if (end->val == start->val){
			while (end&&end->val == start->val){
				end = end->next;
			}
			while (start != end){
				struct ListNode* next = start->next;
				free(start);
				start = next;
			}
			if (prev == NULL){
				pHead = start;
			}
			else{
				prev->next = start;
			}
			if (end){
				end = end->next;
			}
		}
		else{
			prev = start;
			start = end;
			end = end->next;
		}
	}


	return pHead;
}



struct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL || head->next == NULL){
		return head;
	}
	struct ListNode* tail, *cur, *first, *second;
	tail = head;
	cur = head->next;
	while (cur){
		if (tail->val>cur->val){
			first = NULL;
			second = head;
			while (second&&second->val <= cur->val){
				first = second;
				second = second->next;
			}
			tail->next = cur->next;
			cur->next = second;
			if (first){
				first->next = cur;
			}
			else{
				head = cur;
			}
			cur = tail->next;
		}
		else{
			tail = tail->next;
			cur = tail->next;
		}
	}
	return head;
}



struct Node* copyRandomList(struct Node* head) {
	if (head == NULL){
		return head;
	}
	//先拷贝数据
	struct Node* cur = head;
	while (cur){

		struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
		newnode->val = cur->val;
		struct Node* next = cur->next;
		cur->next = newnode;
		newnode->next = next;
		cur = next;
	}
	//拷贝random
	cur = head;
	while (cur){
		struct Node* copy = cur->next;
		if (cur->random){
			copy->random = cur->random->next;

		}
		else{
			copy->random = NULL;
		}
		cur = copy->next;
	}
	//拆链子


	struct Node* newhead = NULL;
	cur = head;
	while (cur){
		struct Node* copy = cur->next;
		struct Node* next = copy->next;
		if (newhead == NULL){//确定头
			newhead = copy;
		}
		cur->next = next;
		if (next)
			copy->next = next->next;
		else
			copy->next = NULL;
		cur = next;
	}


	return newhead;



}
int main()
{
	int i = 0, a = 0;
	while (i<20)
	{
		for (;;)
		{
			if ((i % 10) == 0) break;
			else i--;
		} 
	i+= 11; a += i;
	}
	printf("%d\n", a);
	system("pause");
	return 0;
}