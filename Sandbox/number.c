#include"Hmath.h"

int cFloor(double val){
    return (int)(floor(val));
}

Q* initRat(int type){
// Создает рац. число
// Возвращает указатель
// type -  тип числа
//      0 - дробь
//      1 - целое число
int i;
srand(time(NULL));
Q* rat = NULL;
rat = (Q*)malloc(sizeof(Q));
rat->m.sign =  cFloor(rand())%2; // Генерируем знак
rat->m.num.n = cFloor(rand()) % 3 + 1; // Количество цифр в числе
for(i=0;i<rat->m.num.n;i++)
    rat->m.num.A[i] = cFloor(rand())%10+1;
if(type == 1)
    rat->n.n = 0;
else
{
    rat->n.n = cFloor(rand())%5+1;
    for(i=0;i<rat->n.n;i++)
        rat->n.A[i] = cFloor(rand())%10+1;
}
return rat;
}

void printRat(Q* rat){
// Выводит это число на экран
int i;
printf("Info: sign:%d sizeM:%d sizeN:%d\n",rat->m.sign,rat->m.num.n,rat->n.n);
printf("%c",(rat->m.sign)?'-':'+');
for(i=0;i<rat->m.num.n;i++)
    printf("%d",rat->m.num.A[i]);
if(rat->n.n)
    printf("/");
for(i=0;i<rat->n.n;i++)
    printf("%d",rat->n.A[i]);
printf("\n");
}

void decompRat(Q* rat){
    // Чистит указатель
    free(rat);
}

int main(){
    Q* tmp = initRat(1);
    printRat(tmp);
    decompRat(tmp);
}