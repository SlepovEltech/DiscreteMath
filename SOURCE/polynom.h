//This module was made by Andreev Vladimir and Saprykin Alexander
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
    printf("8-Multiplying of polynomoms\n9-The DIV a polynomial by a polynomial\n10-The MOD a polynomial by a polynomial\n11-GCF of polynoms\n");
    printf("12-Derivative of polynom\n");
    printf("Enter polynom in type: DEG COEF:\nExample:\n5 32/7\n3 -3/5\n0 9\nWhen we have 32/7x^5-3/5x^3+9");
    printf("\nYour answer: ");
    scanf("%d", &key);
    return key;
}
//P-1 Addition of polynomials
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

//P-2 Subtraction of Polynomials
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
	maxDeg++;
    result->c = (Q**)calloc(maxDeg,sizeof(Q*));
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
	int nonZero = 1;
	for (i = maxDeg-2; (i > 0) && nonZero; i--) {
		if (NZER_N_B(result->c[i]->m->num)) {
			clear_Q(result->c[i]);
			result->deg--;
		}
		else
			nonZero = 0;

	}

    return result;
}

//P-3 Multiplication of a polynomial by a rational number
P* MUL_PQ_P(P* mas,Q* mult){
    int i;
    Q *tmp;
    P* result = (P*)malloc(sizeof(P));
    int deg = mas->deg;
    result->c = (Q**)malloc(deg*sizeof(Q*));
    result->deg = deg;
    for(i=0;i<deg;i++)
    {
        result->c[i] = MUL_QQ_Q(mas->c[i],mult);
    }
    return result;
}
//P-4 Multiplication of a polynomial by x ^ k
P* MUL_Pxk_P(P* mas,int k){
    int degree = mas->deg+k;
    char unit[2] = {'1','\0'};
    char nul[2] = {'0','\0'};
    P* result = (P*)calloc(1,sizeof(P));
    int i;
    Q *C;
    result->c = (Q**)calloc(degree,sizeof(Q*));
    result->deg = degree;
    Q* Z = rat_parsing(nul);
    C = rat_parsing(unit);
    for(i=0;i<k;i++)
        result->c[i] = MUL_QQ_Q(Z,Z);
    for(i=0;i<mas->deg;i++)
        {
            result->c[i+k] = MUL_QQ_Q(mas->c[i],C);
        }
    clear_Q(C);
    return result;
}

//P-5 Highest coefficient of a polynomial
Q* LED_P_Q(P* mas){
    return mas->c[mas->deg-1];
}

//P-6 Degree of polynomial
int DEG_P_N(P* mas){
    return mas->deg-1;
}

//P-7 Derivation of the denominators of coefficients and GCD of numerators from the NOC polynomial
Q* FAC_P_Q(P* mas)
{
    int i;
    Q *ratata = NULL;
    if((ratata = (Q*)malloc(sizeof(Q))) != NULL)
    {
        ratata->m = mas->c[0]->m;
        ratata->n = mas->c[0]->n;
        for(i = 1; i < mas->deg; i++)
        {
            ratata->m = TRANS_N_Z((GCF_NN_N(ABS_Z_N(ratata->m), ABS_Z_N(mas->c[i]->m))));
            ratata->n = LCM_NN_N(ratata->n, mas->c[i]->n);
        }
    }
    else
        puts("Allocation error!");

    return ratata;
}

//P-8 Multiplication of polynomials
P* MUL_PP_P(P *a,P *b){
    int i,j,k;
    Q *res,*tmp1,*tmp2;
    char unit[2] = {'1','\0'};
    char nul[2] = {'0','\0'};
    P* result = (P*)calloc(1, sizeof(P));
    result->c = (Q**)calloc(a->deg + b->deg, sizeof(Q*));
    result->deg = a->deg + b->deg;
    for(i=0;i<result->deg;i++){
    res = rat_parsing(nul);
        for(j=0;j<a->deg;j++)
            for(k=0;k<b->deg;k++)
                if(i==(j+k))
                    {
                        tmp1 = MUL_QQ_Q(a->c[j],b->c[k]);
                        tmp2 = ADD_QQ_Q(tmp1,res);
                        clear_Q(res);
                        res = tmp2;
                        clear_Q(tmp1);
                    }
        result->c[i] = res;
    }
    return result;
}

//P-9 The quotient from the division of a polynomial by a polynomial in division with the remainder
P* DIV_PP_P(P *a, P *b)
{
	int i;
    int power;
    P *tmp1,*tmp2,*result;
    char nul[2] = {'0','\0'};
	if(a->deg<b->deg){
        result=SUB_PP_P(a,a);
    }
    else
    {
		if(b->deg==1){

			result = (P*)calloc(1, sizeof(P));
	    	result->c = (Q**)calloc(a->deg+1, sizeof(Q*));
	    	result->deg = a->deg;
	    	for(i=0;i<result->deg;i++)
	    		result->c[i] = DIV_QQ_Q(a->c[i],b->c[0]);
		}
		else
		{
	        result = (P*)calloc(1, sizeof(P));
		    result->c = (Q**)calloc(a->deg - b->deg+1, sizeof(Q*));
		    result->deg = a->deg - b->deg+1;
		    int maxDeg = a->deg - b->deg+1;
	        for(i=0;i<maxDeg;i++)
			    result->c[i] = NULL;
	        while (a->deg >= b->deg) {
	            Q* sep = DIV_QQ_Q(a->c[a->deg-1], b->c[b->deg-1]);
	            power = a->deg - b->deg;
	            result->c[power] = sep;
	            tmp1 = MUL_Pxk_P(b, power);
	            tmp2 = MUL_PQ_P(tmp1, sep);

	            a = SUB_PP_P(a, tmp2);
	            clear_P(tmp1);
	            clear_P(tmp2);
	        }

	        for(i=maxDeg;i>=0;i--)
	            if(result->c[i]==NULL)
	                result->c[i] = rat_parsing(nul);

	        int nonZero = 1;
	        for (i = maxDeg-2; (i > 0) && nonZero; i--) {
	            if (NZER_N_B(result->c[i]->m->num) && (result->c[i]==NULL)) {
	                clear_Q(result->c[i]);
	                result->deg--;
	            }
	            else
	                nonZero = 0;

	        }
	    }
	}
	return result;
}


//P-10 The remainder of dividing a polynomial by a polynomial when dividing with a remainder
P* MOD_PP_P(P *a,P *b){
    P* tmp1 = DIV_PP_P(a,b);
    P* tmp2 = MUL_PP_P(tmp1,b);
    P* result = SUB_PP_P(a,tmp2);
    clear_P(tmp1);
    clear_P(tmp2);
    return result;
}

//P-11 NOD of polynomials
/*
P* GCF_PP_P(P*a,P*b){

    P* tmp,*qu = (P*)malloc(sizeof(P));
    if(a->deg<b->deg)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    while(!(a->deg)||(POZ_Z_D(b->c[0]->m))){
        clear_P(qu);
        tmp = b;
        b = MOD_PP_P(a,b);
        qu = a;
        a = tmp;
    }
    return a;
}
*/

P* GCF_PP_P(P* a, P* b) { 
    P* result;
    int i;
    P* tmp;
	while ((a->deg>1) && (b->deg>1)){
        if (a->deg > b->deg)
			a = MOD_PP_P(a, b);
		else
			b = MOD_PP_P(b, a);


    }
   
   result = ADD_PP_P(a,b);
    return result;
}


//P-12 Polynomial derivative
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

// P-13


P* NMR_P_P(P* a) {
	P* derivative = DER_P_P(a);
    P* gcf = GCF_PP_P(a,derivative);
    P* result = DIV_PP_P(a,gcf);
    clear_P(gcf);
    clear_P(derivative);
    char buf[10];
    sprintf(buf,"%d",a->deg-1);
    Q* MULT = rat_parsing(buf);
    P* FinalResult = MUL_PQ_P(result,MULT);
    clear_P(result);
    return FinalResult;
}