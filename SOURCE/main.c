#define STDSIZE 150
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
int main(){
    P* A = polynom_parsing();
	P* B = polynom_parsing();
	//P* C = NMR_P_P(A);
	P* C = GCF_PP_P(A,B);
	output_pol(C);
	clear_P(C);
	clear_P(A);
	clear_P(B);
	return 0;
}

int mainT()
{
	N *q=NULL, *w=NULL,*res=NULL;
	Z *d=NULL, *t=NULL, *resZ=NULL;
	Q *h=NULL, *l=NULL, *resQ=NULL;
	P *g=NULL,*f=NULL, *resP=NULL;
	int n,i,lim,key,clas,num,sign,key1;
	char c_sign;
	char choose;
	char *s;
	char s1[256];
	FILE *df;
	lim = STDSIZE;
	s = (char*)malloc(lim*sizeof(char));
	if(s != NULL)
	{
		while( (choose = menu()) != '3')
		{
		    CLEAR_WINDOW
		    if(choose != '3' && choose != '2' && choose != '1' && choose != 'F' && choose != 'f')
	        {
	            printf("Enter a correct answer!\n");
	        }
	        if(choose == '1')
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
										printf("You enter: " );
										output(q);
										printf(" + 1 = ");
										ADD_1N_N(q);
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
										printf("You enter: " );
										output(q);
										printf(" + ");
										output(w);
										printf(" = ");
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
										printf("You enter: " );
										output(q);
										printf(" - ");
										output(w);
										printf(" = ");
										output(res);
										printf("\n");
										clear_N(res);
										clear_N(q);
										clear_N(w);
									}
									else
										printf("Error at number allocation!\n");
									break;
								case 6:
									printf("Enter your number: ");
									getchar();
									q = natural_parsing(s,lim);
									printf("Enter digit: ");
									scanf("%d", &num);
									getchar();
									res = MUL_ND_N(q,num);
									if(q && res)
									{
										printf("You enter: " );
										output(q);
										printf(" * %d = ", num);
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
										printf("You enter: " );
										output(q);
										printf(" * 10^%d = ", num);
										output(res);
										puts("");
										getchar();

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
										printf("You enter: " );
										output(q);
										printf(" * ");
										output(w);
										printf(" = ");
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
										printf("Your enter: ");
										output(q);
										printf(" DIV ");
										output(w);
										printf(" = ");
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
										printf("Your enter: ");
										output(q);
										printf(" MOD ");
										output(w);
										printf(" = ");
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
										printf("Your enter: ");
										output(q);
										printf(" NOD ");
										output(w);
										printf(" = ");
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
										printf("Your enter: ");
										output(q);
										printf(" NOK ");
										output(w);
										printf(" = ");
										output(res);
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
			        			d = TRANS_N_Z(q);
			        			if(d)
			        			{
			        				printf("Result: ");
			        				output_int(d);
			        				puts("");
			        				clear_Z(d);
			        				clear_N(q);
			        			}
			        			else
			        				printf("Error at array allocation!\n");
			        				break;
			        		case 5:
		        				printf("Enter your number: ");
			        			getchar();
			        			d = int_parsing(s,lim);
			        			q = TRANS_Z_N(d);
			        			if(d)
			        			{
				        			printf("Result: ");
				        			output(q);
				        			puts("");
				        			//clear_N(q);
				        			clear_Z(d);
			        			}
			        			else
			        				printf("Error at array allocation!\n");
			        			break;
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
			        				clear_Z(d);
			        				clear_Z(t);
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
			        				clear_Z(d);
			        				clear_Z(t);
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
		        	if(clas == 4)
		        	{
			        	switch(polynom())
		        		{
		        			case 0:
		        				break;
		        			case 1:
		        				printf("Entering first polynom\n");
		        				g = polynom_parsing();
		        				printf("Entering second polynom\n");
		        				f = polynom_parsing();
		        				resP = ADD_PP_P(g,f);
		        				if(resP && g && f)
		        				{
		        					printf("Result: ");
		        					output_pol(resP);
		        					clear_P(resP);
		        					clear_P(g);
		        					clear_P(f);
		        				}
		        				break;
		        			case 2:
		        				printf("Entering first polynom\n");
		        				g = polynom_parsing();
		        				printf("Entering second polynom\n");
		        				f = polynom_parsing();
		        				resP = SUB_PP_P(g,f);
		        				if(resP && g && f)
		        				{
		        					printf("Result: ");
		        					output_pol(resP);
		        					clear_P(resP);
		        					clear_P(g);
		        					clear_P(f);
		        				}
		        				break;
		        			case 3:
		        				g = polynom_parsing();
		        				printf("Enter your rational number: ");
		        				new_gets(s,lim);
		        				h = rat_parsing(s);
		        				resP = MUL_PQ_P(g,h);
		        				if(resP && g && h)
		        				{
		        					printf("Result: ");
		        					output_pol(resP);
		        					clear_P(resP);
		        					clear_P(g);
		        					clear_Q(h);
		        				}
		        				break;
		        			case 4:
		        				g = polynom_parsing();
		        				printf("Entering deg k of x^k: ");
		        				scanf("%d", &num);
		        				resP = MUL_Pxk_P(g,num);
		        				if(resP && g)
		        				{
		        					printf("Result: ");
		        					output_pol(resP);
		        					clear_P(resP);
		        					clear_P(g);
		        				}
		        					getchar();
		        				break;
		        			case 5:
		        				g = polynom_parsing();
		        				h = LED_P_Q(g);
		        				if(h&&g)
		        				{
		        					printf("Result: ");
		        					output_rat(h);
		        					//clear_P(g);
		        					//clear_Q(h);
		        				}
		        				break;
		        			case 6:
		        				g = polynom_parsing();
		        				num = DEG_P_N(g);
		        				if(h&&g)
		        				{
		        					printf("Result: %d", num);
		        					clear_P(g);
		        				}
		        				break;
		        			case 7:
		        				printf("Coming soon! :)");
		        				getchar();
		        				break;
		        			case 8:
		        				printf("Entering first polynom\n");
		        				g = polynom_parsing();
		        				printf("Entering second polynom\n");
		        				f = polynom_parsing();
		        				resP = MUL_PP_P(g,f);
		        				if(resP && g && f)
		        				{
		        					printf("Result: ");
		        					output_pol(resP);
		        					clear_P(resP);
		        					clear_P(g);
		        					clear_P(f);
		        				}
		        				break;
		        			case 9:
		        				printf("Entering first polynom\n");
		        				g = polynom_parsing();
		        				printf("Entering second polynom\n");
		        				f = polynom_parsing();
		        				resP = DIV_PP_P(g,f);
		        				if(resP && g && f)
		        				{
		        					printf("Result: ");
		        					output_pol(resP);
		        					clear_P(resP);
		        					clear_P(g);
		        					clear_P(f);
		        				}
		        				break;
		        			case 10:
		        				printf("Entering first polynom\n");
		        				g = polynom_parsing();
		        				printf("Entering second polynom\n");
		        				f = polynom_parsing();
		        				resP = MOD_PP_P(g,f);
		        				if(resP && g && f)
		        				{
		        					printf("Result: ");
		        					output_pol(resP);
		        					clear_P(resP);
		        					clear_P(g);
		        					clear_P(f);
		        				}
		        				break;
		        			case 11:
		        			/*
		        				printf("Entering first polynom\n");
		        				g = polynom_parsing();
		        				printf("Entering second polynom\n");
		        				f = polynom_parsing();
		        				resP = GCF_PP_P(g,f);
		        				if(resP && g && f)
		        				{
		        					printf("Result: ");
		        					output_pol(resP);
		        					clear_P(resP);
		        					clear_P(g);
		        					clear_P(f);
		        				}*/
		        				printf("Coming soon! :)");
		        				getchar();
		        				break;
		        			 case 12:
		        				g = polynom_parsing();
		        				resP = DER_P_P(g);
		        				if(resP && g)
		        				{
		        					printf("Result: ");
		        					output_pol(resP);
		        					clear_P(resP);
		        					clear_P(g);
		        				}

		        				break;
		        			case 13:
		        				printf("Coming soon! :)");
		        				getchar();
		        				break;
		        			default:
		        				break;
		        		}

		        	}
		        printf("\nEnter any key when ready");
		        getchar();

		        CLEAR_WINDOW
		        printf("Choose class of number to work:\n0-Back to main menu\n1-Natural+{0}\n2-Integer\n3-Rational\n4-Polinom\nYour answer: ");
	        	scanf("%d", &clas);
        		}
        	}
        	if(choose == '2')
        	{
        		printf_info();
        		printf("\nEnter any key when ready\n");
        		getchar();
		        getchar();
        	}
        	if(choose == 'F' || choose == 'f')
		    {
		    	df = fopen("./respects","a");
		    	fprintf(df,"1");
		    	fclose(df);
		    	df = fopen("./respects", "r");
		    	fgets(s1,256,df);
		    	i = 0;
		    	while(s1[i] != '\0')
		    		i++;
		    	printf("Your respect has been taken into account. Total amount of respects: %d", i);
		    	getchar();
		    	printf("\nEnter any key when ready");
		    	fclose(df);
		    	getchar();

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
	}
	else
	{
		printf("/");
		output(a->n);
	}

}

void output_pol(P *mas){
    // Output polynom  like Ax^n+...+Z
    int i;
    for(i=mas->deg-1;i>=0;i--)
    {
        if((NZER_N_B(mas->c[i]->m->num) == 0) || (i==0))
        {
        	printf("%c",(mas->c[i]->m->sign==1)?'\0':'+');
        	output_rat(mas->c[i]);
	        if(i!=0 && i!=1)
	        	printf("x^%d",i);
	        if(i==1)
	        	printf("x");
        }

    }
        printf("\n");
}

void print_header()
{
	CLEAR_WINDOW
	printf("\t\t\t\tDiscrethe Math\n\t\tComputer Algebra System by students 8306");
}
void printf_info()
{
	printf("This is the system of computer algebra made by students of 8306 group of LETI University\n");
	printf("The creation of the moduls was devided among students the following way: \n");
	printf("The module 'Naturals' was made by Tumanova Vera and Panfilova Maria\n");		
	printf("The module 'Integer' was made by Malov Pavel and Kuznetsov Artem\n"); 
	printf("The module 'Rational' was made by Slepov Artem and Miskevich Milena\n"); 
	printf("he module 'Polinom' was made by Andreev Vladimir and Saprykin Alexander.\n"); 
}
char menu()
{
	char key;
	print_header();
	printf("\n\t\t\t\tMENU\n");
	printf("Press '1' to start\nPress '2' to check information about the program\nPress '3' to close the program\nPress 'F' to pay respect\nYour answer: ");
	scanf("%c", &key);
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
    int deg,degree,i,j;
    char *buf,*s1,*s2;
    P* result;
    printf("Enter the highest degree of the polynom:");
    scanf("%d", &deg);
    deg++;
    buf = (char*)malloc(STDSIZE*sizeof(char));
    s1 = (char*)malloc(STDSIZE*sizeof(char));
    s2 = (char*)malloc(STDSIZE*sizeof(char));
    printf("Enter polynom in type: DEG COEF(Example: 5 32/7)\n");
    if(deg>0){
        // Пошла жара
        result = (P*)malloc(sizeof(P));
        result->c = (Q**)calloc(deg,sizeof(Q*));
        result->deg = deg;
        degree = 1;
        for(i = 0; i < deg; i++)
        {
        	result->c[i] = rat_parsing("0");
        }
        getchar();
        while(degree != 0)
        {

            new_gets(buf,STDSIZE);
            i = 0; j = 0;
            while(buf[i] != ' ')
            {
            	s1[i] = buf[i];
            	i+=1;
            }
            s1[i] = '\0';
            i+=1;
            j = 0;
            while(buf[i] != '\0')
            {
            	s2[j] = buf[i];
            	i+=1;
            	j+=1;
            }
            s2[j] = '\0';
            degree = atoi(s1);
            result->c[degree] = rat_parsing(s2);
        }
    }
    output_pol(result);
    return result;
}


Q* rat_parsing(char *s)
{
	char *s1,*s2;
	Q* a;
	int lim;
	lim = STDSIZE;
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
	if(a->num != NULL)clear_N(a->num);
	if(a!=NULL)
	{
		free(a);
		a = NULL;
	}
}

void clear_Q(Q* a)
{
	if(a->m != NULL) clear_Z(a->m);
	if(a->n != NULL) clear_N(a->n);
}

void clear_P(P *mas){
    // Чистит всё, что связанно с многочленами
    int i;
    for(i=0;i<mas->deg;i++){
        clear_Q(mas->c[i]);
		}
	free(mas->c);
    free(mas);
}
