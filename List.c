#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"


void InsertLinkEnd(PNode p){
	if(head==NULL){
		head->next = p;
		head = tail = p;
		return;
	}
	else{
		tail->next = p;
		tail = p;
		tail->next = NULL;
	}
}
