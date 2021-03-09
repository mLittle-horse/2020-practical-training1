#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

BST Tree;

void CreateBST(){
	Tree._pRoot = NULL;
	FILE *fp;
	fp = fopen("C:\\mxp\\GitHub_repo\\2020-practical-training1\\in.txt", "r");
	if(fp==NULL){
		printf("提示：文件不存在！无法录入信息\n");
		printf("请按回车键返回.");
		getchar();getchar();
		return ;
	}
	PTreeNode p;
	char message[LENGTH << 1], name[LENGTH];
	while(!feof(fp)){
		p = (PTreeNode)malloc(LEN);
		fscanf(fp, "%s", message);
		int index = 0;
		for (int i = 0; i < strlen(message);i++){
			if(message[i]==','){
				break;
			}
			name[index++] = message[i];
		}
		name[index++] = '\0';
		strcpy(p->_data.name, name);
		p->_data.totalCount = 1;
		p->_Pleft = p->_Pright = NULL;
		InsertTreeNode(p);
	} 
	fclose(fp);
	printf("信息读取成功,建立二叉搜索树！\n");
	printf("按回车继续！\n");
	getchar();
}

void InsertTreeNode(PTreeNode p){
	if(p==NULL)
		return;
	if(Tree._pRoot==NULL){
		Tree._pRoot = p;
		return;
	}
	else{
		PTreeNode now = Tree._pRoot,fa=Tree._pRoot;
		int direction = 0;
//		printf("**%s\n", Tree._pRoot->_data.name);
		while(now){
			fa = now;
//			printf("p:%s  %d\n", p->_data.name, p->_data.totalCount);
			if(strcmp(p->_data.name,now->_data.name)==0){  //找到了，次数累加
				now->_data.totalCount++;
//				printf("find:%d", now->_data.totalCount);
				return;
			}
			else if(strcmp(p->_data.name,now->_data.name)<0){  //往左子树走
				now = now->_Pleft;
				direction = 0;
//				printf("left\n");
			}
			else{  //往右子树走
				now = now->_Pright;
				direction = 1;
//				printf("right\n");
			}
		}
		if(direction==0){
			fa->_Pleft = p;
			return;
		}
		else{
			fa->_Pright = p;
			return;
		}
	}
}

void PreOrderTraverse(PTreeNode T){
	if(!T)
		return;
	else{
		printf("%s,%d\n",T->_data.name,T->_data.totalCount);
		PreOrderTraverse(T->_Pleft);
		PreOrderTraverse(T->_Pright);
	}
}

void InOrderTraverse(PTreeNode T){
	if(!T)
		return;
	else{
		InOrderTraverse(T->_Pleft);
		printf("%s,%d\n",T->_data.name,T->_data.totalCount);
		InOrderTraverse(T->_Pright);
	}
}

void PostOrderTraverse(PTreeNode T){
	if(!T)
		return;
	else{
		PostOrderTraverse(T->_Pleft);
		PostOrderTraverse(T->_Pright);
		printf("%s,%d\n",T->_data.name,T->_data.totalCount);
	}
}


