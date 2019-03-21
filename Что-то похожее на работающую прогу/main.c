#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "struct.h"
#include "functions.h"
#include "natural.h"
#include "integer.h"
#include "rational.h"
#include "polynom.h"
#ifdef _WIN32
#define CLEAR_WINDOW system("cls");
#else
#define CLEAR_WINDOW system("clear");
#endif

// Тестовый main хомяка. не трогать
int mainT(){
    P* A = polynom_parsing();
	Q *t = LED_P_Q(A); 
	output_rat(t);
	clear_P(A);
	return 0;
}

int main()
{
	N *q, *w,*res;
	Z *d, *t, *resZ;
	Q *h, *l, *resQ;
	P *g,*f, *resP;
	int n,i,lim,key,clas,num,sign,key1;
	char c_sign;
	char *s;
	lim = 150;
	s = (char*)malloc(lim*sizeof(char));
	if(s != NULL)
	{
		while( (key = menu()) != 3)
		{
		    CLEAR_WINDOW
		    if(key != 3 && key != 2 && key != 1)
	        {
	            printf("Enter a correct answer!\n");
	        }
	        if(key == 1)
	        {
	        	printf("Choose class of number to work:\n0-Back to main menu\n1-Natural+{0}\n2-Integer\n3-Rational\n4-Polinom\nYour answer: ");
	        	scanf("%d", &clas);
	        	while(clas != 0)
	        	{
		        	CLEAR_WINDOW
		        	if(clas == 1)
		        	{
		        			switch(natural())
							{
								case 0:
		        					break;
								case 1:
									printf("Enter the first number: ");
									getchar();
									q = natural_parsing(s,lim);
									printf("Enter the second number: ");
									w = natural_parsing(s,lim);
									if(q && w)
									{
										if(COM_NN_D(q,w)==2) 
											printf("The first number is bigger\n"); 
										else 
											if(COM_NN_D(q,w)==0) 
												printf("The numbers are equal\n"); 
											else 
												printf("The second number is bigger\n");
										clear_N(q);
										clear_N(w);
									}
									else
										printf("Error at number allocation!\n");
									break;
								case 2:
									printf("Enter your number: ");
									getchar();
									q = natural_parsing(s,lim);
									if(q)
									{
										if(NZER_N_B(q) == 1)
											printf("Your number equals zero\n");
										else
											printf("Your number doesn't equal zero\n");
										clear_N(q);
									}
									else
										printf("Error at number allocation!\n");
									break;
								case 3:
									printf("Enter your number: ");
									getchar();
									q = natural_parsing(s,lim);
									if(q)
									{
										ADD_1N_N(q);
										printf("Result: ");
										output(q);
										puts("");
										clear_N(q);
									}
									else 
										printf("Error at number allocation!\n");
									break;		
								case 4:
									printf("Enter the first number: ");
									getchar();
									q = natural_parsing(s,lim);
									printf("Enter the second number: ");
									w = natural_parsing(s,lim);
									res = ADD_NN_N(q,w);
									if(q && w && res)
									{
										printf("Result: ");
										output(res);
										printf("\n");
										clear_N(q);
										clear_N(w);
										clear_N(res);
									}
									else
										printf("Error at number allocation!\n");
									break;		
								case 5: 
									printf("Enter the first number: ");
									getchar();
									q = natural_parsing(s,lim);
									printf("Enter the second number: ");
									w = natural_parsing(s,lim);
									res = SUB_NN_N(q,w);
									if(q && w && res)
									{
										printf("Result: ");
										output(res);
										printf("\n");
										clear_N(res);
										clear_N(q);
										clear_N(w);
									}
										printf("Error at number allocation!\n");
									break;		
								case 6:
									printf("Enter your number: ");
									getchar();
									q = natural_parsing(s,lim);
									printf("Enter digit: ");
									scanf("%d", &num);
									res = MUL_NN_N(q,w);
									if(q && res)
									{
										printf("Result: ");
										output(res);
										printf("\n");
										clear_N(q);
										clear_N(res);
									}
									else 
										printf("Error at number allocation!\n");
									break;
								case 7:
									printf("Enter your number: ");
									getchar();
									q = natural_parsing(s,lim);
									printf("Enter k: ");
									scanf("%d", &num);
									res = MUL_Nk_N(q,num);
									if(q && res)
									{
										printf("Result: ");
										output(res);
										puts("");
										clear_N(res);
										clear_N(q);
									}
									else 
										printf("Error at number allocation!\n");
									break;
								case 8: 
									printf("Enter the first number: ");
									getchar();
									q = natural_parsing(s,lim);
									printf("Enter the second number: ");
									w = natural_parsing(s,lim);
									res = MUL_NN_N(q,w);
									if(q && w && res)
									{
										printf("Result: ");
										output(res);
										puts("");
										clear_N(res);
										clear_N(q);
										clear_N(w);
									}
									else 
										printf("Error at number allocation!\n");
									break;
								 case 9:
								 	printf("Enter the first number: ");
									getchar();
									q = natural_parsing(s,lim);
									printf("Enter digit: ");
									scanf("%d", &num);
									printf("Enter the second number: ");
									getchar();
									w = natural_parsing(s,lim);
									res = SUB_NDN_N(q,num,w);
									if(q && w && SUB_NDN_N(q,num,w))
									{
										printf("Result: ");
										output(res);
										puts("");
										clear_N(SUB_NDN_N(q,num,w));
										clear_N(q);
										clear_N(w);
									}
									else 
										printf("Eror at at number allocation!\n");
									break;
								case 10:
									printf("Enter the first number: ");
									getchar();
									q = natural_parsing(s,lim);
									printf("Enter the second number: ");
									w = natural_parsing(s,lim);
									if(q && w)
									{
										printf("Result: %d", DIV_NN_Dk(q,w)[0]);
										puts("");
										clear_N(q);
										clear_N(w);
									}
									break;
								case 11:
									printf("Enter the first number: ");
									getchar();
									q = natural_parsing(s,lim);
									printf("Enter the second number: ");
									w = natural_parsing(s,lim);
									res = DIV_NN_N(q,w);
									if(q && w && res)
									{
										printf("Result: ");
										output(res);
										puts("");
										clear_N(q);
										clear_N(w);
										clear_N(res);
									}
									else 
										printf("Error at at number allocation!\n");
									break;
								case 12:
									printf("Enter the first number: ");
									getchar();
									q = natural_parsing(s,lim);
									printf("Enter the second number: ");
									w = natural_parsing(s,lim);
									res = MOD_NN_N(q,w);
									if(q && w && res)
									{
										printf("Result: ");
										output(res);
										puts("");
										clear_N(q);
										clear_N(w);
										clear_N(res);
									}
									else 
										printf("Result is NULL!\n");
									break;
								case 13:
									printf("Enter the first number: ");
									getchar();
									q = natural_parsing(s,lim);
									printf("Enter the second number: ");
									w = natural_parsing(s,lim);
									res = GCF_NN_N(q,w);
									if(q && w && res)
									{
										printf("Result: ");
										output(res);
										puts("");
										clear_N(q);
										clear_N(w);
										clear_N(res);
									}
									else 
										printf("Result is NULL!\n");
									break;
								case 14:
									printf("Enter the first number: ");
									getchar();
									q = natural_parsing(s,lim);
									printf("Enter the second number: ");
									w = natural_parsing(s,lim);
									res = LCM_NN_N(q,w);
									if(res && q && w)
									{
										printf("Result: ");
										output(res);
										puts("");
										clear_N(q);
										clear_N(w);
										clear_N(res);
									}
									else 
										printf("Result is NULL!\n");
									break;
								default:
									printf("Enter correct answer!\n");
									break;
							}
		        	}
		        	if(clas == 2)
		        	{
		    			switch(integer())
		    			{
		    				case 0:
		        					break;
		    				case 1:
			        			printf("Enter your number: ");
			        			getchar();
			        			d = int_parsing(s,lim);
			        			if(d)
			        			{
			        				printf("Result: ");
			        				output(ABS_Z_N(d));
			        				puts("");
			        				clear_Z(d);
			        			}
			        			else
			        				printf("Error at array allocation!\n");
		     					break;
		    				case 2:
			        			printf("Enter your number: ");
			        			getchar();
			        			d = int_parsing(s,lim);
			        			if(d)
			        			{
			        				printf("Result: ");
				        			if(POZ_Z_D(d) == 2) printf("The number is positive\n");
				        			if(POZ_Z_D(d) == 1) printf("The number is negative\n");
				        			if(POZ_Z_D(d) == 0) printf("The number is zero\n");
				        			clear_Z(d);
			        			}
			        			else
			        				printf("Error at array allocation!\n");
			        			break;
		        			case 3:
			        			printf("Enter your number: ");
			        			getchar();
			        			d = int_parsing(s,lim);
			        			if(d)
			        			{
			        				printf("Result: ");
			        				MUL_ZM_Z(d);
			        				output_int(d);
			        				puts("");
			        				clear_Z(d);
			        			}
			        			else
			        				printf("Error at array allocation!\n");

		        				break;
		        			case 4:
		        				printf("Enter your number: ");
			        			getchar();
			        			q = natural_parsing(s,lim);
			        			if(d)
			        			{
			        				d = TRANS_N_Z(q);
			        				printf("Result: ");
			        				output_int(d);
			        				puts("");
			        				clear_Z(d);
			        				clear_N(q);
			        			}
			        				printf("Error at array allocation!\n");		        			
			        		case 5:
		        				printf("Enter your number: ");
			        			getchar();
			        			d = int_parsing(s,lim);
			        			if(d)
			        			{
			        				q = TRANS_Z_N(d);
				        			printf("Result: ");
				        			output(q);
				        			puts("");
				        			clear_N(q);
				        			clear_Z(d);
			        			}
			        			else
			        				printf("Error at array allocation!\n");

			        		case 6:
			        			printf("Enter first number: ");
			        			getchar();
			        			d = int_parsing(s,lim);
			        			printf("Enter second number: ");
			        			t = int_parsing(s,lim);
			        			if(d && t)
			        			{
			        				resZ = ADD_ZZ_Z(d,t);
			        				printf("Result: ");
			        				output_int(resZ);
			        				puts("");
			        				//clear_Z(d);
			        				//clear_Z(t);
			        				//clear_Z(resZ);
			        			}
			        			else
			        				printf("Error at array allocation!\n");
			        			break;
			        		case 7:
			        			printf("Enter first number: ");
			        			getchar();
			        			d = int_parsing(s,lim);
			        			printf("Enter second number: ");
			        			t = int_parsing(s,lim);
			        			resZ = SUB_ZZ_Z(d,t);
			        			if(resZ && d && t)
			        			{
			        				printf("Result: ");
			        				output_int(resZ);
			        				puts("");
			        				//clear_Z(resZ);
			        				//clear_Z(d);
			        				//clear_Z(t);
			        			}
			        			else
			        				printf("Error at array allocatin!\n");
			        			break;
			        		case 8:
			        			printf("Enter first number: ");
			        			getchar();
			        			d = int_parsing(s,lim);
			        			printf("Enter second number: ");
			        			t = int_parsing(s,lim);
			        			resZ = MUL_ZZ_Z(d,t);
			        			if(resZ && d && t)
			        			{
				        			printf("Result: ");
				        			output_int(resZ);
				        			puts("");
				        			clear_Z(resZ);
			        				clear_Z(d);
			        				clear_Z(t);
				        		}
				        		else
			        				printf("Error at array allocatin!\n");
		        				break;
		        			case 9:
			        			printf("Enter first number: ");
			        			getchar();
			        			d = int_parsing(s,lim);
			        			printf("Enter second number: ");
			        			t = int_parsing(s,lim);
			        			resZ = DIV_ZZ_Z(d,t);
			        			if(resZ && d && t)
			        			{
			        				printf("Result: ");
			        				output_int(resZ);
			        				puts("");
			        				clear_Z(resZ);
			        				clear_Z(d);
			        				clear_Z(t);
			        			}
			        			else
			        				printf("Error at array allocatin!\n");
		        				break;
		        			case 10:
			        			printf("Enter first number: ");
			        			getchar();
			        			d = int_parsing(s,lim);
			        			printf("Enter second number: ");
			        			t = int_parsing(s,lim);
			        			resZ = MOD_ZZ_Z(d,t);
			        			if(resZ && d && t)
			        			{
			        				printf("Result: ");
			        				output_int(resZ);
			        				puts("");
			        				clear_Z(resZ);
			        				clear_Z(d);
			        				clear_Z(t);
			        			}
			        			else
			        				printf("Error at array allocatin!\n");
		        				break;
		    				default:
		    					printf("Enter correct answer!\n");
		    				break;
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
		        				case 0:
		        					break;
		        				case 1:
		        					printf("Enter your number: ");
									getchar();
									new_gets(s,lim);
									h = rat_parsing(s);
									if(h)
									{
										printf("Result: ");
										output_rat(RED_Q_Q(h));
										puts("");
										clear_Q(h);
									}
									break;
								case 2:
									printf("Enter your number: ");
									getchar();
									new_gets(s,lim);
									h = rat_parsing(s);
									if(h)
									{
										if(INT_Q_B(h) == 1) 
										{
											printf("Your number is integer: ");
											output_rat(RED_Q_Q(h));

										}
										else
										{
											printf("Your number is rational: ");
											output_rat(RED_Q_Q(h));									
										}
										puts("");
									}
									else
										printf("Error at number allocation!\n");
									break;
								case 3:
									printf("Enter your number: ");
				        			getchar();
				        			d = int_parsing(s,lim);
				        			if(h)
				        			{
				        				printf("Result: ");
				        				output_rat(TRANS_Z_Q(d));
				        				clear_Q(TRANS_Z_Q(d));
				        			}
				        			else
										printf("Error at number allocation!\n");
			     					break;
			     				case 4:
									printf("Enter your number: ");
									getchar();
									new_gets(s,lim);
									h = rat_parsing(s);
									if(h)
									{
				        				printf("Result: ");
				        				output_int(TRANS_Q_Z(h));
				        				clear_Z(TRANS_Q_Z(h));
				        				puts("");
				        			}
				        			else
										printf("Error at number allocation!\n");
			     					break;
								case 5:
									printf("Enter your first number: ");
									getchar();
									new_gets(s,lim);
									h = rat_parsing(s);
									printf("Enter your second number: ");
									new_gets(s,lim);
									l = rat_parsing(s);
									resQ = ADD_QQ_Q(h,l);
									if(h && l && resQ)
									{
										printf("Result: ");
										output_rat(resQ);
										clear_Q(h);
										clear_Q(l);
										clear_Q(resQ);
									}
									else
										printf("Error at number allocation!\n");
									break;
								case 6:
									printf("Enter your first number: ");
									getchar();
									new_gets(s,lim);
									h = rat_parsing(s);
									printf("Enter your second number: ");
									new_gets(s,lim);
									l = rat_parsing(s);
									resQ = SUB_QQ_Q(h,l);
									if(h && l && resQ)
									{
										printf("Result: ");
										output_rat(resQ);
										clear_Q(h);
										clear_Q(l);
										clear_Q(resQ);
									}
									else
										printf("Error at number allocation!\n");
									break;
								case 7:
									printf("Enter your first number: ");
									getchar();
									new_gets(s,lim);
									h = rat_parsing(s);
									printf("Enter your second number: ");
									new_gets(s,lim);
									l = rat_parsing(s);
									resQ = MUL_QQ_Q(h,l);
									if(h && l && resQ)
									{
										printf("Result: ");
										output_rat(resQ);
										clear_Q(h);
										clear_Q(l);
										clear_Q(resQ);
									}
									else
										printf("Error at number allocation!\n");
									break;
								case 8:
									printf("Enter your first number: ");
									getchar();
									new_gets(s,lim);
									h = rat_parsing(s);
									printf("Enter your second number: ");
									new_gets(s,lim);
									l = rat_parsing(s);
									resQ = DIV_QQ_Q(h,l);
									if(h && l && resQ)
									{
										printf("Result: ");
										output_rat(resQ);
										clear_Q(h);
										clear_Q(l);
										clear_Q(resQ);
									}
									else
										printf("Error at number allocation!\n");
									break;
		        				default:
		        					printf("Enter correct answer!\n");
		        				break;
		        			}
		        		}
		        
		        	}
		        	if(clas == 4)
		        	{

		        	}
		        
		        printf("\nEnter any key when ready");
		        getchar();
		        CLEAR_WINDOW
		        printf("Choose class of number to work:\n0-Back to main menu\n1-Natural+{0}\n2-Integer\n3-Rational\n4-Polinom\nYour answer: ");
	        	scanf("%d", &clas);
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
	if( (a->n->n == 1) && (a->n->A[0] == 1) )
	{
		;//printf("\n"); ЕСЛИ НЕ БУДЕТ РАБОТАТЬ, СДЕЛАЙТЕ ПЕРЕГРУЗКУ С ФУНКЦИЕЙ
	}
	else
	{
		printf("/");
		output(a->n);
		printf("\n");
	}
}

void output_pol(P *mas){
    // Выводит многочлен в виде Ax^n+...+Z
    int i;
    for(i=mas->deg-1;i>=0;i--){
        printf("%c",(mas->deg==1)?'\0':'+');
        output_rat(&mas->c[i]);
        printf("x^%d",i);
        }
        printf("\n");
}

void print_header()
{
	CLEAR_WINDOW
	printf("\t\t\t\tDiscrethe Math\n\t\tComputer Algebra System by students 8306");
}

int menu()
{
	int key;
	print_header();
	printf("\n\t\t\t\tMENU\n");
	printf("Press '1' to start\nPress '2' to check information about program\nPress '3' to close the program\nPress 'F' to pay respect\nYour answer: ");
	scanf("%d", &key);
	system("clear");

	return key;
}

N* natural_parsing(char *s, int lim)
{
	N* b;
	int n;
	n = new_gets(s,lim);
	b = (N*)malloc(sizeof(N));
	if(b)
	{
		b->A = (int*)malloc(n*sizeof(int));
		input(b,s,n);
	}
	return b;
}

Z* int_parsing(char *s, int lim)
{
	Z* a;
	int n;
	n = new_gets(s,lim);
	a = (Z*)malloc(sizeof(Z));
	a->num = (N*)malloc(sizeof(N));
	a->num->A = (int*)malloc(n*sizeof(int));
	a->sign = input(a->num,s,n);
	return a;
}

P* polynom_parsing(){
    // Спрашивает у пользователя многочлен и возвращает его
    int deg,i;
    char buf[150];
    P* result;
    printf("Enter the highest degree of the polynom:");
    scanf("%d", &deg);
    deg++;
    printf("Now program will ask you coef's at every power\n");
    if(deg>0){
        // Пошла жара
        result = (P*)malloc(sizeof(P));
        result->c = (Q*)calloc(deg,sizeof(Q));
        result->deg =deg;
    for(i=result->deg-1;i>=0;i--){
            printf("x^%d: ",i);
            fseek(stdin,0,SEEK_END);
            new_gets(buf,150);
            Q* tmp = rat_parsing(buf);
            result->c[i] = *tmp;
            free(tmp);
        }
    }
    return result;
}


Q* rat_parsing(char *s)
{
	char *s1,*s2;
	Q* a;
	int lim;
	lim = 150;
	int i,j,size_s1,size_s2;
	s1 = (char*)malloc(lim*sizeof(char));
	s2 = (char*)malloc(lim*sizeof(char));
	i = 0;
	j = 0;
	if(s1 && s2)
	{
		while(s[i] != '/' && s[i] != '\0')
		{
			s1[i] = s[i];
			i++;
		}
		s1[i] = '\0';
		if(s[i] == '/')
		{
			i+=1;
			while(s[i] != '\0')
			{
				s2[j] = s[i];
				i++;
				j++;
			}
			s2[j] = '\0';
			size_s1 = strlen(s1);
			size_s2 = strlen(s2);	
			a = (Q*)malloc(sizeof(Q));
			a->m = (Z*)malloc(sizeof(Z));
			a->m->num = (N*)malloc(sizeof(N));
			a->m->num->A = (int*)malloc(size_s1*sizeof(int));
			a->m->sign = input(a->m->num,s1,size_s1);
			a->n = (N*)malloc(sizeof(N));
			a->n->A = (int*)malloc(size_s2*sizeof(int));
			input(a->n,s2,size_s2);
		}
		else
		{
			s2[0] = '1';
			s2[1] = '\0';
			size_s1 = strlen(s1);
			size_s2 = strlen(s2);		
			a = (Q*)malloc(sizeof(Q));
			a->m = (Z*)malloc(sizeof(Z));
			a->m->num = (N*)malloc(sizeof(N));
			a->m->num->A = (int*)malloc(size_s1*sizeof(int));
			a->m->sign = input(a->m->num,s1,size_s1);
			a->n = (N*)malloc(sizeof(N));
			a->n->A = (int*)malloc(size_s2*sizeof(int));
			input(a->n,s2,size_s2);
		}
		free(s1);
		free(s2);
		s1 = NULL;
		s2 = NULL;
	}
	return a;
}

void clear_N(N* a)
{
	free(a->A);
	a->A = NULL;
	free(a);
	a = NULL;
}

void clear_Z(Z* a)
{
	clear_N(a->num);
	free(a);
	a = NULL;
}

void clear_Q(Q* a)
{
	clear_Z(a->m);
	clear_N(a->n);
}

void clear_P(P *mas){
    // Чистит всё, что связанно с многочленами
    int i;
    for(i=0;i<mas->deg;i++)
        clear_Q(&(mas->c[i]));
    free(mas);
}