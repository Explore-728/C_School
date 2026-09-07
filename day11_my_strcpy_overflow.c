#include <stdio.h>
#include <string.h>
void my_strcpy(char *dest,char *src){
	int i = 0;
	while (src[i] != '\0'){
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
} 
int main(){
	char buffer[50];
	char *big_str = "Hello!!!";
	printf("【攻击前】目标 buffer 只分配了 5 个字节。\n");
	printf("【攻击前】源字符串 big_str 是: \"%s\"，长度是 %lu 个字符（含结尾的\\0共 %lu 字节）\n", 
           big_str, (unsigned long)sizeof(big_str) - 1, (unsigned long)sizeof(big_str));
	printf("\n【执行 my_strcpy】正在把洪水注入小房间...\n");
    my_strcpy(buffer, big_str);
    printf("【结果】拷贝后 buffer 的内容是: \"%s\"\n", buffer);
    printf("（如果看到这行，说明程序侥幸跑完了，但内存已经乱套了！）\n");
    
    return 0;
}

