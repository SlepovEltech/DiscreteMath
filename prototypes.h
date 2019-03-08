#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include "struct.h"

int new_gets(char *s, int lim)
{
	int i;
	char c;
	for(i = 0;(lim -1) && ( (c = getchar()) != '\n'); s++,i++) *s = c;
	*s = '\0';
	return i;
}

void input(N *q,char *s, int lim)
{
	int n,i;
	n = new_gets(s,lim);
	q->n = n;
	for(i = 0; i < n; i++)
	{
		q->A[n-i-1] = s[i]-'0';
	}
}

int natural()
{
	int key;
	printf("Choose operation with natural numbers: ");
	printf("\n1-Comparison of natural numbers\n2-Check to zero\n3-Appendix 1\n4-Addition of natural numbers\n");
	printf("5-Subtraction(first - large, second -smaller)\n6-Multiplying a natural number by a digit\n");
	printf("7-Multiplying a natural number by 10 in deg\n8-Multiplication of natural numbers\n");
	printf("9-Subtraction from other natural, multiplied by a digit\n10-Calculation of the first digit of the division of greater natural by less, multiplied by 10^k\n");
	printf("11-The DIV of the numbers\n12-The MOD of the numbers\n13-NOD of the numbers\n14-NOK of the numbers\n\n");
	printf("Your answer: ");
	scanf("%d", &key);
	return key;
}

void clear(int sys)
{
	if(sys == 1) system("CLS");
	if(sys == 2) system("clear");
}

void print_header()
{
	printf("\t\t\t     Discrethe Math\n\t\tСomputer Algebra System by students 8306");
}

int menu()
{
	int key;
	print_header();
	printf("\n\t\t\t\tMENU\n");
	printf("Press '1' to start\nPress '2' to check information about program\nPress '3' to close the program\nYour answer: ");
	scanf("%d", &key);
	system("clear");

	return key;
}