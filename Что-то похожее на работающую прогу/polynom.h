#pragma once
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void clear_P(P*);
P* polynom_parsing();
void output_pol(P*);
int polynom();

int polynom()
{
    int key;
    printf("Choose operation with polynoms: ");
    printf("\n0-Back to menu\n1-Addition of polynoms\n2-Substract of polynoms\n3-Multiply bu number\n4-Multiply by x^k\n");
    printf("5-High coef of polynom\n6-Degrece of polynom\n7-The imposition of polynomial LCM of denominators of coefficients and the GCD of the numerators\n");
    printf("8-Multiplying of polynomoms\n9-The DIV a polynomial by a polynomial\n10-The MOD a polynomial by a polynomial\n11-GCD of polynoms\n");
    printf("12-Derivative of polynom\n13-Multiple roots in simple\nYour answer: ");
    scanf("%d", &key);
    return key;
}
//P-1
P* ADD_PP_P(P* first,P* second){
    int i;
    int maxDeg = ((first->deg>second->deg)?first->deg:second->deg);
    P* result = (P*)calloc(1,sizeof(P));
    Q* tmp;
    
    // Описание 0
    Q zero;
    int nu[1] = {0};
    int de[1] = {1};
    N a,b;
    Z c;
    a.n = 1;
    a.A = nu;
    c.sign = 1;
    c.num = &a;
    b.n = 1;
    b.A = de;
    zero.m = &c;
    zero.n = &b;
    //***
    result->deg = maxDeg;
    result->c = (Q**)calloc(maxDeg+1,sizeof(Q*));
    for(i=0;i<maxDeg;i++){
        if((i<first->deg)&&(i<second->deg)){
            result->c[i] = ADD_QQ_Q(first->c[i],second->c[i]);
        }
        else{
                if((i<first->deg))
                {
                    result->c[i] = ADD_QQ_Q(first->c[i],&zero);
                }                
                else
                    if((i<second->deg))
                    {
                        result->c[i] = ADD_QQ_Q(second->c[i],&zero);
                    }
        }
    }
    return result;
}

//P-2
P* SUB_PP_P(P* first,P* second){
    int i;
    int maxDeg = ((first->deg>second->deg)?first->deg:second->deg);
    P* result = (P*)calloc(1,sizeof(P));
    // Описание 0
    Q zero;
    int nu[1] = {0};
    int de[1] = {1};
    N a,b;
    Z c;
    a.n = 1;
    a.A = nu;
    c.sign = 1;
    c.num = &a;
    b.n = 1;
    b.A = de;
    zero.m = &c;
    zero.n = &b;
    //***
    result->deg = maxDeg;
    result->c = (Q**)calloc(maxDeg+1,sizeof(Q*));
    for(i=0;i<maxDeg;i++){
        if((i<first->deg)&&(i<second->deg)){
            result->c[i] = SUB_QQ_Q(first->c[i],second->c[i]);
        }
        else{
                if((i<first->deg))
                {
                    result->c[i] = SUB_QQ_Q(first->c[i],&zero);
                }                
                else
                    if((i<second->deg))
                    {
                        result->c[i] = SUB_QQ_Q(&zero,second->c[i]);
                    }
        }
    }
    return result;
}

//P-3
P* MUL_PQ_P(P* mas,Q* mult){
    int i;
    printf("Zashel v func '");
    Q *tmp;
    P* result = (P*)malloc(sizeof(P));
    int deg = mas->deg+1;
    result->c = (Q**)malloc(deg*sizeof(Q*));
    for(i=0;i<deg;i++)
    {
        result->c[i] = MUL_QQ_Q(mas->c[i],mult);
        printf("Nachal mnozhit'");
    }
    printf("Zakonchil");
    return result;
}
//P-4
P* MUL_Pxk_P(P* mas,int k){
    int degree = mas->deg+k;
    char unit[2] = {'1','\0'};
    P* result = (P*)calloc(1,sizeof(P));
    int i;
    Q *C;
    result->c = (Q**)calloc(degree,sizeof(Q*));
    result->deg = degree;
    Q* Z = rat_parsing(unit);
    C = rat_parsing(unit);
    for(i=0;i<k;i++)
        result->c[i] = MUL_QQ_Q(Z,C);
    for(i=0;i<mas->deg;i++)
        {
            result->c[i+k] = MUL_QQ_Q(mas->c[i],C);
        }
    clear_Q(C);
    return result;
}
//P-5
Q* LED_P_Q(P* mas){
    return mas->c[mas->deg-1];
}
//P-6
int DEG_P_N(P* mas){
    return mas->deg;
}
//P-12
P* DER_P_P(P* mas){
    int i;
    char buf[STDSIZE];
    Q* tmp,*C;
    P* result = (P*)calloc(1,sizeof(P));
    int degree = mas->deg-1;
    if(degree<0)
        degree = 0;
    result->c = (Q**)calloc(degree,sizeof(Q*));
    result->deg = degree;
    for(i=0;i<degree;i++){
        sprintf(buf,"%d",i+1);
        C = rat_parsing(buf);
        result->c[i] = MUL_QQ_Q(mas->c[i+1],C);
        free(C);
    }
    return result;
}

//P-9
P* DIV_PP_P(P *a, P *b)
{
	P *divAB, *var1,*var2,*tmp;
	Q *chastnoe;
    int k=0;
	int degA = DEG_P_N(a);
	int degB = DEG_P_N(b);
	int raznica = degA-degB;
	if (b->deg > a->deg)
		divAB = SUB_PP_P(a, a);
	else
	{
        divAB = (P*)malloc(sizeof(P));
        divAB->deg = a->deg;
        divAB->c = (Q**)malloc(sizeof(Q*)*divAB->deg); 
		while (b->deg <= a->deg)
		{
            printf("6 2\n");
            printf("Trying ");
            //output_rat(a->c[0]);
            printf(" ");
            //output_rat(b->c[0]);

			//chastnoe = DIV_QQ_Q(a->c[0], b->c[0]);
			printf("A");
            var1 = MUL_Pxk_P(b, raznica);
            printf("B");
			var2 = MUL_PQ_P(var1, chastnoe);
			printf("C");		
            tmp = SUB_PP_P(a, var2);
			printf("D");            
            a = tmp;
            degA = a->deg;
			raznica = degA-degB;
			divAB->c[k++] = chastnoe;
            clear_P(var1);
            clear_P(var2);
			clear_P(a);
		}
	}
	return divAB;
}

