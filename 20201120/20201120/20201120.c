#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<assert.h>
#pragma warning (disable:4996)
void * mymmcpy(void * destination, const void * source, size_t num){
	assert(destination != NULL&&source != NULL);
	char* dest = (char*)destination;
	char* sour = (char*)source;
	for (size_t i = 0; i < num; i++){
		*(dest+1) = *(sour+1);	
	}
	return destination;
}

void * mymmove(void * destination, const void * source, size_t num){
	assert(destination != NULL&&source != NULL);
	char* dest = (char*)destination;
	char* sour = (char*)source;
	if (sour <= dest&&sour + num >= dest){
		for (size_t i = num; i >=0; i--){
			*(dest + i) = *(sour + i);
		}
		return destination;
	}return mymmcpy(dest,sour,num);
}
int main(){
	//Ä£ÄâÊµÏÖmemcopy
	//char arr1[] = { 0 };
	//char arr2[] = {1,2,3,4,5};
	//mymmcpy(arr1, arr2, sizeof(arr2));
	//for (int i = 0; i < 5; i++) {
	//	printf("%d\n", arr2[i]);
	//}

	
	system("pause");
	return 0;
}