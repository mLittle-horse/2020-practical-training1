//这里要求从大到小排，即大顶堆
#include <stdio.h>
#include <string.h>
#include "head.h"

PNode heap[100005];
int heap_size = 0;

void insert(PNode p);  //向堆中插入元素
PNode del();  //从堆中删除元素并返回

void HeapSort(){
	time_t start, stop;
	double Total_time;
	start = clock();

	PNode p = head;
	while(p){
		insert(p);
		p = p->next;
	}
	head = tail = NULL;
	while(heap_size){
		InsertLinkEnd(del());
	}
	stop = clock();

	printf("堆排序完成！\n");

	Total_time = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("Total_time:%f seconds\n", Total_time);
}

void insert(PNode p){
	heap[++heap_size] = p;
	int now, nex;
	now = heap_size;
	while(now>1){
		nex = now >> 1;
		if(heap[nex]->data.totalCount>=heap[now]->data.totalCount)
			return;
		swap(heap[nex], heap[now]);
		now = nex;
	}
}

PNode del(){
	PNode ans = heap[1];
	heap[1] = heap[heap_size--];
	int now, nex;
	now = 1;
	while(now<=heap_size/2){
		nex = now << 1;
		if(nex+1<=heap_size&&heap[nex]->data.totalCount<heap[nex+1]->data.totalCount)
			nex++;
		swap(heap[now], heap[nex]);
		now = nex;
	}
	return ans;
}