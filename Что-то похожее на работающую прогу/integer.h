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