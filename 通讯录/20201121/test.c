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
	printf("*** 1. ������ϵ��        **\n");
	printf("*** 2. ɾ����ϵ��        **\n");
	printf("*** 3. ������ϵ��        **\n");
	printf("*** 4. �޸���ϵ��        **\n");
	printf("*** 5. ��ʾ������ϵ��    **\n");
	printf("*** 6. ���������ϵ��    **\n");
	printf("*** 7. ��������������ϵ��**\n");
	printf("*** 0. �˳�              **\n");
	printf("***************************\n");
	printf("��������ѡ��:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


void addperson(addressbook* addressbook) { 
	int Size = addressbook->size;//������size�����ִ�С
	person* p = &addressbook->persons[Size];//ָ�봫����
	if (Size >= MAX_PERSON) {
		printf("ͨѶ¼�Ѿ�����, ����ʧ��!\n");
		return 0;
	}
	printf("����������ϵ��\n"); 
	printf("����������ϵ�˵�����: ");
	scanf("%s", p->name);
	printf("����������ϵ�˵ĵ绰: ");
	scanf("%s", p->phnumber);
	printf("������ϵ�˳ɹ�!\n");
	addressbook->size++;
}

void delperson(addressbook* addressbook) {
	printf("ɾ����ϵ��\n");
	printf("������Ҫɾ������ϵ�˵ı��: ");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addressbook->size) {
		printf("������ı������!\n");
		return 0;
	}
	if (id == addressbook->size - 1) {
		addressbook->size--;
		printf("ɾ���ɹ�!\n");
		return 0;
	}
	// ��� id ��Ӧ��Ԫ�����м�Ԫ��, �����һ��Ԫ�ظ�bia����
	addressbook->persons[id]
		= addressbook->persons[addressbook->size - 1];
	addressbook->size--;
	printf("ɾ���ɹ�!\n");
}

void findPerson(addressbook* addressbook) {
	printf("������Ҫ���ҵ�����: ");
	char name[1024] = { 0 };
	scanf("%s", &name);
	for (int i = 0; i < addressbook->size; i++) {
		person* p = &addressbook->persons[i];
		if (strcmp(name, p->name) == 0) {//�ַ����ȽϺ��� ==0ȡ1
			printf("[%d]\t\t%s\t\t%s\n", i, p->name, p->phnumber);
		}
		printf("�����������ϵ��!\n");
	}
	printf("������ϵ�����!\n");
}

void printPerson(addressbook* addressbook) {
	printf("��ӡ������ϵ��\n");
	for (int i = 0; i < addressbook->size; i++) {
		person* p = &addressbook->persons[i];
		printf("[%d]\t\t%s\t\t%s\n", i, p->name, p->phnumber);
	}
	printf("���� [%d] ����¼\n", addressbook->size);
}

void updateperson(addressbook* addressbook) {
	printf("��������Ҫ�޸��˵ı��");
	int num = 0;
	scanf("%d", &num);
	if (num > addressbook->size){
		printf("��ϵ�˲�����!");
	}
	person*p = &addressbook->persons[num];
	printf("����Ҫ�ĳɵ�����:\n");
	char name[1024] = { 0 };
	scanf("%s", &name);
	strcpy(p->name, name);
	printf("����Ҫ�ĳɵĵ绰��:\n");
	char number[1024] = { 0 };
	scanf("%s", &number);
	strcpy(p->phnumber, number);
	printf("�޸����!\n");
}

void clearperson(addressbook* addressbook) {
	int num = addressbook->size;
	for (int i = 0; i < num; i++){
		addressbook->size--;
	}
	printf("�����ϵ�����!\n");
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
		printf("�ټ�!\n");
		break;
	}
	funcs[choice](&addressBook);
	}
	system("pause");
	return 0;
}