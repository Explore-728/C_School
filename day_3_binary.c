#include <stdio.h>
#include <limits.h>
int main()
{
	unsigned char num = 65;
	int i;
	int bits = sizeof(num)*CHAR_BIT;
	for(i = bits - 1;i >= 0;i--){
		// 复习：>> 右移是把灯泡往右推，&1是只留下最右边那个灯泡看亮不亮。
		printf("%d",(num>>i)&1);
	} 
	return 0;
 } 
