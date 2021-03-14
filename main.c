#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "head.h"

void TestLink();
void TestBST();
void TESTAVL();
void TestHash();

char wholeName[100005][LENGTH];
int totalCount = 0;

int main(){
	TestLink();
	// TestBST();
	TESTAVL();
	// TestHash();
	return 0;
}

void TestLink(){
	ReadFromFile();
	// Display();
	// DeleteRecord();
	// Display();
	// InputRecord();
	// Display();
	// Destroy();
	// Display();
	MergeListNode();
	// Display();
	// WriteToFile();

	///////////////////////////将所有的名字整合到wholeName数组中///////////////////////////
	PNode p = head;
	totalCount = 0;
	while(p){
		strcpy(wholeName[++totalCount], p->data.name);
		p = p->next;
	}
	//遍历一下数组
	// printf("index:%d\n", index);
	// for (int i = 1; i <= index;i++){
	// 	printf("%s\n", wholeName[i]);
	// }
	// printf("index:%d\n", index);


	/////////排序//////////
	//	BubbleSort();
	//	QuickSort();
	//	HeapSort();
	//	RadixSort();

	//	QSort();
	//	Display();
}

void TestBST(){
	///////////二叉搜索树/////////////
	CreateBST();
	// printf("先序遍历结果如下：\n");
	// PreOrderTraverse(Tree._pRoot);
	printf("中序遍历结果如下：\n");
	InOrderTraverse(Tree._pRoot);
	// printf("后序遍历结果如下：\n");
	// PostOrderTraverse(Tree._pRoot);

	// DeleteTreeNode();
	// printf("中序遍历结果如下：\n");
	// InOrderTraverse(Tree._pRoot);

	// AddTreeNode();
	// printf("中序遍历结果如下：\n");
	// InOrderTraverse(Tree._pRoot);

	// char name[LENGTH];
	// printf("请输入想要查询登录次数的用户名：");
	// scanf("%s", name);
	// int num = SearchTimesByName(name);
	// if(num!=0){
	// 	printf("登录次数：%d", num);
	// }
}

void TESTAVL(){
	clock_t start, end;
	double Total_time;
	///////////平衡二叉树/////////////
	
	CreateAVLTree();

	SDataType data;
	// char name[LENGTH];
	
	//遍历
	// printf("先序遍历结果如下：\n");
	// PreOrderTraverseAVL(ATree._pRoot);
	// printf("中序遍历结果如下：\n");
	// InOrderTraverseAVL(ATree._pRoot);
	// printf("后序遍历结果如下：\n");
	// PostOrderTraverseAVL(ATree._pRoot);

	//删除
	// printf("请输入想要删除的用户名：");
	// scanf("%s", name);
	// strcpy(data.name, name);
	// ATree._pRoot = DeleteAVLTreeNode(ATree._pRoot, data);
	// printf("删除后先序遍历结果如下：\n");
	// PreOrderTraverseAVL(ATree._pRoot);

	//查找
	// printf("请输入想要查询登录次数的用户名：");
	// scanf("%s", name);
	// strcpy(data.name, name);
	// int num = SearchTimesByNameInAVL(ATree._pRoot, data);
	// if(num==0){
	// 	printf("没有找到该用户信息！\n");
	// 	printf("按回车返回！\n");
	// }
	// else printf("登录次数：%d", num);

	//查询所有用户名以测时间
	start = clock();
	for (int i = 1; i < totalCount;i++){
		strcpy(data.name, wholeName[i]);
		int num = SearchTimesByNameInAVL(ATree._pRoot, data);
		printf("%s ---", data.name);
		if(num==0){
			printf("没有找到该用户信息！\n");
		}
		else printf("登录次数：%d\n", num);
	}
	end = clock();
	Total_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Total_time:%f seconds\n", Total_time);
}

void TestHash(){
	clock_t start, end;
	double Total_time;
	///////////哈希表/////////////
	

	PHashTable pHashtable = &hashtable;
	InitHashTable(pHashtable, 1000, 31);
	
	SDataType data;
	// char name[LENGTH];

	//从文件读入数据创建哈希表
	CreateHashTable(pHashtable);

	//////////插入数据
	// printf("请输入用户名：\n");
	// while(~scanf("%s",name)){
	// 	strcpy(data.name, name);
	// 	data.totalCount = 1;
	// 	InsertHashNode(pHashtable, data);
	// }

	//////////遍历
	// printf("遍历如下:\n");
	// TraverseHashTable(pHashtable);

	//////////删除
	// printf("请输入待删除的用户名：\n");
	// scanf("%s", name);
	// strcpy(data.name, name);
	// DeleteHashNode(pHashtable, data);
	//遍历
	// printf("遍历如下:\n");
	// TraverseHashTable(pHashtable);

	//////////查询
	// printf("请输入想要查询登录次数的用户名：");
	// scanf("%s", name);
	// strcpy(data.name, name);
	// int num = SearchTimesByNodeInHash(pHashtable, data);
	// if(num==0){
	// 	printf("没有找到该用户信息！\n");
	// 	printf("按回车返回！\n");
	// }
	// else printf("登录次数：%d\n", num);

	//查询所有用户名以测时间
	start = clock();
	for (int i = 1; i < totalCount;i++){
		strcpy(data.name, wholeName[i]);
		int num = SearchTimesByNodeInHash(pHashtable, data);
		printf("%s ---", data.name);
		if(num==0){
			printf("没有找到该用户信息！\n");
		}
		else printf("登录次数：%d\n", num);
	}
	end = clock();
	Total_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Total_time:%f seconds\n", Total_time);
}