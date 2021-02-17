#include <stdio.h>
#include <string.h>
#include "head.h"

void BubbleSort(){
	PNode p,end;
	end=NULL;
	while(end!=head){
		p=head;
		while(p->next!=end){
			if(p->data.totalCount<p->next->data.totalCount){
				//交换 totalCount 的值 
				int tem=p->data.totalCount;
				p->data.totalCount=p->next->data.totalCount;
				p->next->data.totalCount=tem;
				//交换name 
				char name[LENGTH];
				strcpy(name,p->data.name);
				strcpy(p->data.name,p->next->data.name);
				strcpy(p->next->data.name,name);
			}
			p=p->next;
		}
		end=p;
	}
	printf("冒泡排序完成！\n");
}