#include <stdio.h>
int main()
{
	unsigned int a = 10;
	signed int b = -20;
	
	//复习：有符号遇到无符号，有符号会被拖下水变成无符号（-20变成42亿） 
	if (a > b){
		printf("【实验一】10 > -20 成立？其实 b 被偷偷转成了：%u\n",b);
	}else{
		printf("【实验一】10 > -20不成立！因为 b 变成了：%u\n",b);
	}
	
	int x = 10;
	int y = 4;
	int result_int = x/y;
	printf("【实验二】整数除法：%d / %d (小数被砍掉了)\n",x,y,result_int);
	float result_float = (float)x/y;
	printf("【实验二】强制转换后：(float)%d / %d = %f(保留小数)\n",x,y,result_float);
	
	char c = 128;
	unsigned char uc =128;
	printf("【实验三】char 存 128 变成了：%d(溢出循环，变成 -128)\n",c);
	printf("【实验三】unsigned char 存 128 正常：%d\n",uc);
	
	return 0;
}


