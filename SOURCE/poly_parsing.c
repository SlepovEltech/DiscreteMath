#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int new_gets(char *s, int lim) 
{
	int i;
	char c;
	for(i = 0;(i < lim -1) &&  ((c = getchar()) != '\n'); s++,i++) *s = c;
	*s = '\0';
	return i;
}

int input(N *q,char *s, int n) 
{
	int i,sign;
	if(s[0] == '-')
	{
		sign = 1;
		for(i = 1; i < n; i++)
		{
			q->A[n-i-1] = s[i]-'0';
		}
		q->n = n-1;
	}
	if(s[0] != '-')
	{
		sign = 0;
		q->n = n;
		for(i = 0; i < n; i++)
		{
			q->A[q->n-i-1] = s[i]-'0';
		}
	}
	return sign;
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

int main()
{
	char *s = NULL, *s1 = NULL;
	int n,i,j,m;
	int lim = 150;
	s = (char*)malloc(lim*sizeof(int));
	s1 = (char*)malloc(lim/2*sizeof(int));
	n = new_gets(s,lim);
	while(s[i] != '\n')
	{
		if(s[i] == 'x')
		{
			m = 0;
			j = i-1;
			while(isdigit(s[j]))
			{
				
			}
		}
		i+=1;
	}
	return 0;
}