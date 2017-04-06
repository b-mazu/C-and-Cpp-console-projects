#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 
int main()
{
char tekst[100]; 
int x; 
int i;
printf("Podaj tekst do zaszyfrowania\n");
gets(tekst); 
printf("Podaj wspolczynnik przesuniecia\n");
scanf("%d",&x); 
printf("Zaszyfrowany tekst to:\n");
for(i=0;i<=strlen(tekst);i++){  
if(tekst[i]==32) tekst[i]=32; 
else if(tekst[i]<=64 || tekst[i]>=91 && tekst[i]<=96 || tekst[i]>=123) continue; 
if(tekst[i]>=65 && tekst[i]<=90-x) tekst[i]=(tekst[i])+x; 
if(tekst[i]>=91-x && tekst[i]<=90) tekst[i]=(tekst[i])-26+x; 
if(tekst[i]>=97 && tekst[i]<=122-x) tekst[i]=(tekst[i])+x; 
if(tekst[i]>=123-x && tekst[i]<=122) tekst[i]=(tekst[i])-26+x; 
else if(tekst[i]=='.') break;
else if(tekst[i]=='!') break;
else if(tekst[i]=='?') break;
printf("%c",tekst[i]);
}
printf("\n");
system("PAUSE");
 
return 0;
}
