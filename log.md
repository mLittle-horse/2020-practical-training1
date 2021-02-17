## 日志

#### 2021-2-16	16:30:15		add main.c

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/image-20210216163132725.png" style="zoom: 67%;" />



#### 2021-2-17	11:03:21		add head.h

head.h 用于保存创建链表所需的数据结构和函数申明

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/image-20210217110359345.png" alt="image-20210217110359345" style="zoom:67%;" />



#### 2021-2-17	11:40:37		add fileread.c、add List.c、update head.h

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/image-20210217114231863.png" alt="image-20210217114231863" style="zoom:67%;" />

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/image-20210217114621108.png" alt="image-20210217114621108" style="zoom:67%;" />

```c
//fileread.c
//该文件负责读入 user_login.txt 中内容保存到单链表中
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void ReadFromFile(){
	FILE *fp;
	fp = fopen("C:\\in.txt", "r");
	if(fp==NULL){
		printf("提示：文件不存在！无法录入信息\n");
		printf("请按回车键回到主菜单.");
		getchar();getchar();
		return ;
	}
	PNode p;
	char message[LENGTH << 1], name[LENGTH];
	while (!feof(fp))
	{
		p = (PNode)malloc(LEN);
		fscanf(fp, "%s", message);
		int index = 0;
		for (int i = 0; i < strlen(message);i++){
			if(message[i]==',')
				break;
			name[index++] = message[i];
		}
		name[index] = '\0';
		strcpy(p->data.name, name);
		p->data.totalCount = 1;
		InsertLinkEnd(p);
	}
}
```



#### 2021-2-17	13:59:46   	update List.c--add Display function

增加并测试了Display功能，输出链表。

##### 代码截图

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217145914.png" alt="image-20210217140127066" style="zoom:67%;" />

##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217170433.png" alt="image-20210217170431934" style="zoom:67%;" />

#### 2021-2-17	14:41:34		update List.c--add DeleteRecord function

其中DeleteRecord()调用DeleteNode()函数。DeleteNode是删除给定的指针所指向的结点。

DeleteRecord()里面设计了找到结点后可以选择删或不删。

##### 代码截图

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/image-20210217144404403.png" alt="image-20210217144404403" style="zoom:67%;" />

##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217170548.png" alt="image-20210217170546954" style="zoom:67%;" />

```c
//DeleteRecord function
void DeleteRecord(){
	if(head==NULL){
		printf("没有信息，请先存入登录信息！");
		return ;
	}
//	Display();
	PNode p = NULL, pre = NULL;
	printf("请输入想要删除的姓名:");
	char name[LENGTH];
	scanf("%s", name);
	while (1)
	{
		p = head;
		int findFlag = 0;
		while(p){
			if(!strcmp(p->data.name,name)){
				findFlag = 1;
				printf("找到该登录信息如下：\n");
				printf("\t姓名\t登录次数\n");
				printf("\t%s\t%d\n",p->data.name,p->data.totalCount);
				printf("确认要删除吗？[y/n]");
				char ch;
				scanf(" %c",&ch);
				if(ch=='y'||ch=='Y'){
					DeleteNode(p,pre);
				}
				else{
					printf("你选择不删除信息！\n\n");
				}
				break;
			}
			pre = p;
			p = p->next;
		}
		if(findFlag==1)
			break;
		else{
			printf("没有找到该用户信息，请重新输入！\n");
			printf("新的姓名：");
			scanf("%s",name);
		}
	}
	printf("请按回车返回!");
	getchar();
	getchar();
}
```



#### 2021-2-17	15:13:55		update List.c--add InputRecord function

加入了添加结点的功能并测试。

##### 代码

```c
//InputRecord function	
void InputRecord(){
	PNode p, q;
	while(1){
		p = (PNode)malloc(LEN);
		printf("输入待添加信息(格式：姓名,登录时间)：");
		char message[LENGTH << 1], name[LENGTH];
		scanf("%s", message);
		int index = 0;
		for (int i = 0; i < strlen(message);i++){
			if(message[i]==',')
				break;
			name[index++] = message[i];
		}
		name[index] = '\0';
		strcpy(p->data.name, name);
		p->data.totalCount = 1;
		InsertLinkEnd(p);
		printf(">>>>>>>>>>提示：新的结点已经添加完毕，是否要继续添加？[y/n]");
		char ch;
		scanf(" %c", &ch);
		switch(ch){
			case 'y':
			case 'Y':
				break;
			default:
				return;
		}
	}
	printf("请按回车键继续!");
	getchar();
	getchar();
}
```

##### 测试结果

<img src="C:\Users\mxp101800\AppData\Roaming\Typora\typora-user-images\image-20210217170718489.png" alt="image-20210217170718489" style="zoom:67%;" />

#### 2021-2-17	17:00:54		update List.c--add Destroy function

添加了销毁链表功能并测试。

##### 代码截图

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217170239.png" alt="image-20210217170230494" style="zoom:67%;" />

##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217170026.png" alt="image-20210217165957730" style="zoom:67%;" />



#### 2021-2-17	17:17:52		update List.c--add MergeListNode function

增加了合并结点功能，数能够将用户名相同的节点合并，并在合并过程中将登录次数累加

##### 代码截图

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217172009.png" alt="image-20210217172008128" style="zoom:67%;" />

##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217172131.png" alt="image-20210217172127857" style="zoom:67%;" />



#### 2021-2-17	19:48:22		new filewrite.c

增加了将单链表中的节点输出到文件 result.txt 中功能

##### 代码截图

![image-20210217195020067](https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217195022.png)

##### 测试结果

<img src="C:\Users\mxp101800\AppData\Roaming\Typora\typora-user-images\image-20210217195221148.png" alt="image-20210217195221148" style="zoom:67%;" />



#### 2021-2-17	19:55:37		whole

依次执行读入文件、创建链表、合并链表节点和输出文件的功能。

##### 测试代码

```c
int main(){
	ReadFromFile();
	Display();
	// DeleteRecord();
	// Display();
	// InputRecord();
	// Display();
	// Destroy();
	// Display();
	MergeListNode();
	Display();
	WriteToFile();
	return 0;
}
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217195733.png" alt="image-20210217195731627" style="zoom:67%;" />



#### 2021-2-17	20:27:09		new BubbleSort.c 

##### 代码

```c
//冒泡排序
void BubbleSort(){
	PNode p,end;
	end=NULL;
	while(end!=head){
		p=head;
		while(p->next!=end){
			if(p->data.totalCount<p->next->data.totalCount){
				//交换 totalCount 的值 
				int tem=p->data.totalCount;
				p->data.totalCount=p->next->data.totalCount;
				p->next->data.totalCount=tem;
				//交换name 
				char name[LENGTH];
				strcpy(name,p->data.name);
				strcpy(p->data.name,p->next->data.name);
				strcpy(p->next->data.name,name);
			}
			p=p->next;
		}
		end=p;
	}
	printf("冒泡排序完成！\n");
}
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217202842.png" alt="image-20210217202840716" style="zoom:67%;" />



#### 2021-2-17	20:53:36		new QuickSort.c 

##### 代码

```c
//快速排序
void QuickSort(){
	PNode now,p;
	now=head;
	while(now){
		p=now->next;
		PNode maxx=now;
		while(p){
			if(p->data.totalCount>maxx->data.totalCount) maxx=p;
			p=p->next;
		}
		if(maxx!=now){
			//交换 totalCount 的值 
			int tem=now->data.totalCount;
			now->data.totalCount=maxx->data.totalCount;
			maxx->data.totalCount=tem;
			//交换name
			char name[LENGTH];
			strcpy(name,now->data.name);
			strcpy(now->data.name,maxx->data.name);
			strcpy(maxx->data.name,name);
		}
		now=now->next;
	}
	printf("快速排序完成！\n");
}
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217205328.png" alt="image-20210217205327038" style="zoom:67%;" />



