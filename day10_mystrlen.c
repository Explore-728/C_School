#include <stdio.h>

// 手写 strlen 函数（网安版：不用任何标准库函数）
int my_strlen(char *s) {
    int count = 0;          // 计数器，从 0 开始
    
    // 只要 s[count] 不是 '\0'（结束符），就继续数
    while (s[count] != '\0') {
        count++;            // 找到一个字符，计数器加 1
    }
    
    return count;           // 返回总个数
}

int main() {
    // 测试用例 1：普通字符串
    char str1[] = "Hello";
    int len1 = my_strlen(str1);
    printf("字符串 '%s' 的长度是: %d\n", str1, len1);
    
    // 测试用例 2：空字符串（只有 \0）
    char str2[] = "";
    int len2 = my_strlen(str2);
    printf("字符串 '%s' 的长度是: %d\n", str2, len2);
    
    // 测试用例 3：包含空格的字符串
    char str3[] = "Cyber Security";
    int len3 = my_strlen(str3);
    printf("字符串 '%s' 的长度是: %d\n", str3, len3);
    
    // 测试用例 4（网安视角）：用指针方式定义字符串
    char *str4 = "Hack";
    int len4 = my_strlen(str4);
    printf("字符串 '%s' 的长度是: %d\n", str4, len4);
    
    return 0;
}
