int COM_NN_D (N *a, N *b) // a- ïåðâûé ìàññèâ b-âòîðîé ìàññèâ n-ðàçìåðíîñòü ïåðâîãî m-ðàçìåðíîñòü âòîðîãî
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