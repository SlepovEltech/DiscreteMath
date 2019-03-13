int rational()
{
	int key;
	printf("Choose operation with rational numbers: ");
	printf("\n1-Fraction reduction\n2-Check into integer\n3-Converting integer into rational\n4-Converting rational into integer\n");
	printf("5-Addition of rationall\n6-Addition of integers\n");
	printf("7-Subtract of rationals\n8-Multiplication of rational\n");
	printf("Your answer: ");
	scanf("%d", &key);
	return key;
}
Q* RED_Q_Q(Q* h)
{
	Q* res;
	res = (Q*)malloc(sizeof(Q));
	res->m = (Z*)malloc(sizeof(Z));
	res->m->num = DIV_NN_N(h->m->num,GCF_NN_N(h->m->num,h->n));
	res->n = DIV_NN_N(h->n,GCF_NN_N(h->m->num,h->n));
	return res;
}