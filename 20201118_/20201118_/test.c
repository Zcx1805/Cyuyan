#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#pragma warning(disable:4996)
int mystrlen(const char *arr){
	int count=0;
	while (arr[count] != '\0') {
		count++;
	}
	return count;
}
char* mystrcpy(char *arr1,const char *arr2){
	char *arr3 = arr1;
	while (*arr2 != '\0'){
		*arr1 = *arr2;
		arr1++;
		arr2++;
	}
	*arr1 = '\0';
	return arr3;
}
int mystrcmp(const char * str1, const char * str2){
	assert(str1 != NULL && str2 != NULL);
	while (*str1 != '\0'&&*str2 != '\0'){
		if (*str1 > *str2){
			return 1;
		}
		else if (*str1 < *str2){
			return -1;
		}
		str1++;
		str2++;
	}
	if (str1 == '\0'){
		return 1;
	}
	else if(str2 == '\0'){
		return -1;
	}
	return 0;
}

char* mystrcat(char* dest, const char* src) {
	if (dest == NULL || src == NULL) {
		return dest;
	}
	char* arr =  dest;
	while (*arr != '\0'){
		arr++;
	}
	while (*src != '\0'){
		*arr = *src;
		arr++;
		src++;
	}
	*arr= '\0';
	return dest;
}
const char* myStrstr(const char* str1, const char* str2) {
	if (str1 == NULL || str2 == NULL) {
		return NULL;
	}//black起始;redptr(长)和subptr(段)观察
	const char* blackPtr = str1;
	while (*blackPtr != '\0') {
		const char* redPtr = blackPtr;
		const char* subPtr = str2;
		while (*redPtr != '\0' && *subPtr != '\0'
			&& *redPtr == *subPtr) {
			redPtr++;
			subPtr++;
		}
		
		if (*subPtr == '\0') {
			return blackPtr;
		}
		blackPtr++;
	}
	return NULL;
}
int main(){
	//char arr[] = "hello";
	//char arr1[] = "hehe";
	//printf("%s", mystrcat(arr, arr1));
	
	//printf("%d", mystrcmp(arr, arr1));

	//printf("%d", mystrlen(arr));
	/*char arr2[] = {0};
	mystrcpy(arr2, arr);*/
	//printf("%s", arr2);

	system("pause");
	return 0;
}
 