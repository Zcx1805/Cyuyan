#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int fib1(int n) {//ѭ��쳲�����
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 1;
	}
	// ���������ֱ��ʾ�� i - 1 ��͵� i - 2 ��
	int last1 = 1;
	int last2 = 1;
	// �˴� cur ��ʾ��ǰ����� i �� 1 1 2 3 5 8 13
	int cur = 0;
	for (int i = 3; i <= n; i++) {
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}
int fib2(int n) {//�ݹ�쳲�����
		if (n == 1) {
			return 1;
		}
		if (n == 2) {
			return 1;
		}
		return fib2(n - 1) + fib2(n - 2);
	}
int strLen(char a[]) {
		// ���ַ������ȵ�˼·����, ��ǰ��������ַ�����. 
		// ÿ�ζ�ȡ��һ�� �ַ� �� count++, ���� \0 ��ѭ������. 
		int count = 0;
		for (int i = 0; a[i] != '\0'; i++) {
			count++;
		}
		return count;
	}

int strLen1(char str[]) {
	if (str[0] == '\0') {
		// str ��һ�����ַ��� ""
		return 0;
	}
	return 1 + strLen1(str + 1);
}

//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ��
int DigitSum(int n)//����ÿһ��λ��֮��
{
	if (n>9)
		return DigitSum(n / 10) + n % 10;
	else
		return n;
}int Nk(int n, int k)//�ݹ�ʵ��n��k�η�
{
	if (k>0)
	{
		return Nk(n, k - 1)*n;
	}
	return 1;
}


//�����ַ���
int reverse_string(char string[]){
	if (*string == '\0'){
		return 0;
	}
	reverse_string(string + 1);
	printf("%c ", *string);

}


	
	
int main()
{
	char string[] = "hello";
	reverse_string(string);


	/*int n = 0;
	printf("����Ҫ���쳲�������:\n");
	scanf("%d", &n);
	printf("%d", fib2(n));*/
	//printf("%d", fib1(n));

	/*char a[] = "hello";
	int b = strLen1(a);
	printf("%d", b);*/

	/*int a = Nk(2, 10);
	printf("%d\n", a);*/

	/*int n = 0;
	printf("������һ������\n");
	scanf("%d", &n);
	printf("%d\n", DigitSum(n));*/
	system("pause");
	return 0;
}