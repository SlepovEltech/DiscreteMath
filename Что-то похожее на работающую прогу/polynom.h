#pragma once
#include "struct.h"
#include <math.h>
#include <stdlib.h>

P* ADD_PP_P(P* first,P* second){
    int i;
    int maxDeg = (first->deg>second->deg)?first->deg:second->deg;
    P* result = (P*)calloc(maxDeg,sizeof(Q*));
    for(i=0;i<maxDeg;i++){
        if(i<first->deg)
            result[i] = ADD_QQ_Q(result[i],first[i]);

        if(i<second->deg)
            result[i] = ADD_QQ_Q(result[i],second[i]);
    }
    return result;
}