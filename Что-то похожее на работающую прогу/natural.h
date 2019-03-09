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

/*N-4: Addition of natural numbers*/
N* ADD_NN_N (N *a, N *b)
{
    int i,s,w,st;
    N *S=NULL;
    s=0;
    if (COM_NN_D(a,b)==2)
    {
        w=a->n;
        st=b->n;
    }
    else
    {
        w=b->n;
        st=a->n;
    }
    S=(N*)malloc(sizeof(N));
    if(S)
    {
        S->A = (int*)calloc(w+1,sizeof(int));
        S->n=w+1;
        if (S->A)
        {
            if (COM_NN_D(a,b)==2)
            {
                for (i=0;i<w;i++)
                {
                    if (i<st)
                    {
                        S->A[i]=(a->A[i]+b->A[i]+s)%10;
                        s=(a->A[i]+b->A[i]+s)/10;
                    }
                    else
                    {
                        S->A[i]=(a->A[i]+s)%10;
                        s=(a->A[i]+s)/10;
                    }
                }
            }
            else
            {
                for (i=0;i<w;i++)
                {
                    if (i<st)
                    {
                        S->A[i]=(a->A[i]+b->A[i]+s)%10;
                        s=(a->A[i]+b->A[i]+s)/10;
                    }
                    else
                    {
                        S->A[i]=(b->A[i]+s)%10;
                        s=(b->A[i]+s)/10;
                    }
                }
            }
            if (s>0)
            {
                S->A[i]=s;
                S->n=w+1;

            }
            else S->n=w;
        }
    }
    return S;
}

/*N-5: Subtracting from the first natural number the second which is less or equal */
N* SUB_NN_N (N *a, N *b)
{
    N *S=NULL;
    int i,t;
    t=0;
    S=(N*)malloc(sizeof(N));
    //S->n=a->n;
    if(S)
    {
        S->A = (int*)calloc(a->n,sizeof(int));
        if (S->A)
        {
            if(COM_NN_D(a, b)==2)
            {
                for (i=0; i<a->n; i++)
                {
                    if(i<b->n)
                    {
                        if (a->A[i]-t>=b->A[i])
                        {
                            S->A[i]=(a->A[i]-b->A[i]-t);
                            t=0;
                        }
                        else
                        {
                            S->A[i]=(a->A[i]+10-b->A[i]-t);
                            t=1;
                        }
                    }
                    else
                    {
                        if (a->A[i]>=t)
                        {
                            S->A[i]=(a->A[i]-t);
                            t=0;
                        }
                        else
                        {
                            S->A[i]=(a->A[i]+10-t);
                            t=1;
                        }
                    }
                }
            }

        }
    }
    return S;
}

/*N-6: multiplies number by digit (но это не точно)*/
N* MUL_ND_N (N *a, int num)
{
    N *S=NULL;
    int i,t;
    t=0;
    S=(N*)malloc(sizeof(N));
    if(S)
    {
        S->A = (int*)calloc(a->n,sizeof(int));
        if (S->A)
        {
            for (i=0; i<a->n-1; i++)
            {
                S->A[i]=(a->A[i]*num+t)%10;
                t=(a->A[i]*num)/10;
            }
            if (t>0) S->A[a->n]=t;
        }
    }
    return S;
}

/*N-7: multiplies number by 10^k (но это не точно)*/
N* MUL_Nk_N (N *a, int k)
{
    N *S=NULL;
    int i;
    S=(N*)malloc(sizeof(N));
    if(S)
    {
        S->A = (int*)calloc(a->n+k,sizeof(int));
        if (S->A)
        {
            for (i=a->n-1; i>=0; i--)
            {
                S->A[i+k]=a->A[i];
            }
            for (i=0; i<k; i++)
            {
                S->A[i]=0;
            }
        }
    }
    return S;
}

/*N8: Function to multiply two natural numbers*/
N *MUL_NN_N (N *a, N *b)
{
    int k;
    N *res=NULL;
    res=(N*)malloc(sizeof(N));
    if (res) for (k=0;k<b->n;k++) res=ADD_NN_N(res,MUL_Nk_N(MUL_ND_N(a,b->A[k]),k));
    return res;
}

/*N-9: Subtracting natural number multiplied by a digit
from anther natural number for cases with non-negative results*/
N *SUB_NDN_N (N *a, int d, N *b)
{
    N *res=NULL;
    res=(N*)malloc(sizeof(N));
    if (res)
    {
        if ((COM_NN_D(a,MUL_ND_N(b,d)))!=1) res=SUB_NN_N(a,MUL_ND_N(b,d));
        else
        {
            free(res);
            res=NULL;
        };
    }
    return res;
}

 /*N-10: Calculating first digit of division of a bigger natural number by a smaller natural
 number multiplied by 10^k where k is number of digit's position (starting with zero)*/
int DIV_NN_Dk (N *a, N *b)
{
    int d=-1;
    if ((COM_NN_D(a,b))!=1)
    {
        b=MUL_Nk_N(b,(a->n-b->n));
        if ((COM_NN_D(a,b))!=1) d=a->A[a->n]/b->A[b->n];
    }
    return d;
}
