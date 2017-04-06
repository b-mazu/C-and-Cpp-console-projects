#include <stdio.h>
#include <stdlib.h>

struct list{
        int a;
     struct list *nastep;
     struct list *poprz;
       };
 struct list *head;
struct list *tail;


void print(struct list*,int);
struct list* stworz(int*);
void inject (struct list *, int*);
void push (struct list **, int);
void eject(struct list*);
int rear (struct list*);
int front (struct list*);
void pop (struct list**);


   int main(){
    	int size,d,*c;
	struct list *punkt;
	c=&size;

	printf("\n Podaj ilosc elementow z ktorych bedzie skladac sie twoja lista\n");
	scanf("%d",&size);
	punkt=stworz(c);

		while(d>=0){
		printf(" 0-drukowanie listy\
      \n 1- pobranie lewego konca listy\
      \n 2-wstawienie elementu na lewy koniec listy\
      \n 3-usuniecie biezacego konca listy\
      \n 4-pobieranie prawego konca listy\
      \n 5-wstawienie elementu x na prawy koniec listy\
      \n 6-usuniecie biezacego prawego konca listy\
      \n 7-zakonczenie programu\n");
      scanf("%d",&d);
switch(d){
          int i;
          case 0:
				print(head,size);
				break;

          case 1:
               printf("%d\n", front(punkt));
               break;

          case 2:

               printf("podaj wartosc:\n");
               scanf ("%d", &i);
               push(&punkt, i);
               break;
          case 3:
               pop(&punkt);
               break;
          case 4:
               printf("%d\n", rear(punkt));
               break;
          case 5:
                printf("podaj wartosc:\n");
               scanf ("%d", &i);
               inject(tail,c);
               break;
          case 6:
               eject(punkt);
               break;
        	case 7:
				printf("\n Bye =)");
				return 0;
          }
}



getchar();

return 0;

}

struct list* stworz(int* size){

	struct list * wsk;
	int i,check;

	check=*size;
	wsk=(struct list*)malloc(sizeof(struct list));
	wsk->poprz=NULL;
	wsk->nastep=NULL;
	printf("\n Wprowadz liczbe:\n");
	scanf("%d",&wsk->a);
	head=wsk;
	tail=wsk;
	for (i=1;i<check;i++)
		inject(wsk,size);
	return wsk;
}
void inject(struct list* wczesniejszy,int*size){

	if(wczesniejszy->nastep){
		inject(wczesniejszy->nastep,size);

		}

	else{

	struct list *new;

	new=(struct list*)malloc(sizeof(struct list));

	printf("\n Wprowadz liczbe:\n");
	scanf("%d",&new->a);

	new->nastep=NULL;
	new->poprz=wczesniejszy;
	wczesniejszy->nastep=new;
	tail=new;
	if((*size)==1)
		head=new;


	}
}
void print(struct list* wsk, int size){
	int i;
	printf("\n\n ");

	if(size){
	printf("Elementy listy:\n");
		for (i=0;i<size;i++){

			printf(" %d ",wsk->a);
			wsk=wsk->nastep;

		}
	}

	else
		printf("Lista jest pusta");
	printf("\n\n ");
}

void push (struct list **nastep, int n){
   struct list *w = (struct list *) malloc(sizeof(struct list));
          (*w).poprz=NULL;
          (*w).nastep=*nastep;
          (*w).a = n;
          (**nastep).poprz=w;
          *nastep=w;
          }

void eject (struct list* w){
 if(((*w).nastep==0)&&((*w).poprz==0)){
                   printf("nie mozna usunac elementu: lista musi posiadac co najmniej jeden element\n");
                   return;}
 if((*w).nastep) eject((*w).nastep);
 else {
      (*(*w).poprz).nastep=NULL;
      free(w);
      }
}

int rear (struct list *w){
  if((*w).nastep) return rear ((*w).nastep);
 else {
      return (*w).a;

}
}

int front (struct list *w){
  if((*w).poprz) return front ((*w).poprz);
 else {
      return (*w).a;

}
}

void pop (struct list** w){

 if (((**w).poprz==0) && ((**w).nastep==0)){
                   printf("nie mozna usunac elementu: lista musi posiadac co najmniej jeden element\n");
                   return;}
 if((**w).poprz) pop (&(**w).poprz);
 else {
      struct list *tmp = *w;
      *w=(*tmp).nastep;
      (*(*tmp).nastep).poprz=NULL;
      free(tmp);
      }
}


