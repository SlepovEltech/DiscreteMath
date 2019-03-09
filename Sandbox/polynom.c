#include"Hmath.h"

P* initPolynom(int deg){
// Создает многочлен
// На вход: степень, на выходе указатель на многочлен с куче
//
// PAIN
int i;
P* output = (P*)malloc(sizeof(P));
output->c = (Q*)malloc(deg*sizeof(Q));
output->deg = deg;
for(i=0;i<deg;i++){
    output->c->m.sign = 1;
    output->c->m.num.A[0] = 2;
    output->c->m.num.n = 1;
    output->c->n.n = 1;
    output->c->n.A[0] = 1;
}
}

decompPolynom(P* polynom){
    free(polynom->c);
    free(polynom);
}


printPolynom(P* polynom){
    
    int i;
    float coef;
    for(i=0;i<polynom->deg;i++)
        {
            coef = polynom->
            printf("%fx^i",())
        }
}

int main(){

    return 0;
}
