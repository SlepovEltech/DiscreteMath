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
    result->deg = maxDeg;
    result->c = (Q*)calloc(maxDeg+1,sizeof(Q));
    for(i=0;i<maxDeg;i++){
        if((i<first->deg)&&(i<second->deg)){
            printf("A\n");
            tmp = ADD_QQ_Q(&(first->c[i]),&(second->c[i]));
            result->c[i] = *tmp;
            free(tmp);
        }
        else
            if((i<first->deg)){
            printf("B\n");
            tmp = ADD_QQ_Q(&(first->c[i]),&(result->c[i]));
            result->c[i] = *tmp;
            free(tmp);
        }
                    
            else
                if((i<second->deg)){
            printf("C\n");
            tmp = ADD_QQ_Q(&(second->c[i]),&(result->c[i]));
            result->c[i] = *tmp;
            free(tmp);
        }
        printf("%d\n",i);
    }
    return result;
}