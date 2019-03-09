#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "struct.h"
#include "natural.h"
int new_gets(char *s, int lim)
{
	int i;
	char c;
	for(i = 0;(lim -1) && ( (c = getchar()) != '\n'); s++,i++) *s = c;
	*s = '\0';
	return i;
}

void input(N *q,char *s, int n)
{
	int i;
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


int main()
{
	N *q, *w;
	Z d,t;
	P g,f;
	int n,i,lim,key,clas,num;
	char *s;
	int sys;
	lim = 150;
	printf("Choose your OS type:\n1-Windows\n2-Linux\nYour answer: ");
	scanf("%d", &sys);	
	while(sys < 0 || sys > 2)
	{
		printf("Wrong answer! Try again: ");
		scanf("%d", &sys);	
	}
	clear(sys);
	s = (char*)malloc(lim*sizeof(char));
	if(s != NULL)
	{
		while( (key = menu()) != 3)
		{
		    if(key != 3 && key != 2 && key != 1)
	        {
	            printf("Enter a correct answer!\n");
	        }
	        if(key == 1)
	        {
	        	printf("Choose class of number to work:\n1-Natural+{0}\n2-Integer\n3-Rational\n4-Polinom\nYour answer: ");
	        	scanf("%d", &clas);
	        	clear(sys);
	        	if(clas == 1) 
	        	{
	        		q = (N*)malloc(sizeof(N));
	        		w = (N*)malloc(sizeof(N));
	        		if(q && w)
	        		{
	        			switch(natural())
						{
							case 1:
								printf("Enter first number: "); 
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);		
								printf("Enter second number: "); 
								n = new_gets(s,lim);
								w->A = (int*)malloc(n*sizeof(int));
								input(w,s,n);	
								printf("Result: %d\n",COM_NN_D(q,w));
								break;					
							case 2: 
								printf("Enter your number: ");
								n = new_gets(s,lim); 
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);	
							case 6:
								printf("Enter your number: "); 
								getchar();
								input(q,s,lim);	
								printf("Enter digit: "); 
								scanf("%d", &num);
								MUL_ND_N(q,num);
								printf("\n");
								for(i = q->n-1;i>=0;i++)
								printf("%d", q->A[i]);
							default: 
							break;
						}		   
	        		}     		
	        	}
	        	if(clas == 2)
	        	{

	        	}
	        	if(clas == 3)
	        	{

	        	}
	        	if(clas == 4)
	        	{

	        	}

        	}
        }
	    free(s);
		s = NULL;
	}
	else
		printf("Error at memory location! Bye!");
	return 0;
}

 