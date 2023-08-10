/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX1 (Array)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{
	float matrix1 [2][2];
	float matrix2 [2][2];
	float matrixSum [2][2]={};
	int row ,column;

	printf("first matrix  is :\n");
	for (row = 0 ; row < 2 ; row++)
	{
		for (column = 0 ; column < 2 ; column++)
		{
			printf("enter a%d%d : ", row+1 , column+1);
			fflush(stdout);
			fflush(stdin);
			scanf("%f",&matrix1[row][column]);
		}

	}

	printf("\nsecond matrix  is :\n");
	for (row = 0 ; row < 2 ; row++)
	{
		for (column = 0 ; column < 2 ; column++)
		{
			printf("enter a%d%d : ", row+1 , column+1);
			fflush(stdout);
			fflush(stdin);
			scanf("%f",&matrix2[row][column]);
		}

	}

	printf("\nthe sum of matrix  :\n");
	for (row = 0 ; row < 2 ; row++)
	{
		for (column = 0 ; column < 2 ; column++)
		{
			matrixSum [row][column] = matrix1[row][column] + matrix2[row][column];
		}
	}

	for (row = 0 ; row < 2 ; row++)
	{
		for (column = 0 ; column < 2 ; column++)
		{
			printf("%.2f\t" , matrixSum[row][column]);
		}
		printf("\n\n");
	}
	return 0;
}

