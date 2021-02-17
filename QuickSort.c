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
			swap(now, maxx);
		}
		now=now->next;
	}
	printf("快速排序完成！\n");
}