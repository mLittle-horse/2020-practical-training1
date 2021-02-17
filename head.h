#define LENGTH 30
typedef struct User_login{
	char name[LENGTH];
	int totalCount;
}SDataType;   //链表结点

typedef struct SListNode{
	SDataType data;
	struct SListNode *next;
}Node,*PNode;    //链表结点和next指针