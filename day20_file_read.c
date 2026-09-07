#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 复用相同的结构体定义
struct Packet {
    char src_ip[16];
    char dest_ip[16];
    char payload[256];
    int port;
};

int main() {
    // 1. 在堆上创建一个新的结构体实例，用来存放从文件读取的数据
    struct Packet *pkt = (struct Packet*)malloc(sizeof(struct Packet));
    if (pkt == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    // 2. 打开昨天生成的 log.txt 文件（"r" 表示只读模式）
    FILE *fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("文件打开失败！请确认 log.txt 存在于当前目录。\n");
        free(pkt);
        return 1;
    }

    // 3. 从文件读取数据，按行解析并填充到结构体
    //    注意：fscanf 的格式字符串必须和写入时的 fprintf 格式完全匹配！
    //    "源IP: %s\n" 表示：读取 "源IP: " 这几个字，然后把后面的字符串存入 pkt->src_ip
    fscanf(fp, "源IP: %s\n", pkt->src_ip);
    fscanf(fp, "目的IP: %s\n", pkt->dest_ip);
    fscanf(fp, "端口: %d\n", &(pkt->port));
    fscanf(fp, "数据载荷: %[^\n]\n", pkt->payload);  // %[^\n] 表示读取一整行（包括空格）
    // 跳过分割线（如果有的话）
    fscanf(fp, "------------------------\n");

    // 4. 关闭文件
    fclose(fp);

    // 5. 打印读取结果，验证是否和写入时一致
    printf("========== 从硬盘读取的数据包 ==========\n");
    printf("源IP: %s\n", pkt->src_ip);
    printf("目的IP: %s\n", pkt->dest_ip);
    printf("端口: %d\n", pkt->port);
    printf("数据载荷: %s\n", pkt->payload);

    // 6. 释放内存
    free(pkt);
    pkt = NULL;

    printf("\n数据已成功从硬盘恢复！\n");
    return 0;
}
