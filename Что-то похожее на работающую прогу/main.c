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
/*
New_gets and input read string and makes a sign and array for Z and makes an array for N
*/
int input(N *q,char *s, int n) 
{
	int i,sign;
	if(s[0] == '-')
	{
		sign = 1;
		for(i = 1; i < n; i++)
		{
			q->A[n-i-1] = s[i]-'0';
		}
		q->n = n-1;
	}
	else
	{
		sign = 0;
		q->n = n;
		for(i = 0; i < n; i++)
		{
			q->A[q->n-i-1] = s[i]-'0';
		}
	}
	return sign;
}
void output(N *q)
{
	int i;
	for(i = q->n-1; i >= 0; i--)
		printf("%d", q->A[i]);
	printf("\n");
}
int natural()
{
	int key;
	printf("Choose operation with natural numbers: ");
	printf("\n1-Comparison of natural numbers\n2-Check if zero\n3-Appendix 1\n4-Addition of natural numbers\n");
	printf("5-Subtraction(the first - the biggest, the second -smaller or equal)\n6-Multiplying a natural number by a digit\n");
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
	printf("\t\t\t     Discrethe Math\n\t\tComputer Algebra System by students 8306");
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
	N *q, *w,*res;
	Z *d, *t;
	P g,f;
	int n,i,lim,key,clas,num,sign;
	char c_sign;
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
		    clear(sys);
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
	        		res = (N*)malloc(sizeof(N));
	        		if(q && w && res)
	        		{
	        			switch(natural())
						{
							case 1:
								printf("Enter the first number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);
								printf("Enter the second number: ");
								n = new_gets(s,lim);
								w->A = (int*)malloc(n*sizeof(int));
								input(w,s,n);
								if(COM_NN_D(q,w)==2) printf("The first number is bigger\n"); 
								else 
									if(COM_NN_D(q,w)==0) printf("The numbers are equal\n"); 
									else printf("The second number is bigger\n");
								free(q->A);
								free(w->A);
								q->A = NULL; w->A = NULL;
								break;
							case 2:
								printf("Enter your number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);
								if(NZER_N_B(q) == 1)
									printf("Your number equals zero\n");
								else
									printf("Your number equals zero\n");
								free(q->A);
								q->A = NULL;
								break;
							case 3:
								printf("Enter your number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc((n+1)*sizeof(int));
								input(q,s,n);
								printf("Result: ");
								ADD_1N_N(q);
								output(q);
								free(q->A);
								q->A = NULL;
								break;		
							case 4:
								printf("Enter the first number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);
								printf("Enter the second number: ");
								n = new_gets(s,lim);
								w->A = (int*)malloc(n*sizeof(int));
								input(w,s,n);
								res =ADD_NN_N(q,w);
								printf("Result ");
								output(res);
								break;		
							case 5: 
								printf("Enter the first number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);
								printf("Enter the second number: ");
								n = new_gets(s,lim);
								w->A = (int*)malloc(n*sizeof(int));
								input(w,s,n);
								res = SUB_NN_N(q,w);
								printf("Result: ");
								output(res);
								free(q->A);
								free(w->A);
								q->A = NULL; w->A = NULL;
								break;		
							case 6:
								printf("Enter your number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);
								printf("Enter digit: ");
								scanf("%d", &num);
								res = MUL_ND_N(q,num);
								if(res != NULL )
								{
									printf("Result: ");
									output(res);
									free(res);
									res = NULL;
								}
								else 
									printf("Result is NULL!\n");
								free(q->A);
								q->A = NULL; 
								break;
							case 7:
								printf("Enter your number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);
								printf("Enter k: ");
								scanf("%d", &num);
								res = MUL_Nk_N(q,num);
								if(res != NULL )
								{
									printf("Result: ");
									output(res);
									free(res);
									res = NULL;
								}
								else 
									printf("Result is NULL!\n");
								free(q->A);
								q->A = NULL;
								break;
							case 8: 
								printf("Enter the first number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);
								printf("Enter the second number: ");
								n = new_gets(s,lim);
								w->A = (int*)malloc(n*sizeof(int));
								input(w,s,n);
								res = MUL_NN_N(q,w);
								if(res != NULL )
								{
									printf("Result: ");
									output(res);
									free(res);
									res = NULL;
								}
								else 
									printf("Result is NULL!\n");
								free(q->A);
								free(w->A);
								q->A = NULL; w->A = NULL;
								break;
							 case 9:
							 	printf("Enter the first number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);
								printf("Enter digit: ");
								scanf("%d", &num);
								printf("Enter the second number: ");
								getchar();
								n = new_gets(s,lim);
								w->A = (int*)malloc(n*sizeof(int));
								input(w,s,n);
								res = SUB_NDN_N(q,num,w);
								if(res != NULL )
								{
									printf("Result: ");
									output(res);
									free(res);
									res = NULL;
								}
								else 
									printf("Result is NULL!\n");
								free(q->A);
								free(w->A);
								q->A = NULL; w->A = NULL;
								break;
							case 10:
								printf("Enter the first number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);
								printf("Enter the second number: ");
								n = new_gets(s,lim);
								w->A = (int*)malloc(n*sizeof(int));
								input(w,s,n);
								printf("Result: %d", DIV_NN_Dk(q,w));
								free(q->A);
								free(w->A);
								q->A = NULL; w->A = NULL;
								break;
							default:
							break;
						}
	        		}
	        	}
	        	if(clas == 2)
	        	{
	        		d = (Z*)malloc(sizeof(Z));
	        		t = (Z*)malloc(sizeof(Z));
	        		if(d && t)
	        		{
	        			//Zdes' budet vibor variantov, strutcra chtaetsa tak:
	        			printf("Enter your number: ");
	        			getchar();
	        			n = new_gets(s,lim);
	        			d->num = (N*)malloc(sizeof(N));
	        			d->num->A = (int*)malloc(n*sizeof(int));
	        			d->sign = input(d->num,s,n);
	        			printf("Result: %d ",d->sign);
	        			output(d->num);
	        		}

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

