#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>


int los(int i){
    return rand()%i;
}
int main (){
srand(time(NULL));
char tab[5][5];
char *tabz=&tab[0][0];
for(int i='a';i<'a'+25;i++,tabz++)
{
	if(i!='j')
		*tabz=i;
	else
		*tabz='z';
}
tabz=&tab[0][0];
std::random_shuffle(tabz,tabz+25,los);
std::string t2;
std::cout<<"Podaj tekst"<<std::endl;
getline(std::cin, t2);
int w= t2.size();
std::cout<<"Zaszyfrowany:"<<std::endl;
for (int t=0; t<w; t++)
{
	for (int i=0; i<5; i++)
	{
	for(int j=0; j<5; j++)
	{
	if(t2[t]=='j')
		t2[t]='i';
	else
		if(t2[t]==tab[i][j])
	{
		std::cout<<i+1<<":"<<j+1<<"  ";
	}
	else
	{
		std::cout<<"";
	}
	}
	}
}
std::cout<<std::endl<<"Tablica:"<<std::endl;
for(int i=0;i<5;i++)
{
    for(int j=0;j<5;j++)
	{
    	std::cout<<tab[i][j]<<" ";
	}
    std::cout<<std::endl;
}
std::cout<<"Odszyfrowany:"<<std::endl;
for (int t=0; t<w; t++)
{
	for (int i=0; i<5; i++)
	{
	for(int j=0; j<5; j++)
	{
	if(t2[t]=='j')
		t2[t]='i';
	else
		if(t2[t]==tab[i][j])
		{
		std::cout<<tab[i][j];
		}
		else
		{
		std::cout<<"";
		}
	}
	}
	if(t2[t]==' ')
	{
	std::cout << " ";
	}
}
}
