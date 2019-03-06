struct integer
{
	int n;
	int *A;
};
typedef struct integer N;

struct zahlen
{
	int sign;
	N num;
};
typedef struct zahlen Z;

struct ratio
{
	Z m;
	N n;	
};
typedef struct ratio Q;

struct polinom
{
	int m;
	Q *c;
};
typedef struct polinom P;