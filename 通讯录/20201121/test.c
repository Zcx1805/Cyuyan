#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define MAX_PERSON 1024
typedef struct person{
	char name  [1024];
	char phnumber[1024];
}person;

typedef struct addressbook{
	person persons[MAX_PERSON];
	int size;
}addressbook;

int menu(){
	printf("***************************\n");
	printf("*** 1. 新增联系人        **\n");
	printf("*** 2. 删除联系人        **\n");
	printf("*** 3. 查找联系人        **\n");
	printf("*** 4. 修改联系人        **\n");
	printf("*** 5. 显示所有联系人    **\n");
	printf("*** 6. 清空所有联系人    **\n");
	printf("*** 7. 名字排序所有联系人**\n");
	printf("*** 0. 退出              **\n");
	printf("***************************\n");
	printf("输入您的选择:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


void addperson(addressbook* addressbook) { 
	int Size = addressbook->size;//传来了size的数字大小
	person* p = &addressbook->persons[Size];//指针传来了
	if (Size >= MAX_PERSON) {
		printf("通讯录已经满了, 新增失败!\n");
		return 0;
	}
	printf("输入新增联系人\n"); 
	printf("请输入新联系人的姓名: ");
	scanf("%s", p->name);
	printf("请输入新联系人的电话: ");
	scanf("%s", p->phnumber);
	printf("新增联系人成功!\n");
	addressbook->size++;
}

void delperson(addressbook* addressbook) {
	printf("删除联系人\n");
	printf("请输入要删除的联系人的编号: ");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addressbook->size) {
		printf("您输入的编号有误!\n");
		return 0;
	}
	if (id == addressbook->size - 1) {
		addressbook->size--;
		printf("删除成功!\n");
		return 0;
	}
	// 如果 id 对应的元素是中间元素, 把最后一个元素给bia过来
	addressbook->persons[id]
		= addressbook->persons[addressbook->size - 1];
	addressbook->size--;
	printf("删除成功!\n");
}

void findPerson(addressbook* addressbook) {
	printf("请输入要查找的姓名: ");
	char name[1024] = { 0 };
	scanf("%s", &name);
	for (int i = 0; i < addressbook->size; i++) {
		person* p = &addressbook->persons[i];
		if (strcmp(name, p->name) == 0) {//字符串比较函数 ==0取1
			printf("[%d]\t\t%s\t\t%s\n", i, p->name, p->phnumber);
		}
		printf("不存在这个联系人!\n");
	}
	printf("查找联系人完成!\n");
}

void printPerson(addressbook* addressbook) {
	printf("打印所有联系人\n");
	for (int i = 0; i < addressbook->size; i++) {
		person* p = &addressbook->persons[i];
		printf("[%d]\t\t%s\t\t%s\n", i, p->name, p->phnumber);
	}
	printf("共计 [%d] 条记录\n", addressbook->size);
}

void updateperson(addressbook* addressbook) {
	printf("请输入你要修改人的编号");
	int num = 0;
	scanf("%d", &num);
	if (num > addressbook->size){
		printf("联系人不存在!");
	}
	person*p = &addressbook->persons[num];
	printf("输入要改成的姓名:\n");
	char name[1024] = { 0 };
	scanf("%s", &name);
	strcpy(p->name, name);
	printf("输入要改成的电话号:\n");
	char number[1024] = { 0 };
	scanf("%s", &number);
	strcpy(p->phnumber, number);
	printf("修改完成!\n");
}

void clearperson(addressbook* addressbook) {
	int num = addressbook->size;
	for (int i = 0; i < num; i++){
		addressbook->size--;
	}
	printf("清空联系人完成!\n");
}

char sortperson(addressbook* addressbook){
	int i = 0;
	int j = 0;
	for (i = 0; i < addressbook->size - 1; i++)
	{
		for (j = 0; j<addressbook->size - 1 - i; j++)
		{
			if (strcmp(addressbook->persons[j].name, (addressbook->persons[j + 1]).name)>0)
			{
				person tmp = addressbook->persons[j];
				addressbook->persons[j] = addressbook->persons[j + 1];
				addressbook->persons[j + 1] = tmp;
			}
		}
	}
}

void init(addressbook* addressbook){
	addressbook->size = 0;
}

typedef void(*Func)(addressbook*);
addressbook addressBook;
int main(){
	Func funcs[] = {
		NULL,
		addperson,
		delperson,
		findPerson,
		updateperson,
		printPerson,
		clearperson,
		sortperson
	};
	while (1){
	int	 choice = menu();
	if (choice == 0){
		printf("再见!\n");
		break;
	}
	funcs[choice](&addressBook);
	}
	system("pause");
	return 0;
}