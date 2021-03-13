#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

HashTable hashtable;

//初始化哈希表的大小和base
void InitHashTable(PHashTable hash, int TableSize,int base){
	hash->TableSize = TableSize;
	hash->base = base;
}

void CreateHashTable(PHashTable hash){
	FILE *fp;
	fp = fopen("C:\\mxp\\GitHub_repo\\2020-practical-training1\\in.txt", "r");
	if(fp==NULL){
		printf("提示：文件不存在！无法录入信息\n");
		printf("请按回车键返回.");
		getchar();getchar();
		return ;
	}
	else{
		SDataType data;
		char message[LENGTH << 1], name[LENGTH];
		scanf("%s", message);
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
}


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

//算出关键字通过散列函数后计算得到的哈希值
int CalcHash(char key[],int base,int TableSize){
	int len = strlen(key);
	long long ans = 0;
	for (int i = 0; i < len;i++){
		ans += key[i] * FastPow(base, i, TableSize);
		ans %= TableSize;
	}
	return ans;
}

//快速幂
long long FastPow(long long a,long long p,long long mod){
	long long ans = 1;
	while(p){
		if(p&1)
			ans = ans * p % mod;
		p >>= 1;
		a = a * a % mod;
	}
	return ans;
}


