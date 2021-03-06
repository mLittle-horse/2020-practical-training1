#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

PNode head, tail;    //定义链表头、尾的全局变量

void InsertLinkEnd(PNode p){
	if(p==NULL)
		return;
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
	printf("请按回车键继续!");
	getchar();
}

void DeleteNode(PNode p,PNode pre){
	if(p==head){
		head = p->next;
	}
	else{
		pre->next = p->next;
		if(p==tail)
			tail = pre;
	}
	free(p);
}

void DeleteRecord(){
	if(head==NULL){
		printf("没有信息，请先存入登录信息！");
		return ;
	}
//	Display();
	PNode p = NULL, pre = NULL;
	printf("请输入想要删除的姓名:");
	char name[LENGTH];
	scanf("%s", name);
	while (1)
	{
		p = head;
		int findFlag = 0;
		while(p){
			if(!strcmp(p->data.name,name)){
				findFlag = 1;
				printf("找到该登录信息如下：\n");
				printf("\t姓名\t登录次数\n");
				printf("\t%s\t%d\n",p->data.name,p->data.totalCount);
				printf("确认要删除吗？[y/n]");
				char ch;
				scanf(" %c",&ch);
				if(ch=='y'||ch=='Y'){
					DeleteNode(p,pre);
				}
				else{
					printf("你选择不删除信息！\n\n");
				}
				break;
			}
			pre = p;
			p = p->next;
		}
		if(findFlag==1)
			break;
		else{
			printf("没有找到该用户信息，请重新输入！\n");
			printf("新的姓名：");
			scanf("%s",name);
		}
	}
	printf("请按回车继续!");
	getchar();
	getchar();
}

void InputRecord(){
	PNode p;
	while(1){
		p = (PNode)malloc(LEN);
		printf("输入待添加信息(格式：姓名,登录时间)：");
		char message[LENGTH << 1], name[LENGTH];
		scanf("%s", message);
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
		printf(">>>>>>>>>>提示：新的结点已经添加完毕，是否要继续添加？[y/n]");
		char ch;
		scanf(" %c", &ch);
		switch(ch){
			case 'y':
			case 'Y':
				break;
			default:
				return;
		}
	}
	printf("请按回车键继续!");
	getchar();
	getchar();
}

void Destroy(){
	PNode p = head;
	while(p){
		PNode tem = p->next;
//		printf("%s已销毁\n", p->data.name);   //验证是否销毁
		free(p);
		p = NULL;
		p = tem;
	}
	head = tail = NULL;
}

void MergeListNode(){
	PNode p = head;
	while(p){
		PNode now = p->next, pre = p;
		int cnt=1;
		while(now){
			if(!strcmp(now->data.name,p->data.name)){
				cnt++;
				DeleteNode(now, pre);
				now = pre->next;
			}
			else{
				now = now->next, pre = pre->next;
			}
		}
		p->data.totalCount = cnt;
		p = p->next;
	}
	printf("结点合并完成！\n");
	printf("按回车继续！\n");
	getchar();
}

void swap(PNode x,PNode y){
	//交换 totalCount 的值 
	int tem=x->data.totalCount;
	x->data.totalCount=y->data.totalCount;
	y->data.totalCount=tem;
	//交换name
	char name[LENGTH];
	strcpy(name,x->data.name);
	strcpy(x->data.name,y->data.name);
	strcpy(y->data.name,name);
}