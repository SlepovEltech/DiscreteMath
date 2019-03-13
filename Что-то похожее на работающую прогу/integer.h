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