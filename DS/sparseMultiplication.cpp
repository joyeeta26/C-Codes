#include <iostream>

using namespace std;

typedef struct sparse{

int row,col,val;

}sparse;

void printSparse(sparse arr[]){

cout<<"\n";

int k = 1;

    for (int i = 0 ; i < arr[0].row ; i++){

        for (int j = 0 ; j < arr[0].col ; j++){

            if (i == arr[k].row && j == arr[k].col && k <= arr[0].val){

                cout<<arr[k].val<<" ";

                k++;

            }

            else

                cout<<"0 ";

        }

        cout<<"\n";

    }

}

sparse* transpose(sparse a[]){

    sparse *b = new sparse[a[0].val + 1];

    int c[a[0].col];

    for (int i = 0 ; i < a[0].col ; ++i){

        c[i] = 0;

    }

    for (int i = 1 ; i <= a[0].val; i++)

            c[a[i].col]++;

    int d[a[0].col];

    d[0] = 1;

    for (int i = 1 ; i < a[0].col ; ++i){

        d[i] = d[i - 1] + c[i - 1];

    }

    for (int i = 1 ; i <= a[0].val ; ++i){

        b[d[a[i].col]].col = a[i].row;

        b[d[a[i].col]].row = a[i].col;

        b[d[a[i].col]].val = a[i].val;

        d[a[i].col]++;

    }

    b[0].row = a[0].col;

    b[0].col = a[0].row;

    b[0].val = a[0].val;

    return b;

}

int go_where(sparse a[], int i){

    for (int j = 1 ; j <= a[0].val ; j++){

        if (a[j].row == i)

            return j;

    }

    return -1;

}

sparse* multiply(sparse a[], sparse b[]){

    int m1 = a[0].row;

    int m2 = b[0].row;

    int k = 1;

    sparse *c = new sparse[100];

    c[0].row = m1;

    c[0].col = m2;

    c[0].val = 0;

    for (int i = 0 ; i < m1 ; i++){

        for (int j = 0 ; j < m2 ; j++){

            int mult = 0;

            int x = go_where(a,i);

            int y = go_where(b,j);

            if (x != -1 && y != -1){

                while (a[x].row == i && b[y].row == j){

                    if (a[x].col > a[y].col)

                        y++;

                    else if (a[x].col < a[y].col)

                                x++;

                            else{

                                mult += a[x].val * b[y].val;

                                x++;

                                y++;

                            }

                }

            }

            if (mult != 0){

                c[k].row = i;

                c[k].col = j;

                c[k].val = mult;

                c[0].val++;

                k++;

            }

        }

    }

    return c;

}

int main(){

    //input matrix 1

    int m1,n1,nz1;

    cout<<"Enter Number of Rows, Number of Columns, Number of Non-Zero entries for Matrix 1\n";

    cin>>m1>>n1>>nz1;

    sparse arr[nz1 + 1];

    arr[0].row = m1;

    arr[0].col = n1;

    arr[0].val = nz1;

    cout<<"\nEnter entries of sparse matrix in format (row : col : val)\n";

    for(int i = 1 ; i <= nz1 ; i++)

        cin>>arr[i].row>>arr[i].col>>arr[i].val;

    printSparse(arr);

    //input matrix 2

    int m2,n2,nz2;

    cout<<"Enter Number of Rows, Number of Columns, Number of Non-Zero entries for Matrix 2\n";

    cin>>m2>>n2>>nz2;

    sparse brr[nz2 + 1];

    brr[0].row = m2;

    brr[0].col = n2;

    brr[0].val = nz2;

    cout<<"\nEnter entries of sparse matrix in format (row : col : val)\n";

    for(int i = 1 ; i <= nz2 ; i++)

        cin>>brr[i].row>>brr[i].col>>brr[i].val;

    printSparse(brr);

    //take transpose of brr

    sparse* b = transpose(brr);

    //Check for multiplication condition

    if (n1 != m2){

        cout<<"Multiplication not possible";

        return 1;

    }

    sparse* result;

    result = multiply(arr, b);

    cout<<"\nThe result of multiplication is:\n";

    printSparse(result);

    // multiply(arr,brr);

    return 0;

}
