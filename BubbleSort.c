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
				swap(p, p->next);
			}
			p=p->next;
		}
		end=p;
	}
	printf("冒泡排序完成！\n");
}