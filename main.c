#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

int main(){
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

	char name[LENGTH];
	printf("请输入想要查询登录次数的用户名：");
	scanf("%s", name);
	int num = SearchTimesByName(name);
	if(num!=0){
		printf("登录次数：%d", num);
	}
	return 0;
}