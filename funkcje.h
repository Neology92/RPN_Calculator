#ifndef FUNKCJE_H
#define FUNKCJE_H


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define	DL_LINII 11 	// maksymalna wczytywana (+ znak konca linii)
#define STACK_LIM 100	// maks ilość liczb na stosie (przy implementacji tablicowej - 2)
#define IMPL 1		// 1 - listowa, 2 - tablicowa 



typedef struct t_elem	
{
	int tab[STACK_LIM];
	struct t_elem *next;
	int wartosc;
}t_elem;


typedef struct t_head	// Zdefiniowanie głowy 
{
	t_elem *top;
	int ile;
}t_head;


int push(t_head*, int);
int pop(t_head*, int*);
int empty(t_head);
void print(t_head, int);
void inicjuj(t_head*);

#endif /* FUNKCJE_H */