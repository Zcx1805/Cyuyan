//#include<stdio.h>
//
//typedef struct hello{
//	char one;
//	short two;
//	double three;
//	float four;
//	double five;
//	short six;
//	char seven;
//}hi;
//
//typedef struct A{
//	char one;
//	int two;
//	int three;
//}A;
//typedef struct B{
//	char one;
//	int two;
//	char three;
//}B;
//typedef struct C{
//	char one;
//	char two;
//	int three;
//}C;
//#pragma pack(4)/*����ѡ���ʾ4�ֽڶ��� ƽ̨��VS2013�����ԣ�C����*/
//int main(int argc, char* argv[])
//{
//	struct tagTest1
//	{
//		short a;//2
//		char d;//1
//		long b;//4
//		long c;//4
//	};
//	struct tagTest2
//	{
//		long b;//4
//		short c;//2
//		char d;//1
//		long a;//4
//	};
//	struct tagTest3
//	{
//		short c;
//		long b;
//		char d;
//		long a;
//	};
//	struct tagTest1 stT1;
//	struct tagTest2 stT2;
//	struct tagTest3 stT3;
//
//	printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
//	return 0;
//}
//#pragma pack()
//����1
#include <stdio.h>
//int main()
//{
//	struct Node{
//		int data;
//		struct Node next;
//	};
//
//
//	printf("%d", sizeof(struct Node));
//	system("pause");
//	return 0;
//}
//struct Point
//{
//	int x;
//	int y;
//}p1; //�������͵�ͬʱ�������p1
//struct Point p2; //����ṹ�����p2
////��ʼ�������������ͬʱ����ֵ��
//struct Point p3 = { x, y };
//struct Stu        //��������
//{
//	char name[15];//����
//	int age;      //����
//};
//struct Stu s = { "zhangsan", 20 };//��ʼ��
//struct Node
//{
//	int data;
//	struct Point p;
//	struct Node* next;
//}n1 = { 10, { 4, 5 }, NULL }; //�ṹ��Ƕ�׳�ʼ��
//struct Node n2 = { 20, { 5, 6 }, NULL };//�ṹ��Ƕ�׳�ʼ��

//���з�
struct A
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};
int main(){
	printf("%d\n", sizeof(struct A));
	system("pause");
	return 0;

}
