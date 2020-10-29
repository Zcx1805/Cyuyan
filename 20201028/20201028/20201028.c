#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int fib1(int n) {//循环斐波那契
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 1;
	}
	// 这俩变量分别表示第 i - 1 项和第 i - 2 项
	int last1 = 1;
	int last2 = 1;
	// 此处 cur 表示当前这个第 i 项 1 1 2 3 5 8 13
	int cur = 0;
	for (int i = 3; i <= n; i++) {
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}
int fib2(int n) {//递归斐波那契
		if (n == 1) {
			return 1;
		}
		if (n == 2) {
			return 1;
		}
		return fib2(n - 1) + fib2(n - 2);
	}
int strLen(char a[]) {
		// 求字符串长度的思路就是, 从前往后遍历字符数组. 
		// 每次读取到一个 字符 就 count++, 遇到 \0 就循环结束. 
		int count = 0;
		for (int i = 0; a[i] != '\0'; i++) {
			count++;
		}
		return count;
	}

int strLen1(char str[]) {
	if (str[0] == '\0') {
		// str 是一个空字符串 ""
		return 0;
	}
	return 1 + strLen1(str + 1);
}

//编写一个函数实现n的k次方，使用递归实现
int DigitSum(int n)//计算每一个位数之和
{
	if (n>9)
		return DigitSum(n / 10) + n % 10;
	else
		return n;
}int Nk(int n, int k)//递归实现n的k次方
{
	if (k>0)
	{
		return Nk(n, k - 1)*n;
	}
	return 1;
}


//逆序字符串
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
	printf("输入要求的斐波那契数:\n");
	scanf("%d", &n);
	printf("%d", fib2(n));*/
	//printf("%d", fib1(n));

	/*char a[] = "hello";
	int b = strLen1(a);
	printf("%d", b);*/

	/*int a = Nk(2, 10);
	printf("%d\n", a);*/

	/*int n = 0;
	printf("请输入一个数字\n");
	scanf("%d", &n);
	printf("%d\n", DigitSum(n));*/
	system("pause");
	return 0;
}