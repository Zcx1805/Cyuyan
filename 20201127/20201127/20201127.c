#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main() {
	
	FILE* f = fopen("d:/test.txt", "w");
	if (f == NULL) {
		// printf("�ļ���ʧ��! errno = %d, %s\n", errno, strerror(errno));
		perror("�ļ���ʧ��!");
		system("pause");
		return 1;
	}
	printf("�ļ��򿪳ɹ�!\n");

	
	//int n = fread(buf, 1, 1024, f);
	//printf("%s\n", buf);

	
	//char buf[1024] = "hahaha";
	//int n = fwrite(buf, 1, strlen(buf), f);
	//if (n < strlen(buf)) {
	//	perror("fwrite");
	//}

	// ʹ�� fprintf ���и�ʽ��д��
	//int num = 10;
	//fprintf(f, "num = %d", num);

	
	system("pause");
	return 0;
}