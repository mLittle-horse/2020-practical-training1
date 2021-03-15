#include <stdio.h>
#include <string.h>
#include "head.h"

void QuickSort(){
	time_t start, stop;
	double Total_time;
	start = clock();
	
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
	stop = clock();

	printf("快速排序完成！\n");

	Total_time = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("Total_time:%f seconds\n", Total_time);
}