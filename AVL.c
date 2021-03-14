#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

AVL ATree;

//直接通过文件读取建树
void CreateAVLTree(){
	FILE *fp;
//	fp = fopen("in.txt", "r");
	fp = fopen("user_login.txt", "r");
	if(fp==NULL){
		printf("提示：文件不存在！无法录入信息\n");
		printf("请按回车键返回.");
		getchar();getchar();
		return ;
	}
	SDataType data;
	char message[LENGTH << 1], name[LENGTH];
	while(!feof(fp)){
		fscanf(fp, "%s", message);
		int index = 0;
		for (int i = 0; i < strlen(message);i++){
			if(message[i]==',')
				break;
			name[index++] = message[i];
		}
		name[index] = '\0';
		strcpy(data.name, name);
		data.totalCount = 1;
		ATree._pRoot = InsertAVLTreeNode(ATree._pRoot, data);
		// printf("先序遍历结果如下：\n");
		// PreOrderTraverseAVL(ATree._pRoot);
	}
	fclose(fp);
	printf("信息读取成功！建立平衡二叉树！\n");
	printf("按回车继续！\n");
	getchar();
}

PAVLTreeNode CreatAVLNode(SDataType data){
	PAVLTreeNode tem = (PAVLTreeNode)malloc(sizeof(AVLTreeNode));
	tem->_Pleft = tem->_Pright = NULL;
	tem->height = 1;
	tem->_data = data;
	return tem;
}

//返回ab中的较大值
int Max(int a,int b){
	return a > b ? a : b;
}

//求p结点所在的高度
int high(PAVLTreeNode p){
	if(p==NULL)
		return 0;
	else
		return p->height;
}

//求p结点的平衡因子
int GetBalance(PAVLTreeNode p){
	if(p==NULL)
		return 0;
	else
		return high(p->_Pleft) - high(p->_Pright);
}

//将p结点左旋，并返回左旋后的根指针
PAVLTreeNode l_rotate(PAVLTreeNode p){
	PAVLTreeNode l = p->_Pleft;
	p->_Pleft = l->_Pright;
	l->_Pright = p;
	//注意旋转操作之后一定要记得修改结点高度
	//这里因为将l转为p的父亲，所以要自下而上更新，即先更新p，再更新l
	p->height = Max(high(p->_Pleft), high(p->_Pright)) + 1;
	l->height = Max(high(l->_Pleft), high(l->_Pright)) + 1;
	return l;
}

//将p结点右旋，并返回右旋后的根指针
PAVLTreeNode r_rotate(PAVLTreeNode p){
	PAVLTreeNode r = p->_Pright;
	p->_Pright = r->_Pleft;
	r->_Pleft = p;
	//注意旋转操作之后一定要记得修改结点高度
	//这里因为将l转为p的父亲，所以要自下而上更新，即先更新p，再更新r
	p->height = Max(high(p->_Pleft), high(p->_Pright)) + 1;
	r->height = Max(high(r->_Pleft), high(r->_Pright)) + 1;
	return r;
}

PAVLTreeNode InsertAVLTreeNode(PAVLTreeNode now,SDataType data){
	if(now==NULL){
		return CreatAVLNode(data);
	}
	else{
		if(strcmp(data.name,now->_data.name)<0){  //往左走
			now->_Pleft = InsertAVLTreeNode(now->_Pleft, data);
		}
		else if(strcmp(data.name,now->_data.name)>0){	//往右走
			now->_Pright = InsertAVLTreeNode(now->_Pright, data);
		}
		else{  //找到了，将登陆次数累加
			now->_data.totalCount += data.totalCount;
			return now;
		}
	}
	//当结点插入成功后，递归回溯时，要检查每一个点的平衡因子的绝对值是否<1，否则需要旋转
	//首先更新一下当前节点的高度
	now->height = Max(high(now->_Pleft), high(now->_Pright)) + 1;
	int balance = GetBalance(now);
	if(balance>1&&strcmp(data.name,now->_Pleft->_data.name)<0){	 //LL
		return l_rotate(now);
	}
	if(balance>1&&strcmp(data.name,now->_Pleft->_data.name)>0){  //LR
		PAVLTreeNode tem = r_rotate(now->_Pleft);
		now->_Pleft = tem;
		return l_rotate(now);
	}
	if(balance<-1&&strcmp(data.name,now->_Pright->_data.name)>0){  //RR
		return r_rotate(now);
	}
	if(balance<-1&&strcmp(data.name,now->_Pright->_data.name)<0){  //RL
		PAVLTreeNode tem = l_rotate(now->_Pright);
		now->_Pright = tem;
		return r_rotate(now);
	}
	return now;   //如果插入节点后仍然是平衡的就返回即可
}


void PreOrderTraverseAVL(PAVLTreeNode T){
	if(T==NULL){
		return;
	}
	else{
		printf("height:%d	", T->height);
		printf("%s,%d\n",T->_data.name,T->_data.totalCount);
		PreOrderTraverseAVL(T->_Pleft);
		PreOrderTraverseAVL(T->_Pright);
	}
}

void InOrderTraverseAVL(PAVLTreeNode T){
	if(T==NULL){
		return;
	}
	else{
		InOrderTraverseAVL(T->_Pleft);
		printf("height:%d	", T->height);
		printf("%s,%d\n",T->_data.name,T->_data.totalCount);
		InOrderTraverseAVL(T->_Pright);
	}
}

void PostOrderTraverseAVL(PAVLTreeNode T){
	if(T==NULL){
		return;
	}
	else{
		PostOrderTraverseAVL(T->_Pleft);
		PostOrderTraverseAVL(T->_Pright);
		printf("height:%d	", T->height);
		printf("%s,%d\n",T->_data.name,T->_data.totalCount);
	}
}

//递归删除now子树中的值为data的结点并返回删除后的子树根节点
PAVLTreeNode DeleteAVLTreeNode(PAVLTreeNode now, SDataType data){
	if(now==NULL){
//		printf("没有找到该用户的信息，无法删除！\n");
		return NULL;
	}
	else if(strcmp(data.name,now->_data.name)<0){  //左子树
		now->_Pleft = DeleteAVLTreeNode(now->_Pleft, data);
	}
	else if(strcmp(data.name,now->_data.name)>0){  //右子树
		now->_Pright = DeleteAVLTreeNode(now->_Pright, data);
	}
	else{  //找到了相同值的结点，删除
		if(now->_Pleft==NULL||now->_Pright==NULL){
//			printf("删除结点：%s,%d\n", now->_data.name, now->_data.totalCount);
			PAVLTreeNode tem = now->_Pleft == NULL ? now->_Pright : now->_Pleft;
			if(tem==NULL){  //说明该结点是叶子结点，左右子树均为空，直接删除即可
				free(now);
				now = NULL;
			}
			else{
				free(now);
				now = tem;  //直接让其唯一的一个儿子来当根节点
			}
		}
		else{  //now结点的左右子树都存在
			//首先找到后继结点
			PAVLTreeNode nex = now->_Pright;
			while(nex->_Pleft){
				nex = nex->_Pleft;
			}
			now->_data = nex->_data;  //用后继结点来代替now，这里采用将nex的值给now，然后将nex结点删去的方法
			now->_Pright = DeleteAVLTreeNode(now->_Pright, nex->_data);
		}
	}
	if(now==NULL)
		return now;
	//接着判断该结点是否平衡
	now->height = Max(high(now->_Pleft), high(now->_Pright)) + 1;
	int balance = GetBalance(now);
	if(balance>1&&GetBalance(now->_Pleft)>=0){  //LL
		return l_rotate(now);
	}
	if(balance>1&&GetBalance(now->_Pleft)<0){  //LR
		PAVLTreeNode tem = r_rotate(now->_Pleft);
		now->_Pleft = tem;
		return l_rotate(now);
	}
	if(balance<-1&&GetBalance(now->_Pright)<=0){  //RR
		return r_rotate(now);
	}
	if(balance<-1&&GetBalance(now->_Pright)>0){  //RL
		PAVLTreeNode tem = l_rotate(now->_Pright);
		now->_Pright = tem;
		return r_rotate(now);
	}
	return now;   //如果经过删除操作后仍然平衡，直接返回即可
}

//也是递归的方式来查找
int SearchTimesByNameInAVL(PAVLTreeNode T,SDataType data){
	if(T==NULL)
		return 0;
	else{
		if(strcmp(data.name,T->_data.name)==0){
			return T->_data.totalCount;
		}
		else if(strcmp(data.name,T->_data.name)<0){
			return SearchTimesByNameInAVL(T->_Pleft, data);
		}
		else
			return SearchTimesByNameInAVL(T->_Pright, data);
	}
}