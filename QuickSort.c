#include <stdio.h>
#include <string.h>
#include "head.h"

void QuickSort(){
	PNode now,p;
	now=head;
	while(now){
		p=now->next;
		PNode maxx=now;
		while(p){
			if(p->data.totalCount>maxx->data.totalCount) maxx=p;
			p=p->next;
		}
		if(maxx!=now){
			//交换 totalCount 的值 
			int tem=now->data.totalCount;
			now->data.totalCount=maxx->data.totalCount;
			maxx->data.totalCount=tem;
			//交换name
			char name[LENGTH];
			strcpy(name,now->data.name);
			strcpy(now->data.name,maxx->data.name);
			strcpy(maxx->data.name,name);
		}
		now=now->next;
	}
	printf("快速排序完成！\n");
}