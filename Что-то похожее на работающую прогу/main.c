#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "struct.h"
#include "natural.h"
#include "integer.h"
#include "rational.h"

int new_gets(char *s, int lim) 
{
	int i;
	char c;
	for(i = 0;(i < lim -1) &&  ((c = getchar()) != '\n'); s++,i++) *s = c;
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
	if(s[0] != '-')
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

void output(N *a)
{
	int i;
	for(i = a->n-1; i >= 0; i--)
		printf("%d", a->A[i]);
	//printf("\n");
}
void output_int(Z *a)
{
	if(a->sign == 1) printf("-");
	output(a->num);
}
void output_rat(Q* a)
{
	output_int(a->m);
	printf("/");
	output(a->n);
	printf("\n");
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
	Z *d, *t, *resZ;
	Q *h, *l;
	P g,f;
	int n,i,lim,key,clas,num,sign,key1;
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
									printf("Your number doesn't equal zero\n");
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
								printf("\n");
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
								printf("\n");
								
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
								printf("Result: %d", DIV_NN_Dk(q,w)[0]);
								free(q->A);
								free(w->A);
								q->A = NULL; w->A = NULL;
								break;
							case 11:
								printf("Enter the first number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);
								printf("Enter the second number: ");
								n = new_gets(s,lim);
								w->A = (int*)malloc(n*sizeof(int));
								input(w,s,n);
								res = DIV_NN_N(q,w);
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
							case 12:
								printf("Enter the first number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);
								printf("Enter the second number: ");
								n = new_gets(s,lim);
								w->A = (int*)malloc(n*sizeof(int));
								input(w,s,n);
								res = MOD_NN_N(q,w);
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
							case 13:
								printf("Enter the first number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);
								printf("Enter the second number: ");
								n = new_gets(s,lim);
								w->A = (int*)malloc(n*sizeof(int));
								input(w,s,n);
								res = GCF_NN_N(q,w);
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
							case 14:
								printf("Enter the first number: ");
								getchar();
								n = new_gets(s,lim);
								q->A = (int*)malloc(n*sizeof(int));
								input(q,s,n);
								printf("Enter the second number: ");
								n = new_gets(s,lim);
								w->A = (int*)malloc(n*sizeof(int));
								input(w,s,n);
								res = LCM_NN_N(q,w);
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
							default:
							break;
						}
	        		}
	        	}
	        	if(clas == 2)
	        	{
	        		d = (Z*)malloc(sizeof(Z));
	        		t = (Z*)malloc(sizeof(Z));
	        		resZ = (Z*)malloc(sizeof(Z));
	        		if(d && t)
	        		{
	        			switch(integer())
	        			{
	        				case 1:
			        			printf("Enter your number: ");
			        			getchar();
			        			n = new_gets(s,lim);
			        			d->num = (N*)malloc(sizeof(N));
			        			d->num->A = (int*)malloc(n*sizeof(int));
			        			d->sign = input(d->num,s,n);
			        			printf("Result: ");
			        			output(ABS_Z_N(d));
		     					break;
	        				case 2:
			        			printf("Enter your number: ");
			        			getchar();
			        			n = new_gets(s,lim);
			        			d->num = (N*)malloc(sizeof(N));
			        			d->num->A = (int*)malloc(n*sizeof(int));
			        			d->sign = input(d->num,s,n);
			        			printf("Result: ");
			        			if(POZ_Z_D(d) == 2) printf("The number is positive\n");
			        			if(POZ_Z_D(d) == 1) printf("The number is negative\n");
			        			if(POZ_Z_D(d) == 0) printf("The number is zero\n");
			        			break;
		        			case 3:
			        			printf("Enter your number: ");
			        			getchar();
			        			n = new_gets(s,lim);
			        			d->num = (N*)malloc(sizeof(N));
			        			d->num->A = (int*)malloc(n*sizeof(int));
			        			d->sign = input(d->num,s,n);
			        			printf("Result: ");
			        			MUL_ZM_Z(d);
			        			output_int(d);
		        				break;
		        			case 4:
		        				printf("Enter your number: ");
			        			getchar();
			        			n = new_gets(s,lim);
			        			q = (N*)malloc(sizeof(N));
			        			q->A = (int*)malloc(n*sizeof(int));
			        			input(q,s,n);
			        			d = TRANS_N_Z(q);
			        			printf("Result: ");
			        			output_int(d);
			        		case 5:
		        				printf("Enter your number: ");
			        			getchar();
			        			n = new_gets(s,lim);
			        			d->num = (N*)malloc(sizeof(N));
			        			d->num->A = (int*)malloc(n*sizeof(int));
			        			d->sign = input(d->num,s,n);
			        			TRANS_Z_N(d);
			        			printf("Result: ");
			        			output(q);
			        		case 6:
			        			printf("Enter first number: ");
			        			getchar();
			        			n = new_gets(s,lim);
			        			d->num = (N*)malloc(sizeof(N));
			        			d->num->A = (int*)malloc(n*sizeof(int));
			        			d->sign = input(d->num,s,n);
			        			printf("Enter second number: ");
			        			n = new_gets(s,lim);
			        			t->num = (N*)malloc(sizeof(N));
			        			t->num->A = (int*)malloc(n*sizeof(int));
			        			t->sign = input(t->num,s,n);
			        			resZ = ADD_ZZ_Z(d,t);
			        			printf("Result: ");
			        			output_int(resZ);
			        			free(resZ);
			        			resZ=NULL;
			        			break;
			        		case 7:
			        			printf("Enter first number: ");
			        			getchar();
			        			n = new_gets(s,lim);
			        			d->num = (N*)malloc(sizeof(N));
			        			d->num->A = (int*)malloc(n*sizeof(int));
			        			d->sign = input(d->num,s,n);
			        			printf("Enter second number: ");
			        			n = new_gets(s,lim);
			        			t->num = (N*)malloc(sizeof(N));
			        			t->num->A = (int*)malloc(n*sizeof(int));
			        			t->sign = input(t->num,s,n);
			        			resZ = SUB_ZZ_Z(d,t);
			        			printf("Result: ");
			        			output_int(resZ);
			        			free(resZ);
			        			resZ=NULL;
			        			break;
			        		case 8:
			        			printf("Enter first number: ");
			        			getchar();
			        			n = new_gets(s,lim);
			        			d->num = (N*)malloc(sizeof(N));
			        			d->num->A = (int*)malloc(n*sizeof(int));
			        			d->sign = input(d->num,s,n);
			        			printf("Enter second number: ");
			        			n = new_gets(s,lim);
			        			t->num = (N*)malloc(sizeof(N));
			        			t->num->A = (int*)malloc(n*sizeof(int));
			        			t->sign = input(t->num,s,n);
			        			resZ = MUL_ZZ_Z(d,t);
			        			printf("Result: ");
			        			output_int(resZ);
			        			free(resZ);
			        			resZ=NULL;
		        				break;
		        			case 9:
			        			printf("Enter first number: ");
			        			getchar();
			        			n = new_gets(s,lim);
			        			d->num = (N*)malloc(sizeof(N));
			        			d->num->A = (int*)malloc(n*sizeof(int));
			        			d->sign = input(d->num,s,n);
			        			printf("Enter second number: ");
			        			n = new_gets(s,lim);
			        			t->num = (N*)malloc(sizeof(N));
			        			t->num->A = (int*)malloc(n*sizeof(int));
			        			t->sign = input(t->num,s,n);
			        			resZ = DIV_ZZ_Z(d,t);
			        			printf("Result: ");
			        			output_int(resZ);
			        			free(resZ);
			        			resZ=NULL;
		        				break;
		        			case 10:
			        			printf("Enter first number: ");
			        			getchar();
			        			n = new_gets(s,lim);
			        			d->num = (N*)malloc(sizeof(N));
			        			d->num->A = (int*)malloc(n*sizeof(int));
			        			d->sign = input(d->num,s,n);
			        			printf("Enter second number: ");
			        			n = new_gets(s,lim);
			        			t->num = (N*)malloc(sizeof(N));
			        			t->num->A = (int*)malloc(n*sizeof(int));
			        			t->sign = input(t->num,s,n);
			        			resZ = MOD_ZZ_Z(d,t);
			        			printf("Result: ");
			        			output_int(resZ);
			        			free(resZ);
			        			resZ=NULL;
		        				break;
	        				default:
	        				break;
	        			}
	        		}

	        	}
	        	if(clas == 3)
	        	{
	        		h = (Q*)malloc(sizeof(Q));
	        		l =	(Q*)malloc(sizeof(Q));
	        		if(h && l)
	        		{
	        			switch(rational())
	        			{
	        				case 1:
	        					printf("Enter numerator of number: ");
								getchar();
								n = new_gets(s,lim);
								h->m = (Z*)malloc(sizeof(Z));
								h->m->num = (N*)malloc(sizeof(N));
								h->m->num->A = (int*)malloc(n*sizeof(int));
								h->m->sign = input(h->m->num,s,n);
								printf("Enter denumerator of number: ");
								n = new_gets(s,lim);
								h->n = (N*)malloc(sizeof(N));
								h->n->A = (int*)malloc(n*sizeof(int));
								input(h->n,s,n);
								l = RED_Q_Q(h);
								output_rat(l);
								break;
							case 3:
								printf("Enter your number: ");
			        			getchar();
			        			n = new_gets(s,lim);
			        			d = (Z*)malloc(sizeof(Z));
			        			d->num = (N*)malloc(sizeof(N));
			        			d->num->A = (int*)malloc(n*sizeof(int));
			        			d->sign = input(d->num,s,n);
			        			output_int(d);
			        			printf("Result: ");
			        			output_rat(TRANS_Z_Q(d));
		     					break;
		     				case 4:
								printf("Enter numerator of first number: ");
								getchar();
								n = new_gets(s,lim);
								h->m = (Z*)malloc(sizeof(Z));
								h->m->num = (N*)malloc(sizeof(N));
								h->m->num->A = (int*)malloc(n*sizeof(int));
								h->m->sign = input(h->m->num,s,n);
								printf("Enter denumerator of first number: ");
								n = new_gets(s,lim);
								h->n = (N*)malloc(sizeof(N));
								h->n->A = (int*)malloc(n*sizeof(int));
								input(h->n,s,n);
			        			
			        			printf("Result: ");
			        			output_int(TRANS_Q_Z(h));
		     					break;
							case 5:
								printf("Enter numerator of first number: ");
								getchar();
								n = new_gets(s,lim);
								h->m = (Z*)malloc(sizeof(Z));
								h->m->num = (N*)malloc(sizeof(N));
								h->m->num->A = (int*)malloc(n*sizeof(int));
								h->m->sign = input(h->m->num,s,n);
								printf("Enter denumerator of first number: ");
								n = new_gets(s,lim);
								h->n = (N*)malloc(sizeof(N));
								h->n->A = (int*)malloc(n*sizeof(int));
								input(h->n,s,n);
								printf("Enter numerator of second number: ");
								n = new_gets(s,lim);
								l->m = (Z*)malloc(sizeof(Z));
								l->m->num = (N*)malloc(sizeof(N));
								l->m->num->A = (int*)malloc(n*sizeof(int));
								l->m->sign = input(l->m->num,s,n);
								printf("Enter denumerator of second number: ");
								n = new_gets(s,lim);
								l->n = (N*)malloc(sizeof(N));
								l->n->A = (int*)malloc(n*sizeof(int));
								input(l->n,s,n);
								output_rat(ADD_QQ_Q(h,l));
								break;
							case 6:
								printf("Enter numerator of first number: ");
								getchar();
								n = new_gets(s,lim);
								h->m = (Z*)malloc(sizeof(Z));
								h->m->num = (N*)malloc(sizeof(N));
								h->m->num->A = (int*)malloc(n*sizeof(int));
								h->m->sign = input(h->m->num,s,n);
								printf("Enter denumerator of first number: ");
								n = new_gets(s,lim);
								h->n = (N*)malloc(sizeof(N));
								h->n->A = (int*)malloc(n*sizeof(int));
								input(h->n,s,n);
								printf("Enter numerator of second number: ");
								n = new_gets(s,lim);
								l->m = (Z*)malloc(sizeof(Z));
								l->m->num = (N*)malloc(sizeof(N));
								l->m->num->A = (int*)malloc(n*sizeof(int));
								l->m->sign = input(l->m->num,s,n);
								printf("Enter denumerator of second number: ");
								n = new_gets(s,lim);
								l->n = (N*)malloc(sizeof(N));
								l->n->A = (int*)malloc(n*sizeof(int));
								input(l->n,s,n);
								output_rat(l);
								output_rat(SUB_QQ_Q(h,l));
								break;
							case 7:
								printf("Enter numerator of first number: ");
								getchar();
								n = new_gets(s,lim);
								h->m = (Z*)malloc(sizeof(Z));
								h->m->num = (N*)malloc(sizeof(N));
								h->m->num->A = (int*)malloc(n*sizeof(int));
								h->m->sign = input(h->m->num,s,n);
								printf("Enter denumerator of first number: ");
								n = new_gets(s,lim);
								h->n = (N*)malloc(sizeof(N));
								h->n->A = (int*)malloc(n*sizeof(int));
								input(h->n,s,n);
								printf("Enter numerator of second number: ");
								n = new_gets(s,lim);
								l->m = (Z*)malloc(sizeof(Z));
								l->m->num = (N*)malloc(sizeof(N));
								l->m->num->A = (int*)malloc(n*sizeof(int));
								l->m->sign = input(l->m->num,s,n);
								printf("Enter denumerator of second number: ");
								n = new_gets(s,lim);
								l->n = (N*)malloc(sizeof(N));
								l->n->A = (int*)malloc(n*sizeof(int));
								input(l->n,s,n);

								output_rat(MUL_QQ_Q(h,l));
								break;
							case 8:
								printf("Enter numerator of first number: ");
								getchar();
								n = new_gets(s,lim);
								h->m = (Z*)malloc(sizeof(Z));
								h->m->num = (N*)malloc(sizeof(N));
								h->m->num->A = (int*)malloc(n*sizeof(int));
								h->m->sign = input(h->m->num,s,n);
								printf("Enter denumerator of first number: ");
								n = new_gets(s,lim);
								h->n = (N*)malloc(sizeof(N));
								h->n->A = (int*)malloc(n*sizeof(int));
								input(h->n,s,n);
								printf("Enter numerator of second number: ");
								n = new_gets(s,lim);
								l->m = (Z*)malloc(sizeof(Z));
								l->m->num = (N*)malloc(sizeof(N));
								l->m->num->A = (int*)malloc(n*sizeof(int));
								l->m->sign = input(l->m->num,s,n);
								printf("Enter denumerator of second number: ");
								n = new_gets(s,lim);
								l->n = (N*)malloc(sizeof(N));
								l->n->A = (int*)malloc(n*sizeof(int));
								input(l->n,s,n);
								output_rat(MUL_QQ_Q(h,l));
								break;
	        				default:
	        				break;
	        			}
	        		}
	        
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

