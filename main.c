#include "struct.h"
#include "prototypes.h"
#include "natural.h"

int main()
{
	N *q, *w;
	Z d,t;
	P g,f;
	int n,i,lim,key,clas;
	char *s;
	int sys;
	lim = 150;
	printf("Choose your OS type:\n1-Windows\n2-Linux\nYour answer: ");
	scanf("%d", &sys);	
	while(sys < 0 || sys > 2)
	{
		printf("Wrong answer! Try again: ");
		scanf("%d", &sys);	
	}
	clear(sys);
	s = (char*)malloc(lim*sizeof(char));
	if(s != NULL)
	{
		while( (key = menu()) != 3)
		{
		    if(key != 3 && key != 2 && key != 1)
	        {
	            printf("Enter a correct answer!\n");
	        }
	        if(key == 1)
	        {
	        	printf("Choose class of number to work:\n1-Natural+{0}\n2-Integer\n3-Rational\n4-Polinom\nYour answer: ");
	        	scanf("%d", &clas);
	        	clear(sys);
	        	if(clas == 1) 
	        	{
	        		q = (N*)malloc(sizeof(N));
	        		w = (N*)malloc(sizeof(N));
	        		if(q && w)
	        		{
	        			switch(natural())
						{
							case 1:
								printf("Enter first number: "); 
								getchar();
								input(q,s,lim);		
								printf("Enter second number: "); 
								input(w,s,lim);	
								printf("Result: %d\n",COM_NN_D(q,w));
								break;					
							case 2: 
								printf("Enter your number: "); 
								input(q,s,lim);	
							default: 
							break;
						}		   
	        		}     		
	        	}
	        	if(clas == 2)
	        	{

	        	}
	        	if(clas == 3)
	        	{

	        	}
	        	if(clas == 4)
	        	{

	        	}

        	}
        }
	    free(s);
		s = NULL;
	}
	else
		printf("Error at memory location! Bye!");
	return 0;
}

 