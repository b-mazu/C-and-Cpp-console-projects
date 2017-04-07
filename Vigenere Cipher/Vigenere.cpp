#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
int i=0,j=0,k;
char dane[100],haslo[100];

printf("Podaj tekst do zaszyfrowania: ");
fgets(dane,100,stdin);
printf("\nPodaj haslo: ");
fgets(haslo,100,stdin);
while(haslo[i]!=10)
    {
        if(islower(haslo[i]))
        haslo[i]=toupper(haslo[i]);
        i++;
    }
            
	k=i;
    i=0;
    while(dane[i]!=10)
        {
        	if(islower(dane[i]))
            dane[i]=toupper(dane[i]);
            
			if(j<k)
                {
                	if(dane[i]==32) dane[i]=32;
                	else
                    if(haslo[j]+dane[i]-65<='Z')
                    dane[i]=haslo[j]+dane[i]-65;
                    else
                    dane[i]=haslo[j]+dane[i]-65-26;
                }
                    else
                        {
                            j=0;
                            continue;
                        }
                            i++;
                            j++;
        }
             
	printf("\nTekst po zaszyfrowaniu: %s",dane);

i=0;    
j=0;

printf("\nPodaj tekst do odszyfrowania: ");
fgets(dane,100,stdin);
printf("\nPodaj haslo: ");
fgets(haslo,100,stdin);
while(haslo[i]!=10)
    {	
    	if(haslo[i]==32) haslo[i]=32;
    	else
        if(islower(haslo[i]))
        haslo[i]=toupper(haslo[i]);
        i++;
    }
             
	k=i;
    i=0;
    while(dane[i]!=10)
        {
        	if(haslo[i]==32) haslo[i]=32;
    		else
            if(islower(dane[i]))
            dane[i]=toupper(dane[i]);
            
			if(j<k)
            {
            	if(dane[i]==32) dane[i]=32; 
            	else
                if(dane[i]-haslo[j]+65>='A')
                dane[i]=dane[i]-haslo[j]+65;
                else
                dane[i]=dane[i]-haslo[j]+65+26;
            }
                else
                    {
                        j=0;
                        continue;
                    }
                        i++;
                        j++;
        }
             
	printf("\nTekst po odszyfrowaniu: %s",dane);
         
system("pause");
return 0;
}
