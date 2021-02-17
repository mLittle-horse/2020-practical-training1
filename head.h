#ifndef __HEAD_H__
#define __HEAD_H__

#define LENGTH 30
#define LEN sizeof(Node)

typedef struct User_login{
	char name[LENGTH];
	int totalCount;
}SDataType;   //������

typedef struct SListNode{
	SDataType data;
	struct SListNode *next;
}Node,*PNode;    //�������nextָ��

extern PNode head, tail;    //��������ͷ��β��ȫ�ֱ���

void ReadFromFile();  //���ļ���������
void InsertLinkEnd(PNode p); //β����

#endif