#include <stdio.h>

int main() {
    // 1. 定义一个 int 类型的数组（3个房间，每个4字节）
    int arr[3] = {10, 20, 30};
    
    // 2. 定义一个 int 指针，指向数组的第一个元素
    int *p = arr;  // 等价于 int *p = &arr[0];
    
    printf("========== 观察指针的“步伐” ==========\n");
    printf("arr[0] 的地址（即 p）: %p\n", p);
    printf("arr[1] 的地址（即 p+1）: %p\n", p + 1);
    printf("arr[2] 的地址（即 p+2）: %p\n", p + 2);
    
    // 3. 计算一下地址相差的字节数（用 long 强制转换相减）
    long diff = (long)(p + 1) - (long)p;
    printf("\n【关键发现】p+1 和 p 相差了 %ld 个字节！\n", diff);
    
    // 4. 验证：指针加1后，取到的值是不是数组的下一个元素？
    printf("\n========== 验证取值 ==========\n");
    printf("p 指向的值: %d\n", *p);
    printf("p+1 指向的值: %d\n", *(p + 1));
    
    // 5. 挖个坑：你知道数组下标 arr[1] 和指针写法有什么关系吗？
    printf("\n【结论】arr[1] 等价于 *(p+1)，因为数组名就是首地址！\n");
    
    printf("arr 地址: %p\n", arr); 		
    printf("&arr 地址: %p\n", &arr);
    return 0;
}

