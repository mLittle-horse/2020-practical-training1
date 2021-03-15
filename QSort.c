#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

PNode brr[100005];
int brr_size = 0;

void QSort(){
	time_t start, stop;
	double Total_time;
	start = clock();

	PNode p=head;
	while(p){
		brr[brr_size++] = p;
		p = p->next;
	}
	qsort(brr, brr_size, sizeof(PNode), compare);
	head = tail = NULL;
	while(--brr_size>=0){
		InsertLinkEnd(brr[brr_size]);
	}
	stop = clock();

	printf("改进版快速排序完成！\n");

	Total_time = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("Total_time:%f seconds\n", Total_time);
}

/**
 * qsort函数包含在C 标准库 - <stdlib.h>
 * int compare(const void *p1, const void *p2);
 * 如果compare返回值小于0（< 0），那么p1所指向元素会被排在p2所指向元素的左面；
 * 如果compare返回值等于0（= 0），那么p1所指向元素与p2所指向元素的顺序不确定；
 * 如果compare返回值大于0（> 0），那么p1所指向元素会被排在p2所指向元素的右面。
 * int 类型的compare函数如下
int comp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
*/
int compare(const void *pa,const void *pb){
//	return (*(PNode)pa).data.totalCount - (*(PNode)pb).data.totalCount;    //对Node类型排序的
	return (*((PNode *)pa))->data.totalCount - (*((PNode *)pb))->data.totalCount; //对PNode类型排序的
}