#include<stdio.h>
#include"hedda.h"

int compareInt(const void *a, const void *b)			//•À‚Ñ‘Ö‚¦
{
	int aNum = *(int *)a;
	int bNum = *(int *)b;

	if (aNum < bNum) {
		return -1;
	} else if (aNum > bNum) {
		return 1;
	}
	return 0;
}