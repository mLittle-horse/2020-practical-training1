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
		p = (PTreeNode)malloc(sizeof(TreeNode));
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


void DeleteTreeNode(){
	if(Tree._pRoot==NULL){
		printf("此时没有存储信息！\n");
		printf("按回车返回！\n");
		getchar();
		return;
	}
	else{
		printf("请输入想要删除的用户名：");
		char name[LENGTH];
		scanf("%s", name);
		PTreeNode now = Tree._pRoot,fa=Tree._pRoot;  //now为待删结点，fa为其父亲
		int direction;   //0：左边    1：右边
		while(now){
			if(strcmp(name,now->_data.name)==0){
				break;
			}
			else if(strcmp(name,now->_data.name)<0){
				fa = now;
				now = now->_Pleft;
				direction = 0;
			}
			else{
				fa = now;
				now = now->_Pright;
				direction = 1;
			}
		}
		if(!now){
			printf("没有找到该用户的信息！\n");
			printf("请按回车返回！\n");
			return;
		}
		else{
			if(now->_Pleft==NULL&&now->_Pright==NULL){   //左右子树都为空
				if(now==Tree._pRoot){   //说明只有这一个结点
					Tree._pRoot = NULL;
					return;
				}
				if(direction==0){
					fa->_Pleft = NULL;
				}
				else{
					fa->_Pright = NULL;
				}
			}
			else if(now->_Pleft==NULL){   //仅左子树为空,就把其右子树接到父亲上
				if(now==Tree._pRoot){
					Tree._pRoot = now->_Pright;
					return;
				}
				if(direction==0){
					fa->_Pleft = now->_Pright;
				}
				else{
					fa->_Pright = now->_Pright;
				}
			}
			else if(now->_Pright==NULL){  //仅右子树为空，就把其左子树接到父亲上
				if(now==Tree._pRoot){
					Tree._pRoot = now->_Pright;
					return ;
				}
				if(direction==0){
					fa->_Pleft = now->_Pleft;
				}
				else{
					fa->_Pright = now->_Pleft;
				}
			}
			else{   //左右子树都不为空
				//要找到now的右子树的最左下结点和now替换,下面的nex即为now的后继
				PTreeNode nex = now->_Pright;
				if(nex->_Pleft==NULL){ //其左子树为空，则其为now的后继
					nex->_Pleft = now->_Pleft;
					if(direction==0){
						fa->_Pleft = nex;
					}
					else{
						fa->_Pright = nex;
					}
					if(now==Tree._pRoot)   //考虑如果new为根，需要修改
						Tree._pRoot = nex;
				}
				else{  //nex左子树不空，就顺着左边一直走到底
					PTreeNode nex_fa;
					while(nex->_Pleft){
						nex_fa = nex;
						nex = nex->_Pleft;
					}
					nex_fa->_Pleft = NULL;
					//这里要将之前now的一些关系转移给nex
					nex->_Pleft = now->_Pleft;
					nex->_Pright = now->_Pright;
					if(direction==0){
						fa->_Pleft = nex;
					}
					else{
						fa->_Pright = nex;
					}
					if(now==Tree._pRoot)
						Tree._pRoot = nex;
				}
			}
			printf("删除结点：%s,%d\n", now->_data.name, now->_data.totalCount);
			free(now);
		}
	}
}

void AddTreeNode(){
	printf("请输入要添加的用户名：");
	char name[LENGTH];
	scanf("%s", name);
	PTreeNode p = (PTreeNode)malloc(sizeof(TreeNode));
	strcpy(p->_data.name, name);
	p->_data.totalCount = 1;
	p->_Pleft = p->_Pright = NULL;
	InsertTreeNode(p);
}


int SearchTimesByName(char name[]){
	if(Tree._pRoot==NULL){
		printf("此时没有存储信息,无法查找！\n");
		printf("按回车返回！\n");
		getchar();
		return 0;
	}
	PTreeNode now = Tree._pRoot;
	while(now){
		if(strcmp(name,now->_data.name)==0){
			return now->_data.totalCount;
		}
		else if(strcmp(name,now->_data.name)<0){
			now = now->_Pleft;
		}
		else{
			now = now->_Pright;
		}
	}
	printf("没有找到该用户信息！\n");
	printf("按回车返回！\n");
	getchar();
	getchar();
	return 0;
}
