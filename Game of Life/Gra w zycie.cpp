#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;




int main()
{
    srand( time( NULL ) );
    int plansza[10][10];
    int plansza2[10][10];


    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            plansza[i][j]=rand()%2;
            cout<<plansza[i][j]<<"|";
            if(j==9) cout<<endl;

        }
    }

int serce=0;

Skoczek:


for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {

if(i<1 && j<1)
    {
            if (plansza[i][j+1]>0) serce++;
            if (plansza[i+1][j]>0) serce++;
            if (plansza[i+1][j+1]>0) serce++;
            if (plansza[i][j]>0)
            {
                if(serce>3) plansza2[i][j]=0;
                if(serce<2) plansza2[i][j]=0;
                if(serce>=2 && serce<=3) plansza2[i][j]=1;
            }
            else if(plansza[i][j]<1)
            {
                if(serce==3) plansza2[i][j]=1;
                if(serce<3 || serce>3) plansza2[i][j]=0;
            }
            serce=0;



    }
else if(i<1 && j>0 && j<9)
{
            if (plansza[i][j-1]>0) serce++;
            if (plansza[i][j+1]>0) serce++;
            if (plansza[i+1][j-1]>0) serce++;
            if (plansza[i+1][j]>0) serce++;
            if (plansza[i+1][j+1]>0) serce++;
            if (plansza[i][j]>0)
            {
                if(serce>3) plansza2[i][j]=0;
                if(serce<2) plansza2[i][j]=0;
                if(serce>=2 && serce<=3) plansza2[i][j]=1;
            }
            else if(plansza[i][j]<1)
            {
                if(serce==3) plansza2[i][j]=1;
                if(serce<3 || serce>3) plansza2[i][j]=0;
            }
            serce=0;
}

else if(i>0 && i<9 && j>0 && j<9)
{
            if (plansza[i-1][j-1]>0) serce++;
            if (plansza[i-1][j]>0) serce++;
            if (plansza[i-1][j+1]>0) serce++;
            if (plansza[i][j-1]>0) serce++;
            if (plansza[i][j+1]>0) serce++;
            if (plansza[i+1][j-1]>0) serce++;
            if (plansza[i+1][j]>0) serce++;
            if (plansza[i+1][j+1]>0) serce++;
            if (plansza[i][j]>0)
            {
                if(serce>3) plansza2[i][j]=0;
                if(serce<2) plansza2[i][j]=0;
                if(serce>=2 && serce<=3) plansza2[i][j]=1;
            }
            else if(plansza[i][j]<1)
            {
                if(serce==3) plansza2[i][j]=1;
                if(serce<3 || serce>3) plansza2[i][j]=0;
            }
            serce=0;
}

else if(i<1 && j>8)
{
            if (plansza[i][j-1]>0) serce++;
            if (plansza[i+1][j-1]>0) serce++;
            if (plansza[i+1][j]>0) serce++;
            if (plansza[i][j]>0)
            {
                if(serce>3) plansza2[i][j]=0;
                if(serce<2) plansza2[i][j]=0;
                if(serce>=2 && serce<=3) plansza2[i][j]=1;
            }
            else if(plansza[i][j]<1)
            {
                if(serce==3) plansza2[i][j]=1;
                if(serce<3 || serce>3) plansza2[i][j]=0;
            }
            serce=0;
}

else if(j<1 && i>0 && i<9)
{
            if (plansza[i-1][j]>0) serce++;
            if (plansza[i-1][j+1]>0) serce++;
            if (plansza[i][j+1]>0) serce++;
            if (plansza[i+1][j]>0) serce++;
            if (plansza[i+1][j+1]>0) serce++;
            if (plansza[i][j]>0)
            {
                if(serce>3) plansza2[i][j]=0;
                if(serce<2) plansza2[i][j]=0;
                if(serce>=2 && serce<=3) plansza2[i][j]=1;
            }
            else if(plansza[i][j]<1)
            {
                if(serce==3) plansza2[i][j]=1;
                if(serce<3 || serce>3) plansza2[i][j]=0;
            }
            serce=0;
}

else if(j<1 && i>8)
{
            if (plansza[i-1][j]>0) serce++;
            if (plansza[i-1][j+1]>0) serce++;
            if (plansza[i][j+1]>0) serce++;
            if (plansza[i][j]>0)
            {
                if(serce>3) plansza2[i][j]=0;
                if(serce<2) plansza2[i][j]=0;
                if(serce>=2 && serce<=3) plansza2[i][j]=1;
            }
            else if(plansza[i][j]<1)
            {
                if(serce==3) plansza2[i][j]=1;
                if(serce<3 || serce>3) plansza2[i][j]=0;
            }
            serce=0;
}

else if(i>8 && j>0 && j<9)
{
            if (plansza[i-1][j-1]>0) serce++;
            if (plansza[i-1][j]>0) serce++;
            if (plansza[i-1][j+1]>0) serce++;
            if (plansza[i][j-1]>0) serce++;
            if (plansza[i][j+1]>0) serce++;
            if (plansza[i][j]>0)
            {
                if(serce>3) plansza2[i][j]=0;
                if(serce<2) plansza2[i][j]=0;
                if(serce>=2 && serce<=3) plansza2[i][j]=1;
            }
            else if(plansza[i][j]<1)
            {
                if(serce==3) plansza2[i][j]=1;
                if(serce<3 || serce>3) plansza2[i][j]=0;
            }
            serce=0;
}

else if(i>8 && j>8)
{
            if (plansza[i-1][j-1]>0) serce++;
            if (plansza[i-1][j]>0) serce++;
            if (plansza[i][j-1]>0) serce++;
            if (plansza[i][j]>0)
            {
                if(serce>3) plansza2[i][j]=0;
                if(serce<2) plansza2[i][j]=0;
                if(serce>=2 && serce<=3) plansza2[i][j]=1;
            }
            else if(plansza[i][j]<1)
            {
                if(serce==3) plansza2[i][j]=1;
                if(serce<3 || serce>3) plansza2[i][j]=0;
            }
            serce=0;
}

else if(i>0 && i<9 && j>8)
{
            if (plansza[i-1][j-1]>0) serce++;
            if (plansza[i-1][j]>0) serce++;
            if (plansza[i][j-1]>0) serce++;
            if (plansza[i+1][j-1]>0) serce++;
            if (plansza[i+1][j]>0) serce++;
            if (plansza[i][j]>0)
            {
                if(serce>3) plansza2[i][j]=0;
                if(serce<2) plansza2[i][j]=0;
                if(serce>=2 && serce<=3) plansza2[i][j]=1;
            }
            else if(plansza[i][j]<1)
            {
                if(serce==3) plansza2[i][j]=1;
                if(serce<3 || serce>3) plansza2[i][j]=0;
            }
            serce=0;
}
        }}

cout<<endl;
cout<<endl;

for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            plansza[i][j]=plansza2[i][j];
        }
    }

for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<plansza[i][j]<<"|";
            if(j==9) cout<<endl;
        }
    }
system("PAUSE");
goto Skoczek;

return 0;
}
