#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZEOFPOLYNOM 500
void add_polynom(char *src){
    int vals[SIZEOFPOLYNOM] = {0};
    int power;
    char tmp[10] = {0};
    int i=0,k,valueLength,value;
    while(src[++i]!=' ');
    while(src[i++]!='\0'){
        if(isalpha(src[i])){
            power = 0;
            valueLength = 0;
            value = 0;


            if(src[i+1]=='^')
                for(k=i+2;isdigit(src[k]);k++)
                    power=power*10+(src[k]-'0');
            else
                power = 1;
            
            for(k=i-1;(k>0) && (isdigit(src[k]));k--)
                valueLength++;
            for(k=i-valueLength;k<=i-1;k++)
                value = value*10+(src[k]-'0');
            if(valueLength==0){
                vals[power] = -1;
                if(src[i-1]=='-')
                    vals[power] = -1;
            }
                
            if(src[i-valueLength-1] == '-')
                value*=-1;
            vals[power] += value;
        }
    }
    printf(">>");
    for(i=SIZEOFPOLYNOM-1;i>=0;i--)
        if(vals[i])
            printf("%c%dx^%d",(vals[i]>0)?'+':(int)NULL,vals[i],i);
    printf("\n");
}



int main(){
    char buf[1000];
    fgets(buf,1000,stdin);
    int len = strlen(buf);
    buf[len-1] = '\0';
    if(!strncmp(buf,"add_pol",7))
        add_polynom(buf);
    return 0;
}
