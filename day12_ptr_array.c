#include <stdio.h>
int main(){
	char *langs[3] = {"C","Python","Java"};
	int i;
	for (i=0;i<3;i++){
		printf("langs[%d]的门牌号：%p,指向的内容：%s\n",i,langs[i],langs[i]);
	}
	printf("langs 数组的首地址：%p\n",langs);
	printf("langs[0] 的地址：%p\n",langs[0]);
	printf("langs[1] 的地址：%p\n",langs[1]);
	printf("langs[2] 的地址：%p\n",langs[2]);
	
	return 0;
}

