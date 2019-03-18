//Menu list with options
int natural()
{
	int key;
	printf("Choose operation with natural numbers: ");
	printf("\n0-To back to menu\n1-Comparison of natural numbers\n2-Check if zero\n3-Appendix 1\n4-Addition of natural numbers\n");
	printf("5-Subtraction(the first - the biggest, the second -smaller or equal)\n6-Multiplying a natural number by a digit\n");
	printf("7-Multiplying a natural number by 10 in deg\n8-Multiplication of natural numbers\n");
	printf("9-Subtraction from other natural, multiplied by a digit\n10-Calculation of the first digit of the division of greater natural by less, multiplied by 10^k\n");
	printf("11-The DIV of the numbers\n12-The MOD of the numbers\n13-NOD of the numbers\n14-NOK of the numbers\n\n");
	printf("Your answer: ");
	scanf("%d", &key);
	return key;
}
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
    if(S)
    {
        if(COM_NN_D(a, b)==2)
        {
            S->A = (int*)calloc(a->n,sizeof(int));
            if (S->A)
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
                S->n=a->n;
                while ( S->A[S->n-1]==0)
                {
                    S->n-=1;
                }
            }
        }
        else if (COM_NN_D(a, b)==0)
        {
            S->n=1;
            S->A=(int*)calloc(1,sizeof(int));
        }
            else S=NULL;
    }
    return S;
}

/*N-6: multiplies number by digit*/
N* MUL_ND_N (N *a, int num)
{
    N *S=NULL;
    int i,t;
    t=0;
    S=(N*)malloc(sizeof(N));
    if(S)
    {
        if(num != 0)
        {
            S->A = (int*)calloc(a->n+1,sizeof(int));
            if (S->A)
            {   
                for (i=0; i<a->n; i++)
                {
                    S->A[i]=(a->A[i]*num+t)%10;
                    t=(a->A[i]*num+t)/10;
                }
                if (t>0)
                {
                    S->A[a->n]=t;
                    S->n=a->n+1;
                }
                else
                {
                    S->n=a->n;
                }
            }
        }
        else
        {
            S->n = 1;
            S->A = (int*)calloc(1,sizeof(int));
        }
    }
    return S;
}

/*N-7: multiplies number by 10^k*/
N* MUL_Nk_N (N *a, int k)
{
    N *S=NULL;
    int i;
    S=(N*)malloc(sizeof(N));
    if(S)
    {
        if ((a->n==1)&&(a->A[0]==0))
        {
            S->n=1;
            S->A=(int*)calloc(1,sizeof(int));
        }
        else
        {
            S->A = (int*)calloc(a->n+k,sizeof(int));
            if (S->A)
            {
                S->n= a->n+k;
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
    }
    return S;
}

/*N8: Function to multiply two natural numbers*/
N *MUL_NN_N (N *a, N *b)
{
    int i;
    N *res=NULL;
    res=(N*)malloc(sizeof(N));
    if (res)
    {
        res->A=(int*)calloc(((a->n)+(b->n)),sizeof(int));
        if (res->A)
        {
            res->n=((a->n)+(b->n));
            for (i=0;i<(b->n);i++)
                res=ADD_NN_N(res,MUL_Nk_N(MUL_ND_N(a,b->A[i]),i));
        }
        if (res->A[(a->n)+(b->n)-1]==0)
            res->n--;
    }
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
        if ((COM_NN_D(a,MUL_ND_N(b,d)))!=1)
        {
            res=SUB_NN_N(a,MUL_ND_N(b,d));
        }
        else
        {
            free(res);
            res=NULL;
        };
    }
    return res;
}

 /*N-10: Calculating first digit of division of a bigger natural number by a smaller natural
 number, multiplied by 10^k, where k is number of digit's position (starting with zero)*/
int *DIV_NN_Dk (N *a, N *b)
{
    int *d=NULL;
    if (COM_NN_D(a,b)==1){}
    else
    {
        d=(int*)calloc(2,sizeof(int));
        if(d)
        {
            while ((COM_NN_D(a,b))!=1) {d[1]++;b=MUL_Nk_N(b,1);}
            a=MUL_Nk_N(a,1);
            if (a->n>b->n) d[0]=(10*a->A[a->n-1]+a->A[a->n-2])/b->A[b->n-1];
            else d[0]=a->A[a->n-1]/b->A[b->n-1];
            while (COM_NN_D(a,MUL_ND_N(b,d[0]))==1) d[0]--;
        }
    }
    d[1]--;
    return d;
}

/*N-11: Quotient of division with remainder of a bigger natural number by a smaller or equal natural number (divider is nonzero)*/
N *DIV_NN_N (N *a, N *b)
{
    int i,j,k;
    j=0;
    N *res=NULL, *tmp1=NULL, *tmp2=NULL;
    res=(N*)malloc(sizeof(N));
    tmp1=(N*)malloc(sizeof(N));
    tmp2=(N*)malloc(sizeof(N));
    if (res&&tmp1&&tmp2)
    {
        res->A=(int*)calloc(a->n-b->n+1,sizeof(int));
        tmp1->A=(int*)calloc(b->n,sizeof(int));
        tmp2->A=(int*)calloc(1,sizeof(int));
        if (res->A&&tmp1->A&&tmp2->A)
        {
            tmp1->n=b->n;
            for (i=0;i<b->n;i++) tmp1->A[i]=a->A[a->n-b->n+i];
            if (COM_NN_D(tmp1,b)==1) res->n=a->n-b->n;
            else res->n=a->n-b->n+1;
            tmp1->n=1;
            tmp1->A[0]=0;
            tmp2->n=1;
            i=0;
            while (COM_NN_D(tmp1,b)==1)//finding first n figures of a that make a number more or equal than b
            {
                tmp2->A[0]=a->A[a->n-1-i];
                tmp1=ADD_NN_N(MUL_Nk_N(tmp1,1),tmp2);
                i++;
            }
            while (COM_NN_D(a,b)!=1)
            {
                res->A[j]=DIV_NN_Dk(tmp1,b)[0];
                a=SUB_NDN_N(a,res->A[j],MUL_Nk_N(b,DIV_NN_Dk(a,b)[1]));
                tmp1=SUB_NDN_N(tmp1,res->A[j],b);
                j++;
                if (NZER_N_B(tmp1)==1) k=0;
                else k=tmp1->n;
                i=0;
                while (COM_NN_D(tmp1,b)==1)
                {
                    tmp2->A[0]=a->A[a->n-1-i-k];
                    tmp1=ADD_NN_N(MUL_Nk_N(tmp1,1),tmp2);
                    i++;
                }
                for (k=0;k<i-1;k++) {res->A[j]=0;j++;}
            }
            for (i=0;i<res->n/2;i++)
            {
                k=res->A[i];
                res->A[i]=res->A[res->n-1-i];
                res->A[res->n-1-i]=k;
            }
            if (res->n==0) {res->n=1;res->A[0]=0;}
        }
        else{free(res);res=NULL;}
    }
    return res;
}

/*N-12: Remainder of division of a bigger natural number by a smaller or equal natural number (divider is nonzero)*/
N *MOD_NN_N (N *a, N *b)
{
    int i;
    N *res;
    res=(N*)malloc(sizeof(N));
    if (res)
    {
        res=a;
        for (i=0;i<DIV_NN_N(a,b)->n;i++) res=SUB_NDN_N(res,(DIV_NN_N(a,b)->A[i]),MUL_Nk_N(b,i));
    }
    return res;
}

/*N-13: GCF of two natural numbers*/
N *GCF_NN_N(N *a, N *b)
{
    N *res=NULL;
    res=(N*)malloc(sizeof(N));
    if (res)
    {
        while ((NZER_N_B(a)==0)&&(NZER_N_B(b)==0))
        {
            if (COM_NN_D(a,b)==2) a=MOD_NN_N(a,b);
            else b=MOD_NN_N(b,a);
        }
        res=ADD_NN_N(a,b);
        while (res->A[res->n-1]==0) res->n--;
    }
    return res;
}

/*N-14: LCM of two natural numbers*/
N *LCM_NN_N(N *a, N *b)
{
    N *res=NULL;
    res=(N*)malloc(sizeof(N));
    if (res) res=(DIV_NN_N(MUL_NN_N(a,b),GCF_NN_N(a,b)));
    return res;
}
