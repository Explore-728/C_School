#include <stdio.h>
#include <stdlib.h>

int main() {
    // =============================================
    // 实验一：制造“悬空指针”（Use-After-Free）
    // =============================================
    printf("========== 实验一：UAF（释放后使用） ==========\n");
    
    // 1. 在堆上申请一个 int 大小的房间
    int *p = (int*)malloc(sizeof(int));
    if (p == NULL) {
        printf("内存申请失败！\n");
        return 1;
    }
    
    // 2. 往房间里写入数据
    *p = 666;
    printf("【释放前】p 指向的值: %d，p 的地址（门牌号）: %p\n", *p, p);
    
    // 3. 释放这块内存（把房间归还给系统）
    free(p);
    printf("【已执行 free(p)】p 里还存着门牌号: %p（但房间已经不属于你了！）\n", p);
    
    // 4. ！！！高危操作：释放后继续使用（Use-After-Free） ！！！
    //    尝试读取已经释放的内存
    printf("【尝试读取已释放内存】*p = %d （可能乱码或崩溃！）\n", *p);
    
    //    尝试写入已经释放的内存
    *p = 999;
    printf("【尝试写入已释放内存】*p = 999 执行完毕，程序没崩？\n");
    printf("但此时 *p 的值是: %d （可能已经被系统分配给其他变量了！）\n", *p);
    
    // 注意：上面这两行极大概率会导致程序崩溃，如果没崩，属于“侥幸”，千万不要依赖！
    
    // =============================================
    // 实验二：malloc vs calloc（清零对比）
    // =============================================
    printf("\n========== 实验二：malloc vs calloc ==========\n");
    
    // 2.1 使用 malloc（不自动清零，内容随机）
    int *p_malloc = (int*)malloc(5 * sizeof(int));
    printf("【malloc】分配了 5 个 int，但没初始化，内容是: ");
    int i; 
    for (i = 0; i < 5; i++) {
        printf("%d ", p_malloc[i]);   // 打印出的是一堆随机垃圾值
    }
    printf("\n");
    
    // 2.2 使用 calloc（自动清零）
    int *p_calloc = (int*)calloc(5, sizeof(int));
    printf("【calloc】分配了 5 个 int，并自动清零，内容是: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", p_calloc[i]);   // 打印出的全是 0
    }
    printf("\n");
    
    // 释放所有内存（好习惯）
    free(p_malloc);
    free(p_calloc);
    
    // 把悬空指针置为 NULL，防止误用（安全操作）
    p = NULL;
    p_malloc = NULL;
    p_calloc = NULL;
    
    printf("\n所有内存已安全释放，程序结束。\n");
    return 0;
}
