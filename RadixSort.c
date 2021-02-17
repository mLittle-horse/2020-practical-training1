#include <stdio.h>
#include <string.h>
#include "head.h"

PNode arr[100005],temArr[100005];
int array_size = 0;
int cnt[10];

int maxBit();  //计算totalCount的最大位数

void RadixSort(){
	array_size=0;
	PNode p=head;
	while(p){  //将链表里的元素转到数组里 
		arr[++array_size]=p;
		p=p->next;
	}
	head=tail=NULL;
	int digit=maxBit();  //求出最长的位数
//	cout<<"digit:"<<digit<<endl;
	int base=1;
	for(int i=1;i<=digit;i++){
		//清桶 
		for(int j=0;j<=9;j++) cnt[j]=0;
		//记录每个桶中数的个数 
		for(int j=1;j<=array_size;j++){
			int tem=arr[j]->data.totalCount;
			tem/=base;
			cnt[tem%10]++;
		}
//		for(int j=0;j<=9;j++) printf("cnt[%d]=%d ",j,cnt[j]);
		//计算桶的位置 (前缀和)
		for(int j=0;j<=9;j++){
			cnt[j]+=cnt[j-1];
		} 
//		for(int j=0;j<=9;j++) printf("cnt[%d]=%d ",j,cnt[j]);
		//倒着遍历(保证稳定性)，将数加到临时数组中 
		for(int j=array_size;j>=1;j--){
			int tem=arr[j]->data.totalCount;
			tem/=base;
			temArr[cnt[tem%10]--]=arr[j];
		}
		//将临时数组转移到原数组 
		for(int j=1;j<=array_size;j++){
			arr[j]=temArr[j];
		}
		base=(base<<1)+(base<<3);
	}
	//将排序后的数据转到链表中
	while(array_size){
		InsertLinkEnd(arr[array_size--]);
	}
	printf("基排序完成！\n");
}

int maxBit(){
	int maxx=0;
	for(int i=1;i<=array_size;i++){
		int tem=arr[i]->data.totalCount;
		int tot=0;
		while(tem){
			tem/=10;
			tot++;
		}
		maxx=tot>maxx?tot:maxx;
	}
	return maxx;
}