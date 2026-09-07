#include <stdio.h>
#include <string.h>   // 为了使用 strcpy 复制字符串

// 1. 定义“网络数据包”的结构体（相当于设计一张快递单模板）
//    注意：这个定义告诉编译器“将来我要用这种类型的包裹”，但此刻还没分配内存。
struct Packet {
    char src_ip[16];        // 源IP地址（如 "192.168.1.100"）
    char dest_ip[16];       // 目的IP地址（如 "10.0.0.1"）
    char payload[256];      // 数据载荷（传输的内容，如 "Hello Hacker"）
    int port;               // 端口号（如 8080）
};

int main() {
    // 2. 声明一个结构体变量，此时编译器才会在栈上分配内存！
    //    相当于真正拿出一张快递单来填写。
    struct Packet pkt;
    
    // 3. 用 "." 运算符访问结构体字段，填充数据
    strcpy(pkt.src_ip, "192.168.1.100");
    strcpy(pkt.dest_ip, "10.0.0.1");
    strcpy(pkt.payload, "SYN Flood Attack Payload");
    pkt.port = 8080;
    
    // 4. 打印这个数据包的内容
    printf("========== 网络数据包内容 ==========\n");
    printf("源IP: %s\n", pkt.src_ip);
    printf("目的IP: %s\n", pkt.dest_ip);
    printf("端口: %d\n", pkt.port);
    printf("数据载荷: %s\n", pkt.payload);
    
    // 5. （网安视角）用 sizeof 查看这个结构体占多少字节
    //    注意：结果可能不是 16+16+256+4=292，因为有“内存对齐”！
    printf("\n整个结构体大小: %lu 字节\n", (unsigned long)sizeof(pkt));
    printf("（注意：由于内存对齐，可能大于各字段之和！）\n");
    
    return 0;
}
