#include <stdio.h>
#include <string.h>
#include "head.h"

void BubbleSort(){
	time_t start, stop;
	double Total_time;
	start = clock();

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
	stop = clock();

	printf("冒泡排序完成！\n");

	Total_time = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("Total_time:%f seconds\n", Total_time);
}