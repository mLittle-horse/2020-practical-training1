#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void TestLink();
void TestBST();
void TESTAVL();
void TestHash();

int main(){
	// TestLink();
	// TestBST();
	// TESTAVL();
	TestHash();
	return 0;
}

void TestLink(){
	// ReadFromFile();
	// Display();
	// DeleteRecord();
	// Display();
	// InputRecord();
	// Display();
	// Destroy();
	// Display();
	// MergeListNode();
	// Display();
	// WriteToFile();

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
	///////////平衡二叉树/////////////
	CreateAVLTree();
	
	//遍历
	printf("先序遍历结果如下：\n");
	PreOrderTraverseAVL(ATree._pRoot);
	// printf("中序遍历结果如下：\n");
	// InOrderTraverseAVL(ATree._pRoot);
	// printf("后序遍历结果如下：\n");
	// PostOrderTraverseAVL(ATree._pRoot);

	//删除
	SDataType data;
	printf("请输入想要删除的用户名：");
	char name[LENGTH];
	scanf("%s", name);
	strcpy(data.name, name);
	ATree._pRoot = DeleteAVLTreeNode(ATree._pRoot, data);
	printf("删除后先序遍历结果如下：\n");
	PreOrderTraverseAVL(ATree._pRoot);

	//查找
	printf("请输入想要查询登录次数的用户名：");
	scanf("%s", name);
	strcpy(data.name, name);
	int num = SearchTimesByNameInAVL(ATree._pRoot, data);
	if(num==0){
		printf("没有找到该用户信息！\n");
		printf("按回车返回！\n");
	}
	else printf("登录次数：%d", num);
}

void TestHash(){
	PHashTable pHashtable = &hashtable;
	InitHashTable(pHashtable, 1000, 31);
	//////////插入数据
	SDataType data;
	char name[LENGTH];
	printf("请输入用户名：\n");
	while(~scanf("%s",name)){
		strcpy(data.name, name);
		data.totalCount = 1;
		InsertHashNode(pHashtable, data);
	}

	//////////遍历
	printf("遍历如下:\n");
	TraverseHashTable(pHashtable);

	//////////删除
	printf("请输入待删除的用户名：\n");
	scanf("%s", name);
	strcpy(data.name, name);
	DeleteHashNode(pHashtable, data);
	//遍历
	printf("遍历如下:\n");
	TraverseHashTable(pHashtable);


}