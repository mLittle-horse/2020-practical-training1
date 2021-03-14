//该文件负责读入 user_login.txt 中内容保存到单链表中
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void ReadFromFile(){
	FILE *fp;
//	fp = fopen("in.txt","r");
	fp = fopen("user_login.txt", "r");
	if(fp==NULL){
		printf("提示：文件不存在！无法录入信息\n");
		printf("请按回车键返回.");
		getchar();getchar();
		return ;
	}
	PNode p;
	char message[LENGTH << 1], name[LENGTH];
	while (!feof(fp))
	{
		p = (PNode)malloc(LEN);
		fscanf(fp, "%s", message);
		int index = 0;
		for (int i = 0; i < strlen(message);i++){
			if(message[i]==',')
				break;
			name[index++] = message[i];
		}
		name[index] = '\0';
		strcpy(p->data.name, name);
		p->data.totalCount = 1;
		InsertLinkEnd(p);
	}
	fclose(fp);
	printf("信息读取成功！\n");
	printf("按回车继续！\n");
	getchar();
}