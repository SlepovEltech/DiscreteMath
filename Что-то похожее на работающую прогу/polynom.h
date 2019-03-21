#pragma once
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void clear_P(P*);
P* polynom_parsing();
void output_pol(P*);
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
    Q *tmp;
    P* result = (P*)calloc(1,sizeof(P));
    int deg = mas->deg+1;
    result->c = (Q**)calloc(deg,sizeof(Q*));
    for(i=0;i<deg;i++)
    {
        result->c[i] = MUL_QQ_Q(mas->c[i],mult);
    }
    return result;
}

Q* LED_P_Q(P* mas){
    return mas->c[mas->deg-1];
}

int DEG_P_N(P* mas){
    return mas->deg;
}
//P-4
P* MUL_Pxk_P(P* mas,int k){
    int degree = mas->deg+k;
    P* result = (P*)calloc(1,sizeof(P));
    int i;
    Q *C;
    result->c = (Q**)calloc(degree,sizeof(Q*));
    result->deg = degree;
    Q* Z = rat_parsing("0");
    C = rat_parsing("1");
    for(i=0;i<k;i++)
        result->c[i] = MUL_QQ_Q(Z,C);
    for(i=0;i<mas->deg;i++)
        {
            result->c[i+k] = MUL_QQ_Q(mas->c[i],C);
        }
    clear_Q(C);
    return result;
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