#pragma once
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

P* polyGet(){
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

void polyPrint(P *mas){
    // Выводит многочлен в виде Ax^n+...+Z
    int i;
    for(i=mas->deg-1;i>=0;i--){
        printf("%c",(mas->deg==1)?'\0':'+');
        output_rat(&mas->c[i]);
        printf("x^%d",i);
        }
        printf("\n");
}

void polyFree(P *mas){
    // Чистит всё, что связанно с многочленами
    int i;
    for(i=0;i<mas->deg;i++)
        clear_Q(&mas->c[i]);
    free(mas);
}

P* ADD_PP_P(P* first,P* second){
    int i;
    int maxDeg = (first->deg>second->deg)?first->deg:second->deg;
    P* result = (P*)malloc(sizeof(P));
    result->deg = maxDeg;
    result->c = (Q*)calloc(maxDeg,sizeof(Q));
    for(i=0;i<maxDeg;i++){
        if((i<first->deg) && (i<second->deg)){
            
            ;
        }
    }
    return result;
}