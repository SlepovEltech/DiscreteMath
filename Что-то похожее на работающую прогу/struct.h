struct natural
{
	int n;
	int *A;
};
typedef struct natural N;

struct zahlen
{
	int sign;
	N *num;
};
typedef struct zahlen Z;

struct ratio
{
	Z *m;
	N *n;	
};
typedef struct ratio Q;

struct polinom
{
	int deg;
	Q *c;
};
typedef struct polinom P;

//void output(N *q);