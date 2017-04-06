#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;




int main()
{
    srand( time( NULL ) );
    int plansza[11][11];
    int plansza2[11][11];
    int mina = 10;
    int bomba=15;
    int serce=0;



    for(int i=0;i<11;i++) //WYPELNIA CALA TABLICE LICZBA 13
    {
        for(int j=0;j<11;j++)
        {
            plansza[i][j]==13;
        }
    }

    int liczi=0;
    for(int i=0;i<11;i++) //WYPISUJE POZIOMO CYFRY OD 0-10 W CELU NAWIGACJI PODCZAS GRY
    {
       plansza[i][0]=liczi;
       liczi++;
    }

    int liczj=0;
    for(int j=0;j<11;j++)   //WYPISUJE PIONOWO CYFRY OD 0-10 W CELU NAWIGACJI PODCZAS GRY
    {
       plansza[0][j]=liczj;
       liczj++;
    }


        for(int i=1;i<11;i++) //LOSOWAWNIE WSPOLRZEDNYCH USTAWIENIA MINY
        {
            for(int j=1;j<11;j++)
            {
                if(mina>0)
                {
                    int dol=rand()%11;
                    int prawo=rand()%11;
                    if(plansza[dol][prawo]!=bomba && plansza[dol][prawo]>12) //SPRAWDZA CZY NIE MA TAM JUZ MINY LUB CZY NIE MA TAM CYFER Z NAWIGACJI
                    {
                        plansza[dol][prawo]=bomba;
                        mina--; //ZMNIEJSZA O 1 ILOSC BOMB DO USTAWIENIA
                    }
                }
            }
        }



for(int i=1;i<11;i++)
    {
        for(int j=1;j<11;j++)
        {
if(plansza[i][j]!=bomba)
{

if(i<2 && j<2)
    {
            if (plansza[i][j+1]==bomba) serce++;
            if (plansza[i+1][j]==bomba) serce++;
            if (plansza[i+1][j+1]==bomba) serce++;
            plansza[i][j]=serce;
            serce=0;



    }
else if(i<2 && j>1 && j<10)
{
            if (plansza[i][j-1]==bomba) serce++;
            if (plansza[i][j+1]==bomba) serce++;
            if (plansza[i+1][j-1]==bomba) serce++;
            if (plansza[i+1][j]==bomba) serce++;
            if (plansza[i+1][j+1]==bomba) serce++;
            plansza[i][j]=serce;
            serce=0;
}

else if(i>1 && i<10 && j>1 && j<10)
{
            if (plansza[i-1][j-1]==bomba) serce++;
            if (plansza[i-1][j]==bomba) serce++;
            if (plansza[i-1][j+1]==bomba) serce++;
            if (plansza[i][j-1]==bomba) serce++;
            if (plansza[i][j+1]==bomba) serce++;
            if (plansza[i+1][j-1]==bomba) serce++;
            if (plansza[i+1][j]==bomba) serce++;
            if (plansza[i+1][j+1]==bomba) serce++;
            plansza[i][j]=serce;
            serce=0;
}

else if(i<2 && j>9)
{
            if (plansza[i][j-1]==bomba) serce++;
            if (plansza[i+1][j-1]==bomba) serce++;
            if (plansza[i+1][j]==bomba) serce++;
            plansza[i][j]=serce;
            serce=0;
}

else if(j<2 && i>1 && i<10)
{
            if (plansza[i-1][j]==bomba) serce++;
            if (plansza[i-1][j+1]==bomba) serce++;
            if (plansza[i][j+1]==bomba) serce++;
            if (plansza[i+1][j]==bomba) serce++;
            if (plansza[i+1][j+1]==bomba) serce++;
            plansza[i][j]=serce;
            serce=0;
}

else if(j<2 && i>9)
{
            if (plansza[i-1][j]==bomba) serce++;
            if (plansza[i-1][j+1]==bomba) serce++;
            if (plansza[i][j+1]==bomba) serce++;
            plansza[i][j]=serce;
            serce=0;
}

else if(i>9 && j>1 && j<10)
{
            if (plansza[i-1][j-1]==bomba) serce++;
            if (plansza[i-1][j]==bomba) serce++;
            if (plansza[i-1][j+1]==bomba) serce++;
            if (plansza[i][j-1]==bomba) serce++;
            if (plansza[i][j+1]==bomba) serce++;
            plansza[i][j]=serce;
            serce=0;
}

else if(i>9 && j>9)
{
            if (plansza[i-1][j-1]==bomba) serce++;
            if (plansza[i-1][j]==bomba) serce++;
            if (plansza[i][j-1]==bomba) serce++;
            plansza[i][j]=serce;
            serce=0;
}

else if(i>1 && i<10 && j>9)
{
            if (plansza[i-1][j-1]==bomba) serce++;
            if (plansza[i-1][j]==bomba) serce++;
            if (plansza[i][j-1]==bomba) serce++;
            if (plansza[i+1][j-1]==bomba) serce++;
            if (plansza[i+1][j]==bomba) serce++;
            plansza[i][j]=serce;
            serce=0;
}
        }}}



    for(int i=0;i<11;i++) //Robi kopie pierwszej tablicy
        {
            for(int j=0;j<11;j++)
            {
                plansza2[i][j]=plansza[i][j];
            }
        }

    for(int i=1;i<11;i++) //Wypelnia cala tablice ukrytymi kwadracikami, oprocz bocznych cyfr wspolrzednych
        {
            for(int j=1;j<11;j++)
            {
                plansza2[i][j]=254;
            }
        }


        for(int i=0;i<11;i++) //Wyswietla tablice
        {
            for(int j=0;j<11;j++)
            {
                if(plansza2[i][j]==bomba || plansza2[i][j]==254) cout<<(char)plansza2[i][j]<<"|"; // wypisz tablice
                else cout<<plansza2[i][j]<<"|";
                if(j==10) cout<<endl;
            }
        }

    cout<<endl;
    int x,y;
    int red_flag=0;
    bool ok=false;
    do
    {

    cout<<"Podaj wspolrzedne pola ktore chcesz odkryc (1-10):"<<endl;
// Sprawdzanie czy wspolrzedne podane przez uzytkownika sa poprawne
    do{
        cout<<"X: ";
        cin>>x;
        if(x<1 || x>10)
        {
            cout<<"Podales zbyt wysoka lub niska liczbe."<<endl;
            ok=false;
        }
        else ok=true;
    }while(ok!=true);

    do{
        cout<<"Y: ";
        cin>>y;
        if(y<1 || y>10)
        {
            cout<<"Podales zbyt wysoka lub niska liczbe."<<endl;
            ok=false;
        }
        else ok=true;
    }while(ok!=true);


    cout<<endl;
    cout<<endl;

    system( "cls" ); //CZYSCI EKRAN

    plansza2[y][x]=plansza[y][x];  //Odkrywam jedno pole na ukrytej planszy, wskazane przez gracza (Zamieniam komorke ze znakiem z pierwszej tablicy i wpisuje ja w miejsce wspolrzednych tablicy zakrytej
    if(plansza[y][x]==bomba)  //sprawdzanie czy Wspolrzedne gracza wskazuja na bombe. Jesli tak to odkrywam wszystkie bomby
    {
        for(int i=0;i<11;i++)
        {
            for(int j=0;j<11;j++)
            {
                if(plansza[i][j]==bomba) plansza2[i][j]=plansza[i][j]; //sprawdzam kazde pole i przenosze (odkrywam) wszystkie bomby na zakrytej planszy
                if(plansza2[i][j]==bomba || plansza2[i][j]==254) cout<<(char)plansza2[i][j]<<"|"; //wyswietlam bomby jako Char
                else cout<<plansza2[i][j]<<"|"; //Wyswietlam pozostale Cyfry
                if(j==10) cout<<endl;
            }
        }
        cout<<endl<<"Wdeples w bombe! Koniec gry";
        cout<<endl;
        red_flag=1; //ustawia koniec petli
    }
    else        //jesli to nie bomba
        for(int i=0;i<11;i++)
        {
            for(int j=0;j<11;j++)
            {
                if(plansza2[i][j]==bomba || plansza2[i][j]==254) cout<<(char)plansza2[i][j]<<"|"; //to wypisz tablice
                else cout<<plansza2[i][j]<<"|";
                if(j==10) cout<<endl;
            }
        }
        cout<<endl;

    }while(red_flag!=1);

system("PAUSE");

return 0;
}
