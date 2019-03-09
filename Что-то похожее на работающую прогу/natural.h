/*N-1: comparisson of two natural numbers 
if the first one is bigger than the second one-2, if they are equal-0, otherwise-1*/
int COM_NN_D (N *a, N *b) 
{
    int i, res,t, count;
    t=1;
    count=0;
    if (a->n>b->n) res=2;
    if (a->n<b->n) res=1;
    if (a->n==b->n)
    {
        for (i = a->n-1; i>=0 && t!=0; i--)
        {
            if (a->A[i]>b->A[i])
            {
                res=2;
                t=0;
            }
            else if (a->A[i]<b->A[i])
            {
                res=1;
                t=0;
            }
            else count++;
        }
    if (count==a->n) res=0;
    }
    return res;
}

/*N-2: checks if the number equals zero   */
int NZER_N_B (N *a)
{
    int i, res, count;
    count=0;
    res=0;
    for (i=a->n-1; i>=0; i--)
        {
            if (a->A[i]==0) count++;
        }
    if (count==a->n) res=1; //1-yes 0-no
    return res;
}

/*N-3: adds 1 to the natural number*/
void ADD_1N_N (N *a)
{
    int i,t;
    i=0;
    t=1;
    a->A[a->n]=0;
    while (t!=0)
    {
        if (a->A[i]!=9)
        {
            a->A[i]++;
            t=0;
        }
        else
        {
            a->A[i]=0;
            i++;
        }
    }
    if(a->A[a->n] == 0)
        a->A = (int*)realloc(a->A, a->n);
    else
        a->n = a->n + 1;
}

/*N-6: multiplies number by digit (но это не точно)*/
void MUL_ND_N (N *a, int num)
{
    N *S;
    int i,t;
    t=0;
    for (i=0; i<a->n-1; i++)
    {
        S->A[i]=(a->A[i]*num+t)%10;
        t=(a->A[i]*num)/10;
    }
    if (t>0) S->A[a->n]=t;
}