#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

PNode head, tail;    //定义链表头、尾的全局变量

void InsertLinkEnd(PNode p){
	if(head==NULL){
		head = tail = p;
		tail->next = NULL;
		return;
	}
	else{
		tail->next = p;
		tail = p;
		tail->next = NULL;
	}
}

void Display(){
	if(head==NULL){
		printf("当前没有信息，请先存入登录信息！");
		return ;
	}
	PNode p = head;
	printf("当前有登录信息如下：\n");
	while (p)
	{
		printf("%s,%d\n",p->data.name,p->data.totalCount);
		p=p->next;
	}
	printf("\n");
	printf("请按回车键返回!");
	getchar();
}


