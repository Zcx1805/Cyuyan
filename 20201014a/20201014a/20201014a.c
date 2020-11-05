#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main(){
	char num1[] =  "hello,World!" ;
	char num2[] =  "############" ;
	int left = 0;
	int right = strlen(num2) - 1;
	printf("%s\n", num2);
	for (left = 0, right = strlen(num2) - 1;
		left <= right;
		left++, right--)
	{Sleep(500);
	system("cls");
	num2[left] = num1[left];
	num2[right] = num1[right];
	printf("%s\n", num2); }
	system("pause");
	return 0;
}