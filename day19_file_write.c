#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Packet {
    char src_ip[16];
    char dest_ip[16];
    char payload[256];
    int port;
};

int main() {
    struct Packet *pkt = (struct Packet*)malloc(sizeof(struct Packet));
    if (pkt == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    strcpy(pkt->src_ip, "192.168.1.100");
    strcpy(pkt->dest_ip, "10.0.0.1");
    strcpy(pkt->payload, "First log entry: SYN scan detected.");
    pkt->port = 8080;

    FILE *fp = fopen("log.txt", "a");
    
    if (fp == NULL) {
        printf("文件打开失败！请检查磁盘空间或权限。\n");
        free(pkt); 
        return 1;
    }

    fprintf(fp, "源IP: %s\n", pkt->src_ip);
    fprintf(fp, "目的IP: %s\n", pkt->dest_ip);
    fprintf(fp, "端口: %d\n", pkt->port);
    fprintf(fp, "数据载荷: %s\n", pkt->payload);
    fprintf(fp, "------------------------\n");  

    fclose(fp);

    free(pkt);
    pkt = NULL;

    printf("数据已成功写入 log.txt 文件！\n");
    printf("请用记事本打开当前目录下的 log.txt 查看。\n");

    return 0;
}
