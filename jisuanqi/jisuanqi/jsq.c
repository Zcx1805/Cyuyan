#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)

int Myjia(int x, int y){
	return x + y;
}
int Myjian(int x, int y){
	return x - y;
}
int Mycheng(int x, int y) {
	return x*y;
}
int Mychu(int x, int y) {
	return x / y;
	
};
int main(){
	printf("���������֣�");
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	char abc = 'm';
	printf("����+ - * /:" );
	scanf(" %c", &abc);//�ո񻺳���
	if (abc == '+') {
		printf("%d +%d =%d", a, b, Myjia(a, b));
	}
	else if (abc == '-') {
		printf("%d-%d=%d", a, b, Myjian(a, b));
	}
	else if (abc == '*'){
		printf("%d*%d=%d", a, b, Mycheng(a, b));
	}
	else if (abc == '/') {
		printf("%d/%d=%d", a, b, Mychu(a, b));
	}
	else{
		printf("error;");
	}
	system("pause");
	return 0;
	}