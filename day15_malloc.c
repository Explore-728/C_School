#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	int *arr;
	
	printf("请输入你要存储的数字个数：");
	scanf("%d",&n);
	
	arr = (int*)malloc(n * sizeof(int));
	
	if(arr == NULL){
		printf("内存申请失败！系统内存不足！\n");
		return 1;
	} 
	
	int i;
	for (i = 0; i < n; i++) {
        printf("请输入第 %d 个数字: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("你输入的数字是：");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	} 
	printf("\n");
	free(arr);
	arr = NULL;
	printf("内存已安全释放，程序结束。\n");
	return 0;
} 
