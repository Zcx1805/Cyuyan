#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main() {
	
	FILE* f = fopen("d:/test.txt", "w");
	if (f == NULL) {
		// printf("文件打开失败! errno = %d, %s\n", errno, strerror(errno));
		perror("文件打开失败!");
		system("pause");
		return 1;
	}
	printf("文件打开成功!\n");

	
	//int n = fread(buf, 1, 1024, f);
	//printf("%s\n", buf);

	
	//char buf[1024] = "hahaha";
	//int n = fwrite(buf, 1, strlen(buf), f);
	//if (n < strlen(buf)) {
	//	perror("fwrite");
	//}

	// 使用 fprintf 进行格式化写入
	//int num = 10;
	//fprintf(f, "num = %d", num);

	
	system("pause");
	return 0;
}