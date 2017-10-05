#include<stdio.h>
char square[10]={'0','1','2','3','4','5','6','7','8',' '};
void board();
void player();
int checkwin();
char pl1='X', pl2='O',i=0,c=0;
void board()
{
	
	printf(" %c | %c | %c \n", square[0],square[1],square[2]);
	printf("--- --- ---\n");
	printf(" %c | %c | %c \n", square[3],square[4],square[5]);
	printf("--- --- ---\n");
	printf(" %c | %c | %c \n", square[6],square[7],square[8]);
	printf("--- --- ---\n");
}
int mark(char pl,int pos){
int a;
	if(pl=='X'||pl=='O')
	{
		if((square[pos]!='X' ) && (square[pos]!='O'))
		{
			square[pos]=pl;
			c++;
				
			a=checkwin();
			if(a==-1 && c==9)
				return 0;
			else
				return a;	
		}
			
			printf("Invalid move");
			i--;
		
		
	}

}
int checkwin(){
	if((square[0]==square[1])&&(square[1]==square[2]))
	return 1;
	else if((square[3]==square[4])&&(square[4]==square[5]))
	return 1;
	else if((square[6]==square[7])&&(square[7]==square[8]))
	return 1;
	else if((square[0]==square[3])&&(square[3]==square[6]))
	return 1;
	else if((square[2]==square[5])&&(square[5]==square[8]))
	return 1;
	else if((square[1]==square[4])&&(square[4]==square[7]))
	return 1;
	else if((square[0]==square[4])&&(square[4]==square[8]))
	return 1;
	else if((square[2]==square[4])&&(square[4]==square[6]))
	return 1;
	else
	return -1;
}
int main()
{
	char pos;
	int player;
	int a;
	printf("Tic tac toe version 1.0\n");
	printf("player 1 is X\n");
	printf("player 2 is O\n");	
	do{
	
		board();
		player=(i%2);
		if(player==1)
		{
			printf("Enter the position where you want to insert:\n");
			scanf("%d",&pos);
			a=mark(pl1,pos);
			
			
		}
		else
		{
			printf("Enter the position where you want to insert:\n");
			scanf("%d",&pos);
			a=mark(pl2,pos);
		
		}
	i++;
	}while(a==-1);
	if(a==1)
	{
		board();
		printf("Player %d wins",player+1);	
	}
	else if(a==0)
	{
		board();
		printf("Game draws");
	}

	
	return 0;
}
