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

#endif