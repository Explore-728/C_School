#include <stdio.h>

int main() {
    // 1. 定义两个“邻居”变量
    //    把 secret 放在数组前面，看看数组越界后能不能找到它并篡改它
    int secret = 0;          // 假设这是“管理员权限开关”（0=普通，1=管理员）
    int arr[5] = {10, 20, 30, 40, 50};  // 只有 5 个房间，编号 0~4
    
    printf("【越界前检查】\n");
    printf("secret 的值: %d (0表示普通用户)\n", secret);
    printf("arr[0] 的值: %d\n", arr[0]);
    printf("arr[4] 的值: %d\n\n", arr[4]);
    
    // 2. ！！！ 高危操作 ！！！ 强行越界写入
    
    // 尝试一：越界写入 arr[5]（这是数组后面的第 1 个位置）
    printf("【执行 arr[5] = 999】...\n");
    arr[5] = 999;
    printf("写入完成，程序还没崩？\n");
    
    // 尝试二：越界写入 arr[6]（再往后走一个位置）
    printf("【执行 arr[6] = 888】...\n");
    arr[6] = 888;
    printf("写入完成，程序居然还在跑？\n");
    
    // 3. 检查隔壁的 secret 变量有没有被覆盖！
    printf("\n【检查隔壁邻居】\n");
    printf("现在的 secret 值变成了: %d ", secret);
    if (secret == 999 || secret == 888) {
        printf("?? 警告！secret 被越界数据篡改了！\n");
    } else {
        printf("(secret 暂时安全)\n");
    }
    
    // 4. 来个狠的，直接跳到 100 号位置（远超出你的内存地盘）
    printf("\n【执行 arr[100] = 12345】...\n");
    // 复习：越界踩红线，操作系统会直接枪毙程序（Segmentation fault）。
    arr[100] = 12345;
    printf("如果看到这行，说明你的电脑在硬撑，但大概率已经崩了...\n");
    
    system("pause");  
    
    return 0;
}
