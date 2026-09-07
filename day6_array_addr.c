#include <stdio.h>
void test_array_size(int arr[]){
	printf("[在函数内部] sizeof(arr) = %lu 字节(注意！它变成了指针的大小！)\n",(unsigned long)sizeof(arr));
} 

int main(){
	int arr[5] = {10,20,30,40,50};
	printf("========== 实验一：门牌号验证 ==========\n");
    printf("直接打印数组名 arr 的地址: %p\n", arr);
    printf("打印第一个元素 &arr[0] 的地址：%p\n",&arr[0]);
	
	printf("整个数组 arr 占 %lu 字节 （5个int，每个4字节）\n",(unsigned long)sizeof(arr));
	
	printf("\n======== 实验二：数组传参陷阱 ========\n");
	// 复习：调用时只写数组名，传进去的是门牌号（地址），不是整栋楼。
	test_array_size(arr);
	
	return 0; 
}
