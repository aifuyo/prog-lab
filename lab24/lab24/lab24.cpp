// lab24.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
int main()
{
	int **a = NULL, i = 0, j=0,elem=1;
	int studcount = 4; int aver[4]; int sum = 0, less3 = 0, onlybest = 0; bool best = true;
	char c;
	a = (int**)malloc(studcount * sizeof(int*));
	for (i = 0; i < studcount; i++) {
		a[i] = NULL;
		j = 0; best = true; sum = 0;
		do {
			printf_s("a[%d][%d]= ", i, j);
			scanf_s("%d", &elem);
			if (elem != 0) {
				a[i] = (int*)realloc(a[i], (j + 1) * sizeof(int));
				a[i][j] = elem;
				j++;
				sum += elem;
				if (elem != 5 && elem != 4) best = false;
			}
			
		} while (elem != 0);
		aver[i] = sum/j;
		if (j < 3) less3++;
		if (best) onlybest++;
	}
	for (int i = 0; i < studcount; i++)
	{
		printf_s("Средняя оценка %d-го студента = %d\n", i, aver[i]);
	}
	printf_s("Количество студентов с оценками меньше 3 штук = %d\n", less3);
	printf_s("Количество студентов с только 4 и 5 =  %d\n", onlybest);

	getchar();
	return 0;
}