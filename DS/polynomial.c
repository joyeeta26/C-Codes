#include<stdio.h>


struct Node
{
	float coef;
	int exp;
};
typedef struct Node Poly;
Poly P1[20],P2[20],P3[20],P4[20];
void display(Poly P[],int *s);
void addPoly(Poly P1[],Poly P2[],Poly P3[],int s1,int s2,int *s3);
void multTerm(Poly P1[],Poly P2[],float c,int e,int s1);
void copy(Poly P3[],Poly P5[],int s5);
void multPoly(Poly P1[],Poly P2[],Poly P3[],int s1,int s2,int* s3);
int main()
{
	int s1,s2,s3,i,s4;
printf("Enter the number of terms in the polynomial 1:\n");
scanf("%d",&s1);
printf("Enter the coefficients and power of the terms in decreasing order of powers:");
	for( i=0;i<s1;i++)
	{
		scanf("%f%d",&P1[i].coef,&P1[i].exp);
	}
	printf("Enter the number of terms in the polynomial 2:\n");
	scanf("%d",&s2);
	printf("Enter the coefficients and power of the terms in decreasing order of powers:");
	for( i=0;i<s2;i++)
	{
		scanf("%f%d",&P2[i].coef,&P2[i].exp);
	}
	printf("The addition of the two polynomials is as follows:\n");
	addPoly(P1,P2,P3,s1,s2,&s3);
	display(P3,&s3);
	printf("\n");
	printf("The subtraction of the two polynomials is as follows:\n");
	subPoly(P1,P2,P4,s1,s2,&s4);
	display(P4,&s4);
	printf("\n");
	printf("The multiplication of the two polynomials is: ");
	multPoly(P1,P2,P3,s1,s2,&s3);	
	display(P3,&s3);	
	return 0;
}
void subPoly(Poly P1[],Poly P2[],Poly P3[],int s1,int s2,int* s3)
{
int i,j,k;
	i=j=k=0;
	while(i<s1 && j<s2)
	{
		if(P1[i].exp==P2[j].exp)
		{
			P3[k].coef=P1[i].coef-P2[j].coef;
			P3[k].exp=P1[i].exp;
			i++;j++;k++;
		}
		else if(P1[i].exp<P2[j].exp)
		{
			P3[k].exp=P2[j].exp;
			P3[k].coef=P2[j].coef;
			k++;j++;
		}
		else
		{
			P3[k].exp=P1[i].exp;
			P3[k].coef=P1[i].coef;
			k++;i++;	
		}
	}
	while(i<s1)
	{
			P3[k].exp=P1[i].exp;
			P3[k].coef=P1[i].coef;
			k++;i++;	
	}
	while(j<s2)
	{
			P3[k].exp=P2[j].exp;
			P3[k].coef=P2[j].coef;
			k++;j++;	
	}
	*s3=k;
}
void addPoly(Poly P1[],Poly P2[],Poly P3[],int s1,int s2,int* s3)
{
	int i,j,k;
	i=j=k=0;
	while(i<s1 && j<s2)
	{
		if(P1[i].exp==P2[j].exp)
		{
			P3[k].coef=P1[i].coef+P2[j].coef;
			P3[k].exp=P1[i].exp;
			i++;j++;k++;
		}
		else if(P1[i].exp<P2[j].exp)
		{
			P3[k].exp=P2[j].exp;
			P3[k].coef=P2[j].coef;
			k++;j++;
		}
		else
		{
			P3[k].exp=P1[i].exp;
			P3[k].coef=P1[i].coef;
			k++;i++;	
		}
	}
	while(i<s1)
	{
			P3[k].exp=P1[i].exp;
			P3[k].coef=P1[i].coef;
			k++;i++;	
	}
	while(j<s2)
	{
			P3[k].exp=P2[j].exp;
			P3[k].coef=P2[j].coef;
			k++;j++;	
	}
	*s3=k;
}
void display(Poly P[],int *s3)
{
	int i=0;
	for(i=0;i<*s3-1;i++)
	{
		if(P[i].exp==0)
		{
			printf("%0.2f+ ",P[i].coef);
		}
		else if(P[i].exp==1)
			printf("%0.2fx+ ",P[i].coef);
		else
		printf("%0.2fx^%d+ ",P[i].coef,P[i].exp);
	}
		if(P[i].exp==0)
		{
				printf("%0.2f ",P[*s3-1].coef);
		}
		else
		printf("%0.2fx^%d ",P[*s3-1].coef,P[*s3-1].exp);
}
void multTerm(Poly P1[],Poly P2[],float c,int e,int s1)
{
	int i;
	for(i=0;i<s1;i++)
	{
		P2[i].coef=P1[i].coef*c;
		P2[i].exp=P1[i].exp+e;
	}
}
void multPoly(Poly P1[],Poly P2[],Poly P3[],int s1,int s2,int* s3)
{
	int i;
	Poly P4[20],P5[20];
	*s3=0;
	int s4,s5;
	for( i=0;i<s2;i++)
	{
		multTerm(P1,P4,P2[i].coef,P2[i].exp,s1);
		s4=s1;
		if(i==0)
		{
			copy(P3,P4,s4);
			*s3=s4;
		}
		else
		{
			addPoly(P3,P4,P5,*s3,s4,&s5);				//adds polynomial P3 and P4 and stores it in P5
			copy(P3,P5,s5);
			*s3=s5;
		}
	}
}
void copy(Poly P3[],Poly P5[],int s5)
{
	int i=0;
	for(i=0;i<s5;i++)
	{
		P3[i].coef=P5[i].coef;
		P3[i].exp=P5[i].exp;
	}
}
