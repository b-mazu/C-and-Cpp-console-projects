#include <stdio.h>
#include <stdlib.h>

int sprawdz_dlugosc(int liczba){
		int dlugosc = 0;
		while(liczba){
				liczba = liczba/10;
				dlugosc++;
}
return dlugosc;
}

int main(){
	
	int i,j;
	
	int liczba;		
	int dlugosc;

	int tab1[10];	

	int k = 0;
	int cyfra[10];

char tablica[10][3][3];
	
tablica[0][0][0] = ' ';
tablica[0][0][1] = '_';
tablica[0][0][2] = ' ';
tablica[0][1][0] = '|';
tablica[0][1][1] = ' ';
tablica[0][1][2] = '|';
tablica[0][2][0] = '|';
tablica[0][2][1] = '_';
tablica[0][2][2] = '|';


tablica[1][0][0] = ' ';
tablica[1][0][1] = ' ';
tablica[1][0][2] = ' ';
tablica[1][1][0] = ' ';
tablica[1][1][1] = ' ';
tablica[1][1][2] = '|';
tablica[1][2][0] = ' ';
tablica[1][2][1] = ' ';
tablica[1][2][2] = '|';

tablica[2][0][0] = ' ';
tablica[2][0][1] = '_';
tablica[2][0][2] = ' ';
tablica[2][1][0] = ' ';
tablica[2][1][1] = '_';
tablica[2][1][2] = '|';
tablica[2][2][0] = '|';
tablica[2][2][1] = '_';
tablica[2][2][2] = ' ';

tablica[3][0][0] = ' ';
tablica[3][0][1] = '_';
tablica[3][0][2] = ' ';
tablica[3][1][0] = ' ';
tablica[3][1][1] = '_';
tablica[3][1][2] = '|';
tablica[3][2][0] = ' ';
tablica[3][2][1] = '_';
tablica[3][2][2] = '|';

tablica[4][0][0] = ' ';
tablica[4][0][1] = ' ';
tablica[4][0][2] = ' ';
tablica[4][1][0] = '|';
tablica[4][1][1] = '_';
tablica[4][1][2] = '|';
tablica[4][2][0] = ' ';
tablica[4][2][1] = ' ';
tablica[4][2][2] = '|';

tablica[5][0][0] = ' ';
tablica[5][0][1] = '_';
tablica[5][0][2] = ' ';
tablica[5][1][0] = '|';
tablica[5][1][1] = '_';
tablica[5][1][2] = ' ';
tablica[5][2][0] = ' ';
tablica[5][2][1] = '_';
tablica[5][2][2] = '|';

tablica[6][0][0] = ' ';
tablica[6][0][1] = '_';
tablica[6][0][2] = ' ';
tablica[6][1][0] = '|';
tablica[6][1][1] = '_';
tablica[6][1][2] = ' ';
tablica[6][2][0] = '|';
tablica[6][2][1] = '_';
tablica[6][2][2] = '|';

tablica[7][0][0] = ' ';
tablica[7][0][1] = '_';
tablica[7][0][2] = ' ';
tablica[7][1][0] = ' ';
tablica[7][1][1] = ' ';
tablica[7][1][2] = '|';
tablica[7][2][0] = ' ';
tablica[7][2][1] = ' ';
tablica[7][2][2] = '|';

tablica[8][0][0] = ' ';
tablica[8][0][1] = '_';
tablica[8][0][2] = ' ';
tablica[8][1][0] = '|';
tablica[8][1][1] = '_';
tablica[8][1][2] = '|';
tablica[8][2][0] = '|';
tablica[8][2][1] = '_';
tablica[8][2][2] = '|';

tablica[9][0][0] = ' ';
tablica[9][0][1] = '_';
tablica[9][0][2] = ' ';
tablica[9][1][0] = '|';
tablica[9][1][1] = '_';
tablica[9][1][2] = '|';
tablica[9][2][0] = ' ';
tablica[9][2][1] = '_';
tablica[9][2][2] = '|';


printf("Podaj liczbe jaka chcesz wyswietlic (max 10 cyfr): ");
scanf("%d",&liczba);
dlugosc = sprawdz_dlugosc(liczba);


	while(liczba){
		cyfra[k] = liczba%10;
		liczba = liczba/10;
		k++;
		}


  
 	 for(i = 0; i < dlugosc; i++){
  			tab1[dlugosc - 1 - i] = cyfra[i];
 			}



	for(j = 0; j < 3; j++){ 
			for(k = 0; k < dlugosc ; k++){
					for(i = 0; i < 3; i++){ 
							printf("%c", tablica[tab1[k]][j][i]); 
							} 
					} 
			printf("\n"); 
			} 

return 0;
}
