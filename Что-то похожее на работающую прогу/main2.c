#include "polynom.h"


int main(){
    P* tmp = polyGet();
    polyPrint(tmp);
    polyFree(tmp);
}


N* natural_parsing(char *s, int lim)
{
	N* b;
	int n;
	n = new_gets(s,lim);
	b = (N*)malloc(sizeof(N));
	if(b)
	{
		b->A = (int*)malloc(n*sizeof(int));
		input(b,s,n);
	}
	return b;
}

Z* int_parsing(char *s, int lim)
{
	Z* a;
	int n;
	n = new_gets(s,lim);
	a = (Z*)malloc(sizeof(Z));
	a->num = (N*)malloc(sizeof(N));
	a->num->A = (int*)malloc(n*sizeof(int));
	a->sign = input(a->num,s,n);
	return a;
}

Q* rat_parsing(char *s)
{
	char *s1,*s2;
	Q* a;
	int lim;
	lim = 150;
	int i,j,size_s1,size_s2;
	s1 = (char*)malloc(lim*sizeof(char));
	s2 = (char*)malloc(lim*sizeof(char));
	i = 0;
	j = 0;
	if(s1 && s2)
	{
		while(s[i] != '/' && s[i] != '\0')
		{
			s1[i] = s[i];
			i++;
		}
		s1[i] = '\0';
		if(s[i] == '/')
		{
			i+=1;
			while(s[i] != '\0')
			{
				s2[j] = s[i];
				i++;
				j++;
			}
			s2[j] = '\0';
			size_s1 = strlen(s1);
			size_s2 = strlen(s2);	
			a = (Q*)malloc(sizeof(Q));
			a->m = (Z*)malloc(sizeof(Z));
			a->m->num = (N*)malloc(sizeof(N));
			a->m->num->A = (int*)malloc(size_s1*sizeof(int));
			a->m->sign = input(a->m->num,s1,size_s1);
			a->n = (N*)malloc(sizeof(N));
			a->n->A = (int*)malloc(size_s2*sizeof(int));
			input(a->n,s2,size_s2);
		}
		else
		{
			s2[0] = '1';
			s2[1] = '\0';
			size_s1 = strlen(s1);
			size_s2 = strlen(s2);		
			a = (Q*)malloc(sizeof(Q));
			a->m = (Z*)malloc(sizeof(Z));
			a->m->num = (N*)malloc(sizeof(N));
			a->m->num->A = (int*)malloc(size_s1*sizeof(int));
			a->m->sign = input(a->m->num,s1,size_s1);
			a->n = (N*)malloc(sizeof(N));
			a->n->A = (int*)malloc(size_s2*sizeof(int));
			input(a->n,s2,size_s2);
		}
		free(s1);
		free(s2);
		s1 = NULL;
		s2 = NULL;
	}
	return a;
}

void clear_N(N* a)
{
	free(a->A);
	a->A = NULL;
	free(a);
	a = NULL;
}

void clear_Z(Z* a)
{
	clear_N(a->num);
	free(a);
	a = NULL;
}

void clear_Q(Q* a)
{
	clear_Z(a->m);
	clear_N(a->n);
}

