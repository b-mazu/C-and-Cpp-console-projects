#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
char wylosowane[7][7] = {
        { ' ', 'A', 'D','F','G','V', 'X' },
        { 'A'},
        { 'D'},
        { 'F'},
        { 'G'},
        { 'V'},
        { 'X'},
    };
bool czyBylaWylosowana( char iznak, char tab[7][7])
{
    
	for(int i=1; i<7; i++)
        	{
        		for(int j=1; j<7; j++)
        		{
        			            if(tab[i][j] == iznak)        			            
           						return true;	
								 					   
				}
			}
    
return false;
}

char wylosuj()
{	
   char a=( rand() % 36 );
   if (a<26) return (a+'a');
   if(a>=26) return (a-26+'0');

}
int main()
{
    srand( time( 0 ) );
    int wylosowanych=0;
    
 for(int k=0; k<25000; k++){

        char znak = wylosuj();
        if(czyBylaWylosowana( znak, wylosowane) == false )
        {
        	for(int i=1; i<7; i++)
        	{	       znak = wylosuj();
        		for(int j=1; j<7; j++)
        		{        znak = wylosuj();
							if(czyBylaWylosowana( znak, wylosowane) == false ) 
        			            wylosowane[i][j] = znak;
        			       
        			          
        			            
				}
			}
		}
 }


    
    for(int i=0; i<7; i++)
        	{
        		for(int j=0; j<7; j++)
        		{
        		cout<<wylosowane[i][j]," ";cout<<" ";
           	}
			   cout<<"\n";}
    
    
string txt;
string haslo;
cout<<"Podaj tekst do zaszyfrowania"<<endl;
getline(cin, txt);
cout<<"Podaj haslo"<<endl;
getline(cin, haslo);
int z=haslo.size();
int w= txt.size();
int c=((2*w)/z) + ((w%z));
cout<<c<<endl;
cout<<z<<endl;
cout<<w<<endl;
char tab2[z][c];
int k=0,l=0;
cout<<"Zaszyfrowany:"<<endl;
for (int t=0; t<w; t++)
{
	for (int i=1; i<7; i++)
		{
		for(int j=1; j<7; j++)
			{
				if(txt[t]==wylosowane[i][j])
					{
					std::cout<<wylosowane[i][0]<<":"<<wylosowane[0][j]<<"  ";
					if (k==z){
						l++;
						k=0;
					
					}
					 
						tab2[l][k]=wylosowane[i][0];
						++k;
						if (k==z){
						l++;
						k=0;
						}
						tab2[l][k]=wylosowane[0][j];
						++k;
					}					
					
					}

			}
		}
			cout<<endl;
for (int m=0; m<c; m++){
	for (int n=0; n<z; n++){
		cout<<tab2[m][n];
	}
	cout<<endl;
}

    return 0;
}
