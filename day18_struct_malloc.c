#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 struct Packet{
 	char src_ip[16];
 	char dest_ip[16];
 	char payload[256];
 	int port;
 };
 
 int main(){
 	struct Packet *pkt = (struct Packet*)malloc(sizeof(struct Packet));
 	if(pkt == NULL){
 		printf("内存申请失败！\n");
 		return 1;
	 }
	 strcpy(pkt->src_ip,"192.168.1.100");
	 strcpy(pkt->dest_ip,"10.0.0.1");
	 strcpy(pkt->payload,"SYN Flood Arrack Payload from Heao!");
	 pkt->port = 8080;
	 
	printf("源IP：%s\n",pkt->src_ip);
	printf("目的IP：%s\n",pkt->dest_ip);
	printf("端口：%d\n",pkt->port);
	printf("数据载荷：%s\n",pkt->payload);
	
	printf("\n结构体在堆上的地址：%p\n",pkt);
	
	printf("src_ip 的地址：%p\n",&(pkt->src_ip));
	printf("dest_ip 的地址：%p\n",&(pkt->dest_ip));
	printf("payload 的地址：%p\n",&(pkt->payload));
	printf("port 的地址：%p\n",&(pkt->port));
	
	free(pkt);
	
	pkt = NULL;
	
	printf("\n内存已安全释放，程序结束。\n");
	return 0;
	
 }
