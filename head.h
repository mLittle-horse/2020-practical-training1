#define LENGTH 30
typedef struct User_login{
	char name[LENGTH];
	int totalCount;
}SDataType;   //������

typedef struct SListNode{
	SDataType data;
	struct SListNode *next;
}Node,*PNode;    //�������nextָ��