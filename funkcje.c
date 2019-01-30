#include "funkcje.h"


// Dodaje element na górę stostu
//
// [POST] *stack - Głowa stosu
// [PRE] liczba - wartość do położenia na stosie
//
// return - zwraca aktualną liczbę elementów na stosie
//
int push(t_head *stack, int liczba)
{
	if(IMPL == 1)
	{	
		t_elem *node = NULL;
		node = (t_elem*)calloc(1,sizeof(t_elem)); 		// alokacja pamięci pod kolejny element lilsty	// calloc inicjuje zerami	
		assert (node != NULL);				// Sprawdzenie poprawności alokacji
		node->wartosc = liczba;					// Uzupelnienie elementu o wartosc int
	
		if(empty(*stack)){
			stack->top = node;
		}else{
			t_elem *ptr_top;					
			ptr_top = stack->top;		// PRzechowanie adresu ostatniego elementu
	
			 node->next = ptr_top;		// Niech aktualny szczyt wskazuje na węzeł, kttóry był do tej pory na top
			 stack->top = node;				// Ustanowienie nowego wierzchołka
		}
	}
	else if(IMPL == 2)
	{
		assert(stack->ile < STACK_LIM);
		
			t_elem *ptr_elem;			// Wskaźnik na strukturę przechowującą
			ptr_elem = stack->top;		// tablicę ze stosem

			ptr_elem->tab[ stack->ile ] = liczba;
		
	}
	
		stack->ile++;					// Inkrementacja licznika elementów
	return stack->ile;			//Zwróc liczbę elementów na stosie
}


// Ściąga topowy element
//
// [POST] *stack - Głowa stosu
// [POST] *out - miejsce na wartość ściągniętą ze stosu
//
// return - 1, gdy ściągnięto element
// return - 0, gdy stos był pusty
//
int pop(t_head *stack, int *out)
{
	if(empty(*stack))
	{
		return 0;		// Zwróć zero, gdy stos jest posty
	}
	else
	{
		if(IMPL == 1)
		{
			t_elem *ptr; 		// Przechowaj adres aktualnego topu
			ptr = stack->top;

			stack->top = ptr->next; 	// drugi element od góry, lub NULL
			
			*out = ptr->wartosc;	// Przed zwolnieniem pamięci - zachowaj wartość 
			free(ptr);	//Uwolnij ostatni element z listy
		}
		else if(IMPL == 2)
		{
			t_elem *ptr_elem;			// Wskaźnik na strukturę przechowującą
			ptr_elem = stack->top;		// tablicę ze stosem

			*out = ptr_elem->tab[ stack->ile-1 ];
			ptr_elem->tab[ stack->ile-1 ] = 0;
		}
		stack->ile--; // Zdekrementuj wartość ilości elementów
	}

	return 1;			//1 gdy ściągnięto element
}


// Sprawdza czy stos jest pusty
// 
// [PRE] stack - Głowa stosu
//
// return 1, gdy tak
// return 0, gdy nie
//
int empty(t_head stack)
{
	if(stack.ile)
		return 0;	// stos nie jest pusty	
	else
		return 1;	// Stos pusty
}

// Wypisz elementy stosu na stdout
// zaczynając od wierzchniego
//
// [PRE] stack - Głowa stosu
// [PRE] ile - elementów wypisać
//		0 == wypisz wszystkie
//
void print(t_head stack, int ile)
{
	if(!empty(stack))	// Sprawdz, czy empty
	{	
		if(IMPL == 1)
		{
			t_elem *ptr; // Wskaźnik do przechowania aktualnego topu
			ptr = stack.top;

			if(!ile){
				ile = stack.ile;
			}

			printf("===top===\n");
			do{
				printf("    %d\n",ptr->wartosc);	
			}while((ptr = ptr->next) && --ile);	// Dopóki ptr->next nie wskazuje na NULL, lub ile == 0			
		}
		else if (IMPL == 2)
		{
			t_elem *ptr_elem;			// Wskaźnik na strukturę przechowującą
			ptr_elem = stack.top;		// tablicę ze stosem

			printf("===top===\n");
			do
			{	
				printf("    %d\n", ptr_elem->tab[ stack.ile-1 ] );
			}while(--stack.ile);	//Dopóki przynajmniej jeden element na stosie
		}
	}
	else
	{
		fprintf(stdout, "%s\n", "Stos jest pusty" );
	}

}

// Inicjuje stos
//
// [POST] *stack - głowa stosu do zainicjowania
// 
void inicjuj(t_head *stack)
{
	if(IMPL == 1)
	{
		stack->top = NULL;
		stack->ile = 0;		
	}
	else if(IMPL == 2)
	{	
		stack->top = NULL;
					// Calloc inicjuje od razu zerami wewnętrz elem (głownie chodzi o tab[])
		stack->top = (t_elem*)calloc(1,sizeof(t_elem));	// Alokacja pamięci pod elem z arrayem
		stack->ile = 0;	
		assert(stack->top != NULL);

	}

}