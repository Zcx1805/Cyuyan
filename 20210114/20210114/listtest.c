#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
	int val;
	struct Node* next;
	struct Node* random;
};
typedef struct ListNode{
	int val;
	struct ListNode* next;
};
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


//判断有环
bool hasCycle(struct ListNode *head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast&&fast->next){
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow){
			return true;
		}
	}
	return false;
}

int Size(struct ListNode* head){
	int idx = 0;
	while (head != NULL){
		idx++;
		head = head->next;
	}
	return idx;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL){
		return NULL;
	}
	if (headB == NULL){
		return NULL;
	}
	int a = Size(headA);
	int b = Size(headB);
	int c = 0;
	if (a >= b){
		c = a - b;
		while (c--){
			headA = headA->next;
		}
	}
	else{
		c = b - a;
		while (c--){
			headB = headB->next;
		}
	}
	while (headA&&headB){
		if (headA == headB){
			return headA;
		}
		else{
			headA = headA->next;
			headB = headB->next;
		}
	}
	return NULL;

}