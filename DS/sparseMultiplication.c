//code to multiply two matrices
#include<stdio.h>
#define MAXS 10
struct sparse
{
	int row;
	int col;
	int val;
};
struct sparse res[20];
int v=1;
void addData(int r,int c,int val)
{
	res[v].row=r;
	res[v].col=c;
	res[v].val=val;
	printf("Data Added");
	v++;
}
void sparseTranspose(struct sparse A[],struct sparse B[])
{
	int m,n,t,i,C[MAXS],D[MAXS];
	 m=A[0].row;
	 n=A[0].col;
	 t=A[0].val;
	
	for(i=0;i<n;i++)
		C[i]=0;
	for(i=1;i<=t;i++)
	{
		C[A[i].col]++;
	}
	D[0]=1;
	for(i=1;i<n;i++)
		D[i]=D[i-1]+C[i-1];
	
	for(i=1;i<=t;i++)
	{
		B[D[A[i].col]].col=A[i].row;
		B[D[A[i].col]].row=A[i].col;
		B[D[A[i].col]].val=A[i].val;
		D[A[i].col]++;
	}
	B[0].row=A[0].col;
	B[0].col=A[0].row;
	B[0].val=t;
}
void matrixMultiply(struct sparse* A,struct sparse* C)
{
		struct sparse B[20];
		sparseTranspose(C,B);				//store the transpose of C in B
		
		int aPos=0,bPos=0,lenA=A[0].val,lenB=B[0].val;
	
		 for (aPos = 0; aPos < lenA; ) {
            int r = A[aPos].row; // current row
            for (bPos = 0; bPos <lenB; ) {
                int c = B[bPos].row; // current column
                int scanA = aPos;
                int scanB = bPos;
                int sum = 0;
                while (scanA < lenA && A[scanA].row == r && scanB< lenB && B[scanB].row == c) { // calculate rel[r][c]
                    if (A[scanA].col < B[scanB].col )// scanB has larger column
                        scanA++; // skip a
                    else if (A[scanA].col >B[scanB].col) // scanA has larger column
                        scanB++; // skip b
                    else // same column, so they can multiply
                        sum += A[scanA++].val * B[scanB++].val;
                }
                if (sum != 0) addData(r, c, sum);
                while (bPos < lenB && B[bPos].row == c) bPos++; // jump to next column
            }
            while (aPos < lenA && A[aPos] .row== r) aPos++; // jump to next row
        }
		res[0].row=A[0].row;
		res[0].col=B[0].row;
		res[0].val=v-1;
		
		
}
void display(struct sparse* M)
{
	int m=M[0].row;
	int n=M[0].col;
	int val=M[0].val;
	int k=1,i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(k<=val)
			{
				if(i==M[k].row&&j==M[k].col)
				{
					printf("%6d",M[k].val);
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
	struct sparse A[20],B[20],res[20];
	int i=0;
	printf("Enter the no. of rows and columns of matrix A:\n");
	scanf("%d %d",&A[0].row,&A[0].col);
	printf("Enter the no. of rows and columns of matrix B:\n");
	scanf("%d %d",&B[0].row,&B[0].col);
	if(A[0].col!=B[0].row)
	printf("matrix cannot be multiplied...\n");
	else
	{
		printf("Enter the no. of non zero elements in A:\n");
		scanf("%d",&A[0].val);
		
		printf("Enter the non zero elements of A along with their row and column:(row,col,val)\n");
		for( i=1;i<=A[0].val;i++)
		{
			scanf("%d %d %d",&A[i].row,&A[i].col,&A[i].val);
		}
		printf("Enter the no. of non zero elements in B:\n");
		scanf("%d",&B[0].val);
		printf("Enter the non zero elements of B along with their row and column:(row,col,val)\n");
		for( i=1;i<=B[0].val;i++)
		{
			scanf("%d %d %d",&B[i].row,&B[i].col,&B[i].val);
		}
	
		printf("Matrix A:\n");	    display(A);
		printf("Matrix B:\n");  	display(B);
			matrixMultiply(A,B);
		printf("Matrix A*B:\n");	display(res);		
	}
	return 0;
}

