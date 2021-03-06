//This module was made by Slepov Artem and Miskevich Milena of 8306 group
int rational()
{
	int key;
	printf("Choose operation with rational numbers: ");
	printf("\n0-To back to menu\n1-Fraction reduction\n2-Check into integer\n3-Converting integer into rational\n4-Converting rational into integer\n");
	printf("5-Addition of rationall\n6-Substract of integers\n");
	printf("7-Multiplication of rationals\n8-Delenie of rational\n");
	printf("Number enter as m/n when m - integer, n - natural\n");
	printf("Your answer: ");
	scanf("%d", &key);
	return key;
}
//Q-1 Fraction reduction
Q* RED_Q_Q(Q* h)
{
	Q* res;
	res = (Q*)malloc(sizeof(Q));
	res->m = (Z*)malloc(sizeof(Z));
	res->m->num = DIV_NN_N(h->m->num,GCF_NN_N(h->m->num,h->n));
	res->n = DIV_NN_N(h->n,GCF_NN_N(h->m->num,h->n));
	res->m->sign = h->m->sign;
	return res;
}
//Q-2 Check for integer, if a rational number is an integer, then “yes”, otherwise “no”
int INT_Q_B(Q* a)
{
	int f;
	a = RED_Q_Q(a);
	if((a->n->n == 1) && (a->n->A[0] == 1))
		f = 1;
	else
		f = 0;
	return f;
}
//Q-3 Convert integer into fractional
Q* TRANS_Z_Q(Z *a)
{	
	Q* res;
	int i;
	res = (Q*)malloc(sizeof(Q));
	res->m = (Z*)malloc(sizeof(Z));
	res->m->num = (N*)malloc(sizeof(N));
	res->m->num->A = (int*)malloc(a->num->n*sizeof(int));
	res->m->num->n = a->num->n;
	res->n = (N*)malloc(sizeof(N));
	res->n->n = 1;
	res->n->A = (int*)malloc(sizeof(int));
	res->n->A[0] = 1;
	for(i = 0; i < a->num->n;i++)
	{
		res->m->num->A[i] = a->num->A[i];
	}
	res->m->sign = a->sign;
	return res;
}
//Q-4 Conversion of fractional into integer (if the denominator is 1)
Z* TRANS_Q_Z(Q *a)
{
	Z* res = NULL;
	int i;
	res = (Z*)malloc(sizeof(Z));
	res->num = (N*)malloc(sizeof(N));
	res->num->A = (int*)malloc(a->m->num->n*sizeof(int));
	res->num->n = a->m->num->n;
	res->sign = a->m->sign;
	for(i = 0; i < a->m->num->n; i++)
		res->num->A[i] = a->m->num->A[i];

	return res;
}
//Q-5 Addition of fractions
Q* ADD_QQ_Q(Q* a, Q*b)
{
	Q* res;
	res = (Q*)malloc(sizeof(Q));
	res->m = ADD_ZZ_Z(MUL_ZZ_Z(a->m,TRANS_N_Z(b->n)),MUL_ZZ_Z(b->m,TRANS_N_Z(a->n)));
	res->n = MUL_NN_N(a->n,b->n);
	res = RED_Q_Q(res);
	return res;
}
//Q-6 Subtraction of fractions
Q* SUB_QQ_Q(Q* a, Q*b)
{
	Q* res;
	res = (Q*)malloc(sizeof(Q));
	res->m = SUB_ZZ_Z(MUL_ZZ_Z(a->m,TRANS_N_Z(b->n)),MUL_ZZ_Z(b->m,TRANS_N_Z(a->n)));
	res->n = MUL_NN_N(a->n,b->n);
	res = RED_Q_Q(res);
	return res;
}
//Q-7 Multiplication of fractions
Q* MUL_QQ_Q(Q* a, Q* b)
{
	Q* res;
	Q* finalRes;
	res = (Q*)malloc(sizeof(Q));
	res->m = MUL_ZZ_Z(a->m,b->m);
	res->n = MUL_NN_N(a->n,b->n);
	if( ((POZ_Z_D(a->m) == 1) && (POZ_Z_D(b->m) == 1)) || ((POZ_Z_D(a->m) == 0) && (POZ_Z_D(b->m) == 0)) )
		res->m->sign = 0;
	if(POZ_Z_D(a->m) != POZ_Z_D(b->m))
		res->m->sign = 1;
	res = RED_Q_Q(res);
	return res;
}

//Q-8 Fraction division (divider is non-zero)
Q* DIV_QQ_Q(Q* a, Q*b)
{
	Q* res;
	res = (Q*)malloc(sizeof(Q));
	res->m = MUL_ZZ_Z(a->m, TRANS_N_Z(b->n));
	res->n = TRANS_Z_N(MUL_ZZ_Z(TRANS_N_Z(a->n), b->m));
	res = RED_Q_Q(res);
	if( ((POZ_Z_D(a->m) == 1) && (POZ_Z_D(b->m) == 1)) || ((POZ_Z_D(a->m) == 0) && (POZ_Z_D(b->m) == 0)) )
		res->m->sign = 0;
	if(POZ_Z_D(a->m) != POZ_Z_D(b->m))
		res->m->sign = 1;
	return res;
}
