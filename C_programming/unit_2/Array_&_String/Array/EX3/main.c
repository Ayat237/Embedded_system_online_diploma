/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX3 (Array)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{
	int n , m;
	printf("enter the row and column :\n");
	fflush(stdout);
	fflush(stdin);
	scanf("%d %d",&n,&m);
	int matrix1 [10][10];
	int matrix2 [10][10];
	int row ,column;
	printf("enter the element of matrix : \n");
	for (row = 0 ; row < n ; row++)
	{
		for (column = 0 ; column < m ; column++)
		{
			fflush(stdout);
			fflush(stdin);
			scanf("%d",&matrix1[row][column]);
		}

	}
	printf("the matrix you enterd is :\n");
	for (row = 0 ; row < n ; row++)
	{
		for (column = 0 ; column < m ; column++)
		{
			printf("%d\t", matrix1[row][column]);
		}
		printf("\n");
	}

	printf("\nthe transpose matrix  :\n");
	for (row = 0 ; row < n ; row++)
	{
		for (column = 0 ; column < m ; column++)
		{
			matrix2[column][row] = matrix1[row][column];
		}
	}
	for (row = 0 ; row < m ; row++)
	{
		for (column = 0 ; column < n ; column++)
		{
			printf("%d\t", matrix2[row][column]);
		}
		printf("\n");
	}
	return 0;
}

