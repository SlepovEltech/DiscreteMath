#pragma once
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void clear_P(P*);
P* polynom_parsing();
void output_pol(P*);
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
    result->c = (Q*)calloc(maxDeg+1,sizeof(Q));
    for(i=0;i<maxDeg;i++){
        if((i<first->deg)&&(i<second->deg)){
            tmp = ADD_QQ_Q(&(first->c[i]),&(second->c[i]));
            result->c[i] = *tmp;
            free(tmp);
        }
        else{
                if((i<first->deg))
                {
                    tmp = ADD_QQ_Q(&(first->c[i]),&zero);
                    result->c[i] = *tmp;
                    free(tmp);
                }                
                else
                    if((i<second->deg))
                    {
                        tmp = ADD_QQ_Q(&(second->c[i]),&zero);
                        result->c[i] = *tmp;
                        free(tmp);
                    }
        }
    }
    return result;
}


P* SUB_PP_P(P* first,P* second){
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
    result->c = (Q*)calloc(maxDeg+1,sizeof(Q));
    for(i=0;i<maxDeg;i++){
        if((i<first->deg)&&(i<second->deg)){
            tmp = SUB_QQ_Q(&(first->c[i]),&(second->c[i]));
            result->c[i] = *tmp;
            free(tmp);
        }
        else{
                if((i<first->deg))
                {
                    tmp = SUB_QQ_Q(&(first->c[i]),&zero);
                    result->c[i] = *tmp;
                    free(tmp);
                }                
                else
                    if((i<second->deg))
                    {
                        tmp = SUB_QQ_Q(&zero,&(second->c[i]));
                        result->c[i] = *tmp;
                        free(tmp);
                    }
        }
    }
    return result;
}

P* MUL_PQ_P(P* mas,Q* mult){
    int i;
    Q *tmp;
    P* result = (P*)calloc(1,sizeof(P));
    int deg = mas->deg+1;
    result->c = (Q*)calloc(deg,sizeof(Q));
    for(i=0;i<deg;i++)
    {
        tmp = MUL_QQ_Q(&(mas->c[i]),mult);
        result->c = tmp;
        free(tmp);
    }
    return result;
}

Q* LED_P_Q(P* mas){
    return &mas->c[mas->deg-1];
}

int DEG_P_N(P* mas){
    return mas->deg;
}

//MUL_Pxk_P(Q* coef,d)
P* DER_P_P(P* mas){
    int i;
    char buf[STDSIZE];
    Q* tmp,*C;
    P* result = (P*)calloc(1,sizeof(P));
    int degree = mas->deg-1;
    if(degree<0)
        degree = 0;
    result->c = (Q*)calloc(degree,sizeof(Q));
    result->deg = degree;
    for(i=0;i<degree;i++){
        sprintf(buf,"%d",i);
        C = rat_parsing(buf);
        tmp = MUL_QQ_Q(&mas->c[i+1],C);
        result->c[i] = *tmp;
        free(tmp);
        free(C);
    }
    return result;
}