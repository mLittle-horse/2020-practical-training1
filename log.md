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

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217233805.png" alt="image-20210217170718489" style="zoom:67%;" />

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

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217233858.png" alt="image-20210217195221148" style="zoom:67%;" />



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
				swap(p, p->next);
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
			swap(now, maxx);
		}
		now=now->next;
	}
	printf("快速排序完成！\n");
}
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217205328.png" alt="image-20210217205327038" style="zoom:67%;" />



#### 2021-2-17	21:18:16		add swap function to simplify code

##### 代码截图

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217233946.png" alt="image-20210217211949158" style="zoom:67%;" />



#### 2021-2-17	21:41:53		new HeapSort.c

这里要求从大到小排，即建立大顶堆。

其中void insert(PNode p)用来向大顶堆中插入节点，PNode del()用来删除堆顶元素并返回。

##### 代码

```c
//堆排序（大顶堆）
PNode heap[100005];
int heap_size = 0;

void HeapSort(){
	PNode p = head;
	while(p){
		insert(p);
		p = p->next;
	}
	head = tail = NULL;
	while(heap_size){
		InsertLinkEnd(del());
	}
	printf("堆排序完成！\n");
}

void insert(PNode p){
	heap[++heap_size] = p;
	int now, nex;
	now = heap_size;
	while(now>1){
		nex = now >> 1;
		if(heap[nex]->data.totalCount>=heap[now]->data.totalCount)
			return;
		swap(heap[nex], heap[now]);
		now = nex;
	}
}

PNode del(){
	PNode ans = heap[1];
	heap[1] = heap[heap_size--];
	int now, nex;
	now = 1;
	while(now<=heap_size/2){
		nex = now << 1;
		if(nex+1<=heap_size&&heap[nex]->data.totalCount<heap[nex+1]->data.totalCount)
			nex++;
		swap(heap[now], heap[nex]);
		now = nex;
	}
	return ans;
}
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217214942.png" alt="image-20210217214939935" style="zoom:67%;" />



#### 2021-2-17	23:16:52		new RadixSort.c

##### 代码

```c
PNode arr[100005],temArr[100005];
int array_size = 0;
int cnt[10];

int maxBit();  //计算totalCount的最大位数

void RadixSort(){
	array_size=0;
	PNode p=head;
	while(p){  //将链表里的元素转到数组里 
		arr[++array_size]=p;
		p=p->next;
	}
	head=tail=NULL;
	int digit=maxBit();  //求出最长的位数
//	cout<<"digit:"<<digit<<endl;
	int base=1;
	for(int i=1;i<=digit;i++){
		//清桶 
		for(int j=0;j<=9;j++) cnt[j]=0;
		//记录每个桶中数的个数 
		for(int j=1;j<=array_size;j++){
			int tem=arr[j]->data.totalCount;
			tem/=base;
			cnt[tem%10]++;
		}
//		for(int j=0;j<=9;j++) printf("cnt[%d]=%d ",j,cnt[j]);
		//计算桶的位置 (前缀和)
		for(int j=0;j<=9;j++){
			cnt[j]+=cnt[j-1];
		} 
//		for(int j=0;j<=9;j++) printf("cnt[%d]=%d ",j,cnt[j]);
		//倒着遍历(保证稳定性)，将数加到临时数组中 
		for(int j=array_size;j>=1;j--){
			int tem=arr[j]->data.totalCount;
			tem/=base;
			temArr[cnt[tem%10]--]=arr[j];
		}
		//将临时数组转移到原数组 
		for(int j=1;j<=array_size;j++){
			arr[j]=temArr[j];
		}
		base=(base<<1)+(base<<3);
	}
	//将排序后的数据转到链表中
	while(array_size){
		InsertLinkEnd(arr[array_size--]);
	}
	printf("基排序完成！\n");
}

int maxBit(){
	int maxx=0;
	for(int i=1;i<=array_size;i++){
		int tem=arr[i]->data.totalCount;
		int tot=0;
		while(tem){
			tem/=10;
			tot++;
		}
		maxx=tot>maxx?tot:maxx;
	}
	return maxx;
}
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210217233049.png" alt="image-20210217233047019" style="zoom:67%;" />





#### 2021-3-8	11:33:38		new QSort.c

##### 代码

```c
PNode brr[100005];
int brr_size = 0;

void QSort(){
	PNode p=head;
	while(p){
		brr[brr_size++] = p;
		p = p->next;
	}
	qsort(brr, brr_size, sizeof(PNode), compare);
	head = tail = NULL;
	while(--brr_size>=0){
		InsertLinkEnd(brr[brr_size]);
	}
	printf("改进版快速排序完成！\n");
}

/**
 * qsort函数包含在C 标准库 - <stdlib.h>
 * int compare(const void *p1, const void *p2);
 * 如果compare返回值小于0（< 0），那么p1所指向元素会被排在p2所指向元素的左面；
 * 如果compare返回值等于0（= 0），那么p1所指向元素与p2所指向元素的顺序不确定；
 * 如果compare返回值大于0（> 0），那么p1所指向元素会被排在p2所指向元素的右面。
 * int 类型的compare函数如下
int comp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
*/
int compare(const void *pa,const void *pb){
//	return (*(PNode)pa).data.totalCount - (*(PNode)pb).data.totalCount;    //对Node类型排序的
	return (*((PNode *)pa))->data.totalCount - (*((PNode *)pb))->data.totalCount; //对PNode类型排序的
}
```

其中compare函数尤其要注意，这个容易出错，应该用的指针类型来进行比较



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210308114935.png" alt="image-20210308114815989" style="zoom:67%;" />







#### 2021-3-9	12:57:32		update BST.c--new CreateBST、new InsertTreeNode、new tree traverse

##### 代码

注意这里是以姓名为关键字，也就是字符串，因为后续我们查找的时候查的是人名

```c
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
```



```c
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
```



```c
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
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210309130831.png" alt="image-20210309130752784" style="zoom:67%;" />





#### 2021-3-9	13:58:34		update BST.c--new DeleteTreeNode

这里出现了一个问题，就是我个人习惯宏定义LEN，这样用malloc分配size的时候就不用每次写sizeof，但是这里其实是多个文件，之前那种类型的时候用过一个LEN了，这次在建树的时候还是分配的空间为free，这样做是可以正常运行的，也就是为什么上面new CreateBST、new InsertTreeNode、new tree traverse这些函数都能正常原因，但是在删除结点的时候需要free，free的时候却抛出了异常。所以就去网上查了一下发现原因是我使用的空间超出了malloc时向系统申请的空间。

##### 代码

```c
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
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210309173505.png" alt="image-20210309173503873" style="zoom: 67%;" />



<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210309173624.png" alt="image-20210309173622701" style="zoom:67%;" />



<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210309173744.png" alt="image-20210309173743601" style="zoom:67%;" />



<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210309173859.png" alt="image-20210309173855974" style="zoom:67%;" />



<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210309174136.png" alt="image-20210309174134994" style="zoom:50%;" />



#### 2021-3-9	20:48:24		update BST.c--new AddTreeNode、update DeleteTreeNode

我在测新函数AddTreeNode的时候中序遍历发现之前的删除函数DeleteTreeNode有所不足，就改了一点，具体表现在没有判断当删除结点为根节点时要修改根，不然会造成之后操作的问题。

##### 代码

```c
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
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210309205313.png" alt="image-20210309205311350" style="zoom:67%;" />



#### 2021-3-9	21:15:03		update BST.c--new SearchTimesByName

这里写了一个带参数的函数，需要在主函数里输入name然后传参给该函数去查询，返回值为int

##### 代码

```c
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
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210309211721.png" alt="image-20210309211719961" style="zoom:67%;" />

这个是故意输入一个不存在的用户测试查询的

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210309211758.png" alt="image-20210309211757045" style="zoom:67%;" />





#### 2021-3-11	18:00:29	new AVL.c--new CreateAVLTree、new InsertAVLTreeNode、new l_rotate、new r_rotate

对于这种要旋转的平衡树，采用递归的方式插入节点和删除结点

对于LL和RR型只需要旋转一次就够了；但是对于LR和RL型的要先转成LL型或者RR型然后再处理，所以是要转两次

一定要注意，旋转的时候可能会改变一些结点的高度，所以旋转操作结束一定要记得更新结点的高度，否则后续插入节点的时候就会出错

##### 代码

```c
//直接通过文件读取建树
void CreateAVLTree(){
	FILE *fp;
	fp = fopen("C:\\mxp\\GitHub_repo\\2020-practical-training1\\in.txt", "r");
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
```

```c
//插入节点
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
```

```c
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
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210311205109.png" alt="image-20210311204711756" style="zoom:67%;" />



#### 2021-3-12	21:08:42		update AVL.c--new DeleteAVLTreeNode

这个删除操作也是递归删除，和insert的操作很像，注意也是在删完之后要记得计算其平衡因子看是否要旋转

##### 代码

```c
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
```



##### 测试结果

<img src="C:\Users\mxp101800\AppData\Roaming\Typora\typora-user-images\image-20210312210854197.png" alt="image-20210312210854197" style="zoom:67%;" />



<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210312211123.png" alt="image-20210312211121935" style="zoom: 67%;" />

<img src="C:\Users\mxp101800\AppData\Roaming\Typora\typora-user-images\image-20210312211240996.png" alt="image-20210312211240996" style="zoom:67%;" />



#### 2021-3-13	09:55:43		update AVL.c--new SearchTimesByNameInAVL

这个地方的搜索功能实现的和BST里的方法不太一样，这里是递归的去搜索的，BST里面就是单纯的顺着树往下搜，是用while循环实现的

##### 代码

```c
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
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210313095605.png" alt="image-20210313095603442" style="zoom:67%;" />

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210313095712.png" alt="image-20210313095711956" style="zoom:67%;" />



#### 2021-3-13	12:17:03		new hashtable.c--new InitHashTable、new InsertHashNode、new TraverseHashTable

其实就是以取模出来的哈希值作为桶的下标，然后每个桶本质是一个单链表。我们要添加的时候，就从该桶的第一个找到最后一个，然后遇到相同用户名的就将登陆次数累加。但是我这里对于每一个桶不仅维护了head，还维护了tail，这是在最后如果扫过一遍发现这个桶之前并没有key值的时候往末尾添加数据时用的。

有一个优化，就是在计算哈希值的时候，频繁的用到了取模，对于库函数pow无法支持取模操作，可能会有溢出。而如果利用循环来完成乘法效率较低，所以这里添加了一个FastPow快速幂的算法，可以实现快速算出某个数的幂次并且在计算的过程中取模。

##### 代码

```c
//初始化哈希表的大小和base
void InitHashTable(PHashTable hash, int TableSize,int base){
	hash->TableSize = TableSize;
	hash->base = base;
}
```

```c
//在一个单链表从前到后的时候顺便看看有没有相同的key值，如果有的话，将totalCount累加
void InsertHashNode(PHashTable hash, SDataType data){
	char key[LENGTH];
	strcpy(key, data.name);
	int h = CalcHash(key, hash->base, hash->TableSize);
	//插入节点在h地址的链表后
	PHashNode p = (PHashNode)malloc(sizeof(HashNode));
	p->_data = data;
	PHashNode now = hash->head[h];
	if(hash->head[h]==NULL){
		hash->head[h] = hash->tail[h] = p;
		p->next = NULL;
	}
	else{
		while(now){
			if(strcmp(now->_data.name,data.name)==0){
				now->_data.totalCount += data.totalCount;
				return;
			}
			now = now->next;
		}
		//说明没有找到相同key值的，在末尾添加即可；记得顺便修改tail的值
		hash->tail[h]->next = p;
		hash->tail[h] = p;
		p->next = NULL;
	}
}
```

```c
//遍历哈希表，从小桶开始
void TraverseHashTable(PHashTable hash){
	for (int i = 0; i < hash->TableSize;i++){
		PHashNode p = hash->head[i];
		while(p){
			printf("%s,%d\n",p->_data.name,p->_data.totalCount);
			p = p->next;
		}
	}
}
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210313121732.png" alt="image-20210313121731036" style="zoom:67%;" />



#### 2021-3-13	12:45:53		update hashtable.c--new DeleteHashNode

这个删除结点没啥难的，就还是先计算出其哈希值，找到桶，然后在这个单链表里顺着搜下去，找到相同的值就删掉返回即可

##### 代码

```c
void DeleteHashNode(PHashTable hash, SDataType data){
	int h = CalcHash(data.name, hash->base, hash->TableSize);
	PHashNode p = hash->head[h],pre;
	while(p){
		if(strcmp(data.name,p->_data.name)==0){
			printf("删除结点：%s,%d\n", p->_data.name, p->_data.totalCount);
			if(p==hash->head[h]&&p==hash->tail[h]){
				hash->head[h] = hash->tail[h] = NULL;
			}
			else if(p==hash->head[h]){
				hash->head[h] = hash->head[h]->next;
			}
			else{
				pre->next = p->next;
				if(p==hash->tail[h])
					hash->tail[h] = pre;
			}
			free(p);
			return;
		}
		pre = p;
		p = p->next;
	}
	printf("没有找到该用户信息!\n");
	printf("按回车返回！\n");
	getchar();
}
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210313124612.png" alt="image-20210313124611113" style="zoom:67%;" />



#### 2021-3-13	16:44:03		update hashtable.c--new SearchTimesByNodeInHash

##### 代码

```c
int SearchTimesByNodeInHash(PHashTable hash, SDataType data){
	if(hash==NULL)
		return 0;
	int h = CalcHash(data.name, hash->base, hash->TableSize);
	PHashNode p = hash->head[h];
	while(p){
		if(strcmp(data.name,p->_data.name)==0){
			return p->_data.totalCount;
		}
		p = p->next;
	}
	return 0;
}
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210313164426.png" alt="image-20210313164422291" style="zoom:67%;" />



#### 2021-3-13	16:54:32		update hashtable.c--new CreateHashTable

##### 代码

```c
//从文件读入数据创建哈希表
void CreateHashTable(PHashTable hash){
	FILE *fp;
	fp = fopen("C:\\mxp\\GitHub_repo\\2020-practical-training1\\in.txt", "r");
	if(fp==NULL){
		printf("提示：文件不存在！无法录入信息\n");
		printf("请按回车键返回.");
		getchar();getchar();
		return ;
	}
	else while(!feof(fp)){
		SDataType data;
		char message[LENGTH << 1], name[LENGTH];
		fscanf(fp,"%s", message);
		int index = 0;
		for (int i = 0; i < strlen(message);i++){
			if(message[i]==',')
				break;
			name[index++] = message[i];
		}
		name[index] = '\0';
		strcpy(data.name, name);
		data.totalCount = 1;
		InsertHashNode(hash, data);
	}
	fclose(fp);
	printf("信息读取成功！\n");
	printf("按回车继续！\n");
	getchar();
}
```



##### 测试结果

<img src="https://cdn.jsdelivr.net/gh/mLittle-horse/PicStore/img/20210313165451.png" alt="image-20210313165450411" style="zoom:67%;" />





#### 2021-3-14	19:57:19		Learn to calculate the running time of a program

clock_t是一个长整形数。在time.h文件中，还定义了一个常量CLOCKS_PER_SEC，它用来表示一秒钟会有多少个时钟计时单元

注意这个start和end都是clock_t类型的，最后在计算时间的时候一定要注意转成double类型的算，不然会丢失掉很多精度的。而且一定要除以CLOCKS_PER_SEC，这样除之后求出来的是运行的秒数。

主要思想就是把程序执行要测试的代码之前的时间段保存下来，再记录一下测试程序执行后的时间，用程序总执行时间减去程序执行要测试代码段之前的执行时间的时间得到程序执行要测试代码的时间。

##### 代码

```c
#include<time.h>
void test1(){
	clock_t start,end;
	double Total_time;
	start=clock();
	int i;
	for(i=1;i<=100000;i++){
		printf("%d\n",i);
	}
	end=clock();
	Total_time=(double)(end-start)/CLOCKS_PER_SEC;
	printf("%f second\n",Total_time);
} 
```

























