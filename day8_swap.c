#include <stdio.h>
void swap_wrong(int a,int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("【函数内部】交换后：a=%d,b=%d\n",a,b);
 } 
 
 void swap_right(int *a,int *b)
 {
 	int temp;
 	temp = *a;
 	*a =*b;
 	*b = temp;
 }
 
int main()
{
	int x = 10;
	int y = 20;
	
	printf("【原始值】x=%d,y=%d\n\n",x,y);
	
	printf("--- 实验：调用 swap_wrong ---\n");
	swap_wrong(x,y);
	printf("【回到 main 后】x = %d，y = %d\n\n",x,y);
	
	printf("---实验：调用 swap_right ---\n");
	swap_right(&x,&y);
	printf("【回到 main 后】x=%d,y=%d\n",x,y);
	
	return 0;
}
