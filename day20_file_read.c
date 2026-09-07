#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������ͬ�Ľṹ�嶨��
struct Packet {
    char src_ip[16];
    char dest_ip[16];
    char payload[256];
    int port;
};

int main() {
    // 1. �ڶ��ϴ���һ���µĽṹ��ʵ����������Ŵ��ļ���ȡ������
    struct Packet *pkt = (struct Packet*)malloc(sizeof(struct Packet));
    if (pkt == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
        return 1;
    }

    // 2. ���������ɵ� log.txt �ļ���"r" ��ʾֻ��ģʽ��
    FILE *fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ���ȷ�� log.txt �����ڵ�ǰĿ¼��\n");
        free(pkt);
        return 1;
    }

    // 3. ���ļ���ȡ���ݣ����н�������䵽�ṹ��
    //    ע�⣺fscanf �ĸ�ʽ�ַ��������д��ʱ�� fprintf ��ʽ��ȫƥ�䣡
    //    "ԴIP: %s\n" ��ʾ����ȡ "ԴIP: " �⼸���֣�Ȼ��Ѻ�����ַ������� pkt->src_ip
    fscanf(fp, "ԴIP: %s\n", pkt->src_ip);
    fscanf(fp, "Ŀ��IP: %s\n", pkt->dest_ip);
    fscanf(fp, "�˿�: %d\n", &(pkt->port));
    fscanf(fp, "�����غ�: %[^\n]\n", pkt->payload);  // %[^\n] ��ʾ��ȡһ���У������ո�
    // �����ָ��ߣ�����еĻ���
    fscanf(fp, "------------------------\n");

    // 4. �ر��ļ�
    fclose(fp);

    // 5. ��ӡ��ȡ�������֤�Ƿ��д��ʱһ��
    printf("========== ��Ӳ�̶�ȡ�����ݰ� ==========\n");
    printf("ԴIP: %s\n", pkt->src_ip);
    printf("Ŀ��IP: %s\n", pkt->dest_ip);
    printf("�˿�: %d\n", pkt->port);
    printf("�����غ�: %s\n", pkt->payload);

    // 6. �ͷ��ڴ�
    free(pkt);
    pkt = NULL;

    printf("\n�����ѳɹ���Ӳ�ָ̻���\n");
    return 0;
}
