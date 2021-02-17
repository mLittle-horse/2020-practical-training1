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



#### 2021-2-17	13:59:46   	update List.c

增加了Display功能，输出链表。







