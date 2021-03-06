/*#include <stdio.h>
#include <stdlib.h>
#include "natural.h"*/
//This module was made by Malov Pavel and Kuznetsov Artem of 8306 group
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

//Z-1 The absolute value of the number, the result is natural
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

//Z-2 Determines if the number is positive (2 - positive, 0- equals zero, 1 - negative)
int POZ_Z_D(Z* a)
{
	int f;
	if(a->sign == 0) f = 2;
	if(a->sign == 1) f = 1;
	if(NZER_N_B(a->num) == 1) f = 0;
	return f;
}
//Z-3 Multiplication of an integer by (-1)
void MUL_ZM_Z(Z* a)
{
	if(a->sign == 0) a->sign = 1;
	else if(a->sign == 1) a->sign = 0;
}
//Z-4 Convertation of a nutral into an integer
Z* TRANS_N_Z(N* n_num)
{
    Z* result = NULL;
    int stat,i;

    stat = 0;
    if((result = (Z*)malloc(sizeof(Z))) != 0)
    {
        result->num = (N*)malloc(sizeof(N));
        result->num->n = n_num->n;
        result->num->A = (int*)calloc(n_num->n,sizeof(int));
        for(i = 0; i < n_num->n; i++)
        	result->num->A[i] = n_num->A[i];
        result->sign = 0;
    }
    else
        puts("Memory allocation error!");
    return result;
}
//Z-5 Convertation of a non-negative integer into a natural
N* TRANS_Z_N(Z* z_num)
{
    N* result;
    int i;
    result = (N*)malloc(sizeof(N));
    result->A = (int*)malloc(z_num->num->n*sizeof(int));
    for(i = 0; i < z_num->num->n;i++)
        result->A[i] = z_num->num->A[i];
    result->n = z_num->num->n;
    if(z_num->sign == 1) printf("Your number was negative, but we did absolute natural value of it!\n");
    return result;
}
//Z-6 Addition of integers
Z* ADD_ZZ_Z(Z* first, Z* second)
{
    Z* result = NULL;
    Z *t = NULL;

    if(POZ_Z_D(first) == 0 && POZ_Z_D(second) != 0)
        result = second;
    if(POZ_Z_D(first) != 0 && POZ_Z_D(second) == 0)
        result = first;
    if(POZ_Z_D(first) == 0 && POZ_Z_D(second) == 0)
        result = first;
    if((POZ_Z_D(first) == 2 && POZ_Z_D(second) == 2) || (POZ_Z_D(first) == 1 && POZ_Z_D(second) == 1))
    {
        if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
        {
            result->sign = first->sign;
            result->num = ADD_NN_N(first->num, second->num);
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
//Z-7 substruction of integers
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
//Z-8 Multiplication of integers
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
    if((POZ_Z_D(first) == 1 && POZ_Z_D(second) == 2)||(POZ_Z_D(first) == 2 && POZ_Z_D(second) == 1))
    {
        if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
        {
            result->num = MUL_NN_N(second->num, first->num);
            result->sign = 1;
        }
        else
            puts("Memory allocation error!");
    }
    if((POZ_Z_D(first) == 1 && POZ_Z_D(second) == 1)||(POZ_Z_D(first) == 2 && POZ_Z_D(second) == 2))
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
//Z-9 The quotient from dividing a larger integer by a smaller or equal natural with the remainder (the divisor is non-zero)
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
//Z-10 The remainder of dividing a larger integer by a smaller or equal natural with the remainder (the divisor is non-zero)
Z* MOD_ZZ_Z(Z* first, Z* second)
{
    Z* result = NULL;
    Z* t = NULL;

    if(POZ_Z_D(first) != 0 && POZ_Z_D(second) != 0)
    {
        if(POZ_Z_D(first) == 2 && POZ_Z_D(second) == 2)
        {
            if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
            {
                if(COM_NN_D(first->num, second->num) == 2)
                {
                    result->num = MOD_NN_N(first->num, second->num);

                }
                if(COM_NN_D(first->num, second->num) < 2)
                {
                    result->num = MOD_NN_N(second->num, first->num);

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
                }
                if(COM_NN_D(first->num, second->num) < 2)
                {
                    result->num = MOD_NN_N(second->num, first->num);
                }
            }
            else
                puts("Memory allocation error!");
        }
        if(POZ_Z_D(first) == 1 && POZ_Z_D(second) == 2)
        {
            if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
            {
                result->num = MOD_NN_N(first->num, second->num);
                result->num = SUB_NN_N(second->num, result->num) ;
            }
            else
                puts("Memory allocation error!");
        }
        if(POZ_Z_D(first) == 2 && POZ_Z_D(second) == 1)
        {
            if(((result = (Z*)malloc(sizeof(Z)))!= NULL))
            {
                puts("Negative value.");
            }
            else
                puts("Memory allocation error!");
        }

    }
    else
        puts("Division by zero!");
    free(t);
    t = NULL;
    return result;
}
