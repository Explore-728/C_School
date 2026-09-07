#include <stdio.h>
int main()
{
	int i;
	int j;
	//复习：i管换行（行数），j管打印（列数） 
	for (i=1;i<=9;i++){
		for(j=1;j<=i;j++){
			printf("%d*%d=%d ",j,i,i*j);
		}
		printf("\n");
	}
	return 0;
}
