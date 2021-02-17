#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

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
//	WriteToFile();

/////////排序//////////
//	BubbleSort();
	QuickSort();
	Display();
	return 0;
}