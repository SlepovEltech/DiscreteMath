/*#include <stdio.h>
#include <stdlib.h>*/

//Menu list with options
int integer()
{
	int key;
	printf("Choose operation with integer numbers: ");
	printf("\n1-The absolute value of the number\n2-The positivity of the number\n3-Multiplying by (-1)\n4-Converting natural into integer\n");
	printf("5-Converting integer into natural\n6-Addition of integers\n");
	printf("7-Subtract integers\n8-Multiplication of integer numbers\n");
	printf("9-The DIV of integer numbers\n10-The MOD of integer numbers\n");
	printf("Your answer: ");
	scanf("%d", &key);
	return key;
}
//Z-1
N* ABS_Z_N(Z* a)
{
	N *b = NULL;
	int i;
	b = (N*)malloc(sizeof(N));
	if(b)
	{
		b->n = a->num->n;
		b->A = (int*)malloc(a->num->n*sizeof(int));
		for(i = 0; i < a->num->n; i++)
			b->A[i] = a->num->A[i];
	}
	return b;
}

//Z-2
int POZ_Z_D(Z* a)
{
	int f;
	if(a->sign == 0) f = 2;
	if(a->sign == 1) f = 1;
	if(NZER_N_B(a->num) == 1) f = 0;
	return f;
}
//Z-3
void MUL_ZM_Z(Z* a)
{
	if(a->sign == 0) a->sign = 1;
	if(a->sign == 1) a->sign = 0;
}
//Z-4
Z* TRANS_N_Z(N* n_num)
{
    Z* result = NULL;
    int stat;

    stat = 0;
    if((result = (Z*)malloc(sizeof(Z))) != 0)
    {
        result->num = n_num;
        result->sign = 0;
    }
    else
        puts("Memory allocation error!");
    return result;
}
//Z-5
N* TRANS_Z_N(Z* z_num)
{
    N* result;

    if(z_num->sign == 0)
        result = z_num->num;
    else
        puts("It's negative number");

    return result;
}
//Z-6
Z* ADD_ZZ_Z(Z* first, Z* second)
{
    Z* result = NULL;
    Z *t = NULL;

    if(POZ_Z_D(first) == 0 && POZ_Z_D(second) != 0)
        result = second;
    if(POZ_Z_D(first) != 0 && POZ_Z_D(second) == 0)
        result = first;
    if((POZ_Z_D(first) == 2 && POZ_Z_D(second) == 2) || (POZ_Z_D(first) == 1 && POZ_Z_D(second) == 1))
    {
        if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
        {
            result->sign = first->sign;
            result->num = ADD_NN_N(first->num, second->num);
            /*int i;
            for(i = result->num->n-1; i >= 0; i--)
                printf("%d", result->num->A[i]);   */     
        }
        else
            puts("Memory allocation error!");
    }
    if(POZ_Z_D(first) == 2 && POZ_Z_D(second) == 1)
    {
        t = first;
        first = second;
        second = t;

    }
    if(POZ_Z_D(first) == 1 && POZ_Z_D(second) == 2)
    {
        if(COM_NN_D(first->num, second->num) == 2)
        {
            if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
            {
                result->num = SUB_NN_N(first->num, second->num);
                result->sign = 1;
            }
            else
                puts("Memory allocation error!");

        }
        if(COM_NN_D(first->num, second->num) == 1)
        {
            if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
            {
                result->num = SUB_NN_N(second->num, first->num);
                result->sign = 0;
            }
            else
                puts("Memory allocation error!");
        }
        if(COM_NN_D(first->num, second->num) == 0)
        {
            if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
            {
                result->num = SUB_NN_N(second->num, first->num);
                result->sign = 0;
            }
            else
                puts("Memory allocation error!");

        }
    }
    free(t);
    t = NULL;
    return result;
}
//Z-7
Z* SUB_ZZ_Z(Z* first, Z* second)
{
    Z* result = NULL;

    if(second->sign == 1)
        second->sign = 0;
    else
        second->sign = 1;
    result = ADD_ZZ_Z(first, second);
    return result;
}
//Z-8
Z* MUL_ZZ_Z(Z* first, Z* second)
{
    Z* result = NULL;

    if(POZ_Z_D(first) == 0 || POZ_Z_D(second) == 0)
    {
        if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
        {
            result->num = MUL_NN_N(second->num, first->num);
            result->sign = 0;
        }
        else
            puts("Memory allocation error!");
    }
    if((POZ_Z_D(first) == 1 & POZ_Z_D(second) == 2)||(POZ_Z_D(first) == 2 & POZ_Z_D(second) == 1))
    {
        if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
        {
            result->num = MUL_NN_N(second->num, first->num);
            result->sign = 1;
        }
        else
            puts("Memory allocation error!");
    }
    if((POZ_Z_D(first) == 1 & POZ_Z_D(second) == 1)||(POZ_Z_D(first) == 2 & POZ_Z_D(second) == 2))
    {
        if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
        {
            result->num = MUL_NN_N(second->num, first->num);
            result->sign = 0;
        }
        else
            puts("Memory allocation error!");
    }
    return result;
}
//Z-9
Z* DIV_ZZ_Z(Z* first, Z* second)
{
    Z* result = NULL;
    Z* t = NULL;

    if((POZ_Z_D(first) == 2 && POZ_Z_D(second) == 2)||(POZ_Z_D(first) == 1 && POZ_Z_D(second) == 1))
    {
        if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
        {
            if(COM_NN_D(first->num, second->num) == 2)
            {
                result->num = DIV_NN_N(first->num, second->num);
                result->sign = 0;
            }
            if(COM_NN_D(first->num, second->num) < 2)
            {
                result->num = DIV_NN_N(second->num, first->num);
                result->sign = 0;
            }
        }
        else
            puts("Memory allocation error!");
    }
    if((POZ_Z_D(first) == 1 && POZ_Z_D(second) == 2)||(POZ_Z_D(first) == 2 && POZ_Z_D(second) == 1))
    {
        if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
        {
            if(COM_NN_D(first->num, second->num) == 2)
            {
                result->num = DIV_NN_N(first->num, second->num);
                result->sign = 1;
            }
            if(COM_NN_D(first->num, second->num) < 2)
            {
                result->num = DIV_NN_N(second->num, first->num);
                result->sign = 1;
            }
        }
        else
            puts("Memory allocation error!");
    }
    free(t);
    t = NULL;
    return result;
}
//Z-10
Z* MOD_ZZ_Z(Z* first, Z* second)
{
    Z* result = NULL;
    Z* t = NULL;

    if(POZ_Z_D(first) == 2 && POZ_Z_D(second) == 2)
    {
        if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
        {
            if(COM_NN_D(first->num, second->num) == 2)
            {
                result->num = MOD_NN_N(first->num, second->num);
                result->sign = 0;
            }
            if(COM_NN_D(first->num, second->num) < 2)
            {
                result->num = MOD_NN_N(second->num, first->num);
                result->sign = 0;
            }
        }
        else
            puts("Memory allocation error!");
    }
    if(POZ_Z_D(first) == 1 && POZ_Z_D(second) == 1)
    {
        if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
        {
            if(COM_NN_D(first->num, second->num) == 2)
            {
                result->num = MOD_NN_N(first->num, second->num);
                result->sign = 1;
            }
            if(COM_NN_D(first->num, second->num) < 2)
            {
                result->num = MOD_NN_N(second->num, first->num);
                result->sign = 1;
            }
        }
        else
            puts("Memory allocation error!");
    }
    if((POZ_Z_D(first) == 1 && POZ_Z_D(second) == 2)||(POZ_Z_D(first) == 2 && POZ_Z_D(second) == 1))
    {
        if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
        {
            if(COM_NN_D(first->num, second->num) == 2)
            {
                result->num = MOD_NN_N(first->num, second->num);
                result->sign = 1;
            }
            if(COM_NN_D(first->num, second->num) == 1)
            {
                result->num = MOD_NN_N(second->num, first->num);
                result->sign = 1;
            }
            if(COM_NN_D(first->num, second->num) == 0)
            {
                result->num = MOD_NN_N(second->num, first->num);
                result->sign = 0;
            }
        }
        else
            puts("Memory allocation error!");
    }
    free(t);
    t = NULL;
    return result;
}
