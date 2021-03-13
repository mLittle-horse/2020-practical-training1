#ifndef __HEAD_H__
#define __HEAD_H__

#define LENGTH 30
#define LEN sizeof(Node)

typedef struct User_login{
	char name[LENGTH];
	int totalCount;
}SDataType;   //链表结点

typedef struct SListNode{
	SDataType data;
	struct SListNode *next;
}Node,*PNode;    //链表结点和next指针

extern PNode head, tail;    //定义链表头、尾的全局变量

void ReadFromFile();  //从文件读入数据
void InsertLinkEnd(PNode p); //尾插结点
void Display();  //遍历链表，输出信息
void DeleteNode(PNode p,PNode pre);  //删除指定结点
void DeleteRecord();  //删除某条记录
void InputRecord();  //增加某条记录
void Destroy();  //摧毁链表
void MergeListNode();   //合并相同姓名的结点
void WriteToFile();  //将单链表中的节点输出到文件 result.txt 中

////////////////////////////////排序/////////////////////////////
void swap(PNode x, PNode y);   //交换两个结点信息
void BubbleSort();  //冒泡排序
void QuickSort();	//快速排序
void HeapSort();    //堆排序
void RadixSort();   //基排序

int compare(const void *pa, const void *pb);   //qsort的比较函数
void QSort();   //修改快速排序--使用标准库中的qsort()函数

////////////////////////////////////////二叉搜索树BST//////////////////////////////////////////////////////

typedef struct TreeNode
{
	SDataType _data;
	struct TreeNode *_Pleft;
	struct TreeNode *_Pright;
}TreeNode,*PTreeNode;    //封装BST的结点和左右子树指针

typedef struct BST{
	PTreeNode _pRoot;    //指向BST的根节点
}BST;


extern BST Tree;


void CreateBST();
void InsertTreeNode(PTreeNode p);
void PreOrderTraverse(PTreeNode T);
void InOrderTraverse(PTreeNode T);
void PostOrderTraverse(PTreeNode T);
void DeleteTreeNode();    //给出一个名字，将这个名字的结点从二叉搜索树 中删除
void AddTreeNode();   //这个是新增结点，输入用户姓名，默认登录次数为1
int SearchTimesByName(char name[]);   //对人名的查找，显示登录次数信息


////////////////////////////////////////平衡二叉树AVL//////////////////////////////////////////////////////
//AVL里面采用递归的方法来写Insert和Delete

typedef struct AVLTreeNode
{
	SDataType _data;
	struct AVLTreeNode *_Pleft;
	struct AVLTreeNode *_Pright;
	int height;
}AVLTreeNode,*PAVLTreeNode;    //封装AVL的结点和左右子树指针

typedef struct AVL{
	PAVLTreeNode _pRoot;    //指向AVL的根节点
}AVL;

extern AVL ATree;

void CreateAVLTree();
PAVLTreeNode InsertAVLTreeNode(PAVLTreeNode now, SDataType data);
PAVLTreeNode DeleteAVLTreeNode(PAVLTreeNode now, SDataType data);
int SearchTimesByNameInAVL(PAVLTreeNode T,SDataType data);   //对人名的查找，显示登录次数信息

//辅助函数
PAVLTreeNode CreatAVLNode(SDataType data);
int high(PAVLTreeNode p);
int GetBalance(PAVLTreeNode p);
PAVLTreeNode l_rotate(PAVLTreeNode p);
PAVLTreeNode r_rotate(PAVLTreeNode p);
int Max(int a, int b);

//遍历
void PreOrderTraverseAVL(PAVLTreeNode T);
void InOrderTraverseAVL(PAVLTreeNode T);
void PostOrderTraverseAVL(PAVLTreeNode T);


#endif