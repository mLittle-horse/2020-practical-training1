#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

int main(){
	ReadFromFile();
	Display();
	DeleteRecord();
	Display();
	InputRecord();
	Display();
	Destroy();
	Display();
	return 0;
}