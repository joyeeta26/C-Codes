#include<stdio.h>

struct sparse
{
	int row;
	int col;
	int value;
};
void sub(struct sparse* A,struct sparse* B, struct sparse* D)
{
	int i,j,k;
	int m,n;
	m=A[0].row;
	n=A[0].col;
	i=j=k=1;
	while(i<=A[0].value&&j<=B[0].value)
	{
		if((A[i].row<B[j].row)||(A[i].row==B[j].row&&A[i].col<B[j].col))
		{
			D[k].row=A[i].row;
			D[k].col=A[i].col;
			D[k].value=A[i].value;
			k++;i++;
		}
		else if((A[i].row>B[j].row)||(A[i].row==B[j].row&&A[i].col>B[j].col))
		{
			D[k].row=B[j].row;
			D[k].col=B[j].col;
			D[k].value=-1*B[j].value;
			k++;j++;	
		}
		else
		{
			int diff;
			diff=A[i].value-B[j].value;
		
			if(diff!=0)
			{
			
				D[k].row=A[i].row;
				D[k].col=A[i].col;
				D[k].value=A[i].value-B[j].value;
				k++;
			}
			i++;j++;
			
		}
	
	}
	while(i<=A[0].value)
	{
			D[k].row=A[i].row;
			D[k].col=A[i].col;
			D[k].value=A[i].value;
			k++;i++;
	}
	while(j<=B[0].value)
	{
			D[k].row=B[j].row;
			D[k].col=B[j].col;
			D[k].value=-1*B[j].value;
			k++;j++;
	}
		D[0].row=A[0].row;
		D[0].col=A[0].col;
		D[0].value=k-1;

}
void add(struct sparse* A,struct sparse* B,struct sparse* C)
{
	int i,j,k;

	int m,n;
	m=A[0].row;n=A[0].col;
	i=j=k=1;
	while(i<=A[0].value&& j<=B[0].value)
	{
		if(A[i].row<B[j].row||(A[i].row==B[j].row&&A[i].col<B[j].col))
		{
			C[k].row=A[i].row;
			C[k].col=A[i].col;
			C[k].value=A[i].value;
			i++;k++;
		}
		else if(A[i].row>B[j].row||(A[i].row==B[j].row&&A[i].col>B[j].col))
		{
			C[k].row=B[j].row;
			C[k].col=B[j].col;
			C[k].value=B[j].value;
			k++;j++;
		}
		else
		{
			
			
				C[k].col=A[i].col;
				C[k].row=A[i].row;
				C[k].value=A[i].value+B[j].value;
				i++;j++;k++;
			
		}
	}
	while(i<=A[0].value)
	{
		C[k].row=A[i].row;
		C[k].col=A[i].col;
		C[k].value=A[i].value;
		i++;
		k++;
	}
	while(j<=B[0].value)
	{
		C[k].row=B[j].row;
		C[k].col=B[j].col;
		C[k].value=B[j].value;
		j++;
		k++;
	}
	C[0].col=A[0].col;
	C[0].row=A[0].row;
	C[0].value=k-1;	
		
}

void Display(struct sparse* M)
{
	int m=M[0].col;
	int n=M[0].row;
	int val=M[0].value;
	int k=1,i,j;
	for( i=0;i<n;i++)
	{
		for( j=0;j<m;j++)
		{
			if(k<=val)
			{
				if(i==M[k].row&& j==M[k].col)
				{
					printf("%6d",M[k].value);
					k++;
					continue;
				}
			}
			printf("%6d",0);
			
		}
		printf("\n");
	}
}
int main()
{
	int m,n,i,j;
	struct sparse A[20],B[20],C[20],D[20];
	
	printf("Enter rows and columns of the matrix A:\n");
	scanf("%d%d",&A[0].row,&A[0].col);
	
	printf("Enter rows and columns of the matrix B:\n");
	scanf("%d%d",&B[0].row,&B[0].col);
	
	printf("Enter Number of nonzero elements in A:\n");
	scanf("%d",&A[0].value);
	printf("Enter the non zero elements of Matrix A along with their row and column(r,c,val):\n");
	for( i=1;i<=A[0].value;i++)
	{
		scanf("%d%d%d",&A[i].row,&A[i].col,&A[i].value);	
	}
	
	printf("Enter Number of nonzero elements in B :\n");
	scanf("%d",&B[0].value);
	printf("Enter the non zero elements of Matrix B along with their row and column(r,c,val):\n");
	for( i=1;i<=B[0].value;i++)
	{
		scanf("%d%d%d",&B[i].row,&B[i].col,&B[i].value);	
	}	
	
	if(A[0].row==B[0].row&&A[0].col==B[0].col)
	{
		add(A,B,C);
		sub(A,B,D);
	}
	else
	{
		printf("Matrices cannot be added or subtracted\n");
	}
printf("MAtrix A\n");				Display(A);
printf("MAtrix B\n");				Display(B);
printf("MAtrix A+Matrix B\n");		Display(C);
printf("MAtrix A- Matrix B\n");		Display(D);
	return 0;
}

