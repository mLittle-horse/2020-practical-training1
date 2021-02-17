//将单链表中的节点输出到文件 result.txt 中
#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void WriteToFile(){
	FILE *fp;
	fp = fopen("C:\\mxp\\GitHub_repo\\2020-practical-training1\\result.txt","w"); 
	if(fp==NULL){
		printf("提示：文件不存在！无法保存信息\n");
		printf("请按回车键返回.");
		getchar();getchar();
		return ;
	}
	PNode p = head;
	while(p){
		fprintf(fp, "%s,%d\n", p->data.name, p->data.totalCount);
		p = p->next;
	}
	fclose(fp);
	printf("该信息已成功保存至文件!\n");
	printf("请按回车键继续！");
	getchar();
}
