/*
 *  main.c
 *  Created on: Aug 17, 2023
 *  Author: Ayat Mohamed
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int binary(int dnumber);
int main ()
{
	int number;
	printf("enter the number:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&number);
	printf("number of ones of %d -> %d",number,binary(number));
	return 0;
}
int binary(int dnumber)
{
	int bNumber[32] ;
	int i,size;;
	int iter = 0, counter = 0, maxCounter = 0,zeroFlag =0;
	while (dnumber > 0)
	{
		bNumber[iter] = dnumber%2;
		dnumber /= 2;
		iter ++;
	}
	size = iter;
	for (i = size - 1 ; i >= 0; i --)
	{
		if(bNumber[i] == 0)
		{
			if(zeroFlag && counter > maxCounter)
			{
				maxCounter = counter;
			}
			counter = 0;
			zeroFlag = 1;
		}
		else
		{
			counter ++;
		}
	}
	return maxCounter;
}

/*int uniqeNumber(int arr[],int size);
int main ()
{
	int arr[7];
	int size ;
	int iter;
	printf("enter the size :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&size);
	printf("enter the array element :");
	fflush(stdin);
	fflush(stdout);
	for(iter = 0 ; iter < size ; iter ++)
	{
		scanf("%d",&arr[iter]);
	}
	printf("unique number = %d",uniqeNumber(arr,size));
	return 0;
}

int uniqeNumber(int arr[],int size)
{
	int iter;

	int number = arr[0];
	for(iter= 1 ; iter < size ; iter ++)
	{
		number ^=arr[iter];
	}
	return number;
}*/

/*
void reverseWordSting(char *str);
int main ()
{
	char str[100];
	printf("enter the string : \n");
	fflush(stdout);
	fflush(stdin);
	gets(str);
	reverseWordSting(str);
	return 0;
}
void reverseWordSting(char *str)
{
	int i;
	int j;
	int len;
	int startIdx;
	int endIdx;
	len = strlen(str);
	endIdx = len - 1;
	for(i = len - 1; i >= 0; i--)
	{
		if(str[i] == ' ' || i == 0)
		{
			if(i == 0)
			{
				startIdx = 0;
			}
			else
			{
				startIdx = i + 1;
			}
			for(j = startIdx; j <= endIdx; j++)
			{
				printf("%c", str[j]);
			}
			endIdx = i - 1;
			printf(" ");
		}
	}
}
 */

/*
void reverseArray(int arr[],int size);
int main ()
{
  int arr[5];
  int size = 5;
  int iter;
  printf("enter the array element :");
  fflush(stdin);
  fflush(stdout);
  for(iter = 0 ; iter < 5 ; iter ++)
  {
    scanf("%d",&arr[iter]);
  }
  reverseArray(arr,size);
  return 0;
}

void reverseArray(int arr[],int size)
{
  int iter;
  for(iter= size-1 ; iter >=0 ; iter --)
  {
    printf("%d ",arr[iter]);
  }
}
 */
/*
int sum(int number);

int main ()
{

	printf("sum from 1 to 100 = %d",sum(100));
	return 0;
}

int sum(int number)
{
	//int iterator=0;
	int summ = 0;
	if(number != 0)
	{
		return number+sum(number-1);
	}
}
 */


/*
int binary(long n);
int main ()
{
	int number;
	printf("enter the number:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&number);
	printf("number of ones of %d -> %d",number,binary(number));
	return 0;
}
int binary(long n)
{
	long iter;
	int counter = 0;
	for (iter = 1 << 30; iter > 0; iter = iter / 2)
	{
		if((n & iter) != 0)
		{
			counter++;
		}
	}
	return counter;

}
 */
/*
int reverseNumber(int number);
int main()
{
	int number;
	printf("enter the number:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&number);
	printf("%d",reverseNumber(number));
	return 0 ;
}
int reverseNumber(int number)
{
	int iterator;
	int reverse = 0;
	for(iterator = number ; iterator!=0 ;iterator=iterator/10)
	{
		number = iterator%10;
		reverse = (10*reverse)+number;
	}
	return reverse;
}
 */




/*
int PrimeNumbers(int number);
int main()
{
	int number1 ,number2;
	int flag;
	int iterator;
	printf("enter the two numbers intervals :\n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&number1);
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&number2);
	if(number1<number2)
	{
		printf("Prime numbers between %d and %d = ",number1,number2);
		for(iterator = number1 ;iterator < number2 ;iterator++)
		{
			flag =	PrimeNumbers(iterator);

			if(flag == 0)
			{
				printf("%d  ",iterator);
			}
		}
	}
	return 0 ;
}
int PrimeNumbers(int number)
{
	int flag = 0 ;
	int iterator = 0;
	for (iterator = 2 ; iterator <= number/2 ; iterator ++)
	{
		if (number % iterator == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
 */
/*
double squareRoot (int number);
int main ()
{

	int number ;
	printf("enter the number :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&number);
	printf("root = %.3lf",squareRoot(number));
	return 0;
}
double squareRoot (int number)
{
	double root ;
	root = log(number)/log(2);

	return root;
}
 */


/*int sumAllDigits(int number)
{
	int sum=0;
	int iterator;
	for(iterator = number ; iterator!=0 ;iterator=iterator/10 )
	{
		number = iterator%10;
		sum +=number;
	}
	return sum;
}

int main ()
{
	int number;
	printf("enter the number to get sum:");
	fflush(stdin);
	fflush(stdout);
    scanf("%d",&number);
	printf("%d",sumAllDigits(number));
	return 0;
}
 */
