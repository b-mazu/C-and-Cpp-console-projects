#include <stdio.h>
#include <stdlib.h>

struct node{
	int id;//klucz
	int typ;
	struct node *p;//rodzic
    struct node *l;//lewe dziecko
    struct node *r;//prawe dziecko
    //wezel to jest wskaznik
};

struct node* plus(int, struct node*);
struct node  * delete(struct node*,int); 
struct node  * del(struct node*, struct node*  ); 
struct node* find(int, struct node*);
void druk(struct node*);


int main(){
	struct node* root=NULL;	//wzskaznik na korzen
	int opcja,wartosc;



do{	
	
	printf("1-Dodaj element do drzewa\n");	
	printf("2-Drukuj drzewo\n");
	printf("3-Szukaj elementu w drzewie\n");
	printf("4-Usun element z drzewa\n");	
	printf("5-KONIEC?\n");
	here:{
		printf("\nWYBIERZ OPCJE:");
		if(scanf("%d",&opcja));
		else{
			printf("ERROR: blad wprowadzania do menu\n");
			getchar();
			goto here;
		}
	}
	switch(opcja){
		case 1:
			printf("podaj wartosc:");
			//je¿eli nieprawid³owa wartoœæ to zakomunikuj
			if(!scanf("%d",&wartosc))
				printf("ERROR: wartosc nie jest liczba\n");
			else
				//je¿eli istnieje ju¿ ta wartosc to zakomunikuj
				if(find(wartosc,root))//wywolywana funkcja find
					printf("ERROR: podana wartosc jest juz dodana\n");
				else
					root=plus(wartosc,root);
			break;
		case 2:
			if(root!=NULL)
				druk(root);
			else
				printf("ERROR: drzewo puste\n");
			break;
		case 3:
			if(root!=NULL){
				printf("podaj wartosc:");
				if(!scanf("%d",&wartosc)){
					printf("ERROR: wartosc nie jest liczba\n");
					getchar();
					}
				else	
					if(find(wartosc,root))
						printf("Wartosc jest w drzewie\n");
					else
						printf("Wartosci nie ma w drzewie\n");
			}
			else
				printf("ERROR: drzewo puste\n");						
			break;
	 case 4: 
         if (root!=NULL){ 
            printf("\nPodaj dane do usuniecia:"); 
            scanf("%d", &wartosc); 
            root=delete(root,wartosc); 
        } 
        else
            printf("\nDrzewo puste"); 
           break; 					
		case 5:
			printf("BYE");
			return 0;			
		default:
			printf("ERROR: Nie ma takiej opcji\n");
			break;
	}
}while(opcja!=5);

return 0;
}

struct node *a; 

struct node  * del(struct node *b, struct node *d ) 
{ 
  if(b->r!=NULL) b->r=del(b->r,d); 
  else
  { 
    d->id=b->id; 
    d=b; 
    b=b->l; 
    free(d); 
   } 
   return b; 
 } 

struct node  * delete(struct node *p, int c) 
{ 
   
 if(p==NULL) 
 printf("\nKlucza %d nie ma  w drzewie", c); 
 else
   if (c<p->id) p->l=delete(p->l, c); 
 else
   if(c>p->id) p->r=delete(p->r,c); 
 else
   { 
    a=p; 
    if (a->r==NULL){ 
      p=a->l; 
      free(a); 
      } 
    else
       if (a->l==NULL){ 
           p=a->r; 
           free(a); 
        } 
    else
     a->l=del(a->l,a);  
   } 
   return p; 
} 



struct node* plus(int x, struct node* wezel){//przekazujesz mu wartosc do dodania i korzen
//je¿eli nie istnieje korzen, to go stworz
	if(wezel==NULL){
		struct node* root;//tworzenie korzenia
		root=(struct node*)malloc(sizeof(struct node));							
		root->id=x;//przypiane wartosc x do klucza
		root->l=root->r=root->p=NULL;//zerujesz wskaznik na dzieci i ustawiasz typ 0
		root->typ=0;
		return root;
	}
	//je¿eli korzen istnieje to:
	else{
			//je¿eli wartosc x jest mniejsza od watosci dla korzenia idz do lewego poddrzewa
		if(x<wezel->id){//jesli ta wartosc ktora chcesz dodac jest mniejszy od twoja ocja.
			//jeœli lewe poddrzewo istnieje to wywo³aj dla niego rekurencynie fuknkcje dodawania elementu
			if(wezel->l!=NULL)
				plus(x,wezel->l);//wywolanie funkcji rekurancyjnie ze wskaznikiem na nowy element
				//w przeciwnym wypadku stwórz lewe poddrzewo z podan¹ wartoœci¹
			else{
				struct node* lewy;//tworzenie nowego lewego elementu
				lewy=(struct node*)malloc(sizeof(struct node));
				lewy->typ=-1;
				lewy->id=x;//zapisywanie wartosci lewego elementu na klucza
				lewy->l=lewy->r=NULL;//zerowanie wskaznikow bo jest nowy
				lewy->p=wezel;//podpisujesz wskaznik na rodzica
				wezel->l=lewy;//u rodzica podpisujesz wskaznik na lewy
			}
		}
			//je¿eli wart x jest >= od wartosci dla korzenia idz do prawego poddrzewa
		else
		//jezeli prawe poddrzewo istnieje to wywolaj dla niego funkcje rekurencyjnie dodawania elementu
			if(wezel->r!=NULL)
				plus(x,wezel->r);
				//w przeciwnym wypadku stwórz prawe poddrzewo
			else{
				struct node* prawy;
				prawy=(struct node*)malloc(sizeof(struct node));
				prawy->typ=1;				
				wezel->r=prawy;
				prawy->id=x;
				prawy->l=prawy->r=NULL;
				prawy->p=wezel;
				wezel->p=prawy;			
			}			
	}
	
return wezel;
}
//znajdz czy wartosc wystepuje w drzewie
struct node* find(int x, struct node* wezel){
	//je¿eli wêze³ nie istnieje, to zwróæ NULL
	if(wezel==NULL)
		return NULL;
	//w przeciwnym wypadku:	
	else{
		//jeœli wartoœci wêz³a i szukanej s¹ równe, to zwróæ wêze³
		if(wezel->id==x)//jestes korzeniem funkcja rekurencyjnie
			return wezel;
				//je¿eli nie s¹ równe to:
		else
			//je¿eli wartoœæ szukanej jest mniejsza ni¿ wêz³a to wywo³aj rekurencjê dla lewego poddrzewa
			if(x<wezel->id)//jesli x jest mniejszy od bierzacego wezla 
				find(x,wezel->l);//wywolanie funkcji find z tym bierzacym element do zalezenia i wskaznikiem na lewego syna
				//w przeciwnym wypadku wywo³aj rekurencjê dla prawego poddrzewa	
			else
				find(x,wezel->r);
	}
}

void druk(struct node* wezel){
	if(wezel!=NULL){
	druk(wezel->l);
	printf("%d %d\n",wezel->id,wezel->typ);
	druk(wezel->r);
	}
}
