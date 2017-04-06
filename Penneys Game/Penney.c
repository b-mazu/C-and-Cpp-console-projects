#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int gra(char tab[], char g1[], char g2[], int *w1, int *w2)
	
	{
		int i=0,j=0,x;
		while(tab[i]==g1[i]&&i<4)
		{
			i++;
		}
		while(tab[j]==g2[j]&&j<4)
		{
			j++;
		}
	
		if(i==4||j==4)
			{
				if(i==4) 
				{
					(*w1)++;
					return 0;
				}
			else
			{
				(*w2)++;
				return 0;	
			} 
			}
		else
		{
			tab[0]=tab[1]; tab[1]=tab[2]; tab[2]=tab[3];
			x=rand()%2;
			if(x==0) tab[3]='O';
			else tab[3]='R';
			return 1;
		}
	}

void losuj(char tab[])
	{
		int i,j;
		for(i=0;i<4;i++)
		{
			j=rand()%2;
			if(j==0) tab[i]='O';
			else tab[i]='R';
		}
	}

	void seria(char tab[])
	{
		int i=0;
		char znak;
		while(scanf("%1c",&znak)!='\n'&&i<4)
		{	
			if(znak=='R')
			{ 
				tab[i]='R';
				i++;
			}
			if(znak=='O') 
				{
				tab[i]='O';
				i++;
		}
		}
	}
	
	
int main()
{
	printf("symulacja 1000 gier Penneya. Podaj serie np. (OORR) )\n" );
	int k=0,wygr1=0,wygr2=0;
	
	char tab[4];
	char gracz_1[4];
	char gracz_2[4];
	srand(time(NULL));
	
	printf("Seria pierwszego gracza: ");
	seria(gracz_1);
	printf("\n");
	
	printf("Seria drugiego gracza: ");
	seria(gracz_2);
	printf("\n");
	
	while(k<1000)
	{
		losuj(tab);
		while(gra(tab,gracz_1,gracz_2,&wygr1,&wygr2));	
		k++;
	}
	printf("Gracz nr 1 wygral %d razy.\n",wygr1);
	printf("Gracz nr 2 wygral %d razy.\n",wygr2);
	
	return 0;	
}

	
	

	
	







