#include "main.h"

//	Autor:				Oskar Legner

int main(void)
{	

	t_head stos;
	inicjuj(&stos);

	short run = 1;		// Warunek pętli while

	while(run)
	{
		int buf1=0, buf2=0; 	// bufory wartości pobranych ze stosu
		int result=0;			// ZMienna przechowująca wyniki
		char znaki[DL_LINII]={0}; //Deklarowana i inicjowana na nowo w kazdym przejsciu petli, wiec pusta
		int liczba=0;

		scanf("%s", znaki); //Czytanie strumienia (dla liczb - zakres int)

		// Jesli ciag znakow zaczyna się od cyfr, to tylko one zostaną przetworzone
		if(		(znaki[0] >= '0' && znaki[0] <= '9') 
			|| ((znaki[1] >= '0' && znaki[1] <= '9') && znaki[0] == '-'))
		{
			liczba = atoi(znaki);			// Zamień chary na liczbę
			push(&stos, liczba);			// Wrzuć liczbę na stos
		}	
		else
		{
			switch(znaki[0])
			{
				case '+':	// Dodawanie
					if (stos.ile > 1) // Jeśli na stosie jest więcej niż 1 liczba
					{
						pop(&stos, &buf1); // Ściągnij ze stosu		
						pop(&stos, &buf2); // Dwie wartosci	
						result = buf2 + buf1;	// Dodaj 
						push(&stos, result); 	// i umieść na szczycie
					}else{
						fprintf(stderr, "%s\n", "Error: Zbyt mało liczb do wykonania operacji" );
					}
					break;

				case '-':	// Odejmowanie
					if (stos.ile > 1) // Jeśli na stosie jest więcej niż 1 liczba
					{
						pop(&stos, &buf1); // Ściągnij ze stosu		
						pop(&stos, &buf2); // Dwie wartosci	
						result = buf2 - buf1;	// Odejmij 
						push(&stos, result); 	// i umieść na szczycie
					}else{
						fprintf(stderr, "%s\n", "Error: Zbyt mało liczb do wykonania operacji" );
					}
					break;

				case '*':	// Mnożenie
					if (stos.ile > 1) // Jeśli na stosie jest więcej niż 1 liczba
					{
						pop(&stos, &buf1); // Ściągnij ze stosu		
						pop(&stos, &buf2); // Dwie wartosci	
						result = buf2 * buf1;	// Pomnóż 
						push(&stos, result); 	// i umieść na szczycie
					}else{
						fprintf(stderr, "%s\n", "Error: Zbyt mało liczb do wykonania operacji" );
					}
					break;

				case '/':	// Dzielenie
					if (stos.ile > 1) // Jeśli na stosie jest więcej niż 1 liczba
					{
						pop(&stos, &buf1); // Ściągnij ze stosu		
						pop(&stos, &buf2); // Dwie wartosci	
						if(buf2)
						{
							result = (int)(buf2 / buf1);	// Podziel 
							push(&stos, result); 	// i umieść na szczycie
						}else{
							fprintf(stderr, "%s\n", "Error: Nie można podzielić przez zero!" );
							push(&stos, buf2);
							push(&stos, buf1);
						}

					}else{
						fprintf(stderr, "%s\n", "Error: Zbyt mało liczb do wykonania operacji" );
					}
					break;

				case 'f':	// Wypisz cały stos
					print(stos,0);			
			 		break; 

				case 'p':	// Wypisz top stosu
					print(stos,1);			
			 		break; 

			 	case 'P':	// Ściągnij element ze stosu
			 		pop(&stos, &buf1);	
			 		break;

				case 'c':	// Wyczyść stos
					while(pop(&stos, &buf1));
			 		break; 

			 	case 'r':	// Reverse (dwa wierchnie elementy)
			 		if(stos.ile > 1){
				 		pop(&stos, &buf1);	// Sciagnij wartość wierzchnię
				 		pop(&stos, &buf2);	// i kolejną

				 		push(&stos, buf1);	// teraz połóż pobrane wartosci
				 		push(&stos, buf2);	// w odwrotnej kolejności na stosie
			 		}else{
			 			fprintf(stderr,"%s\n", "Error: Zbyt malo elementow na stosie." );
			 		}

			 		break;

			 	case 'd':	// Duplikuj wierzchni element
					if(!empty(stos))
					{
						pop(&stos, &buf1); 	// Ściągnij i zapisz wartość do buf1
				 		push(&stos, buf1);	// teraz połóż pobraną wartość
				 		push(&stos, buf1);	// dwukrotnie
					}	
					else
					{
						fprintf(stderr,"%s\n", "Error: Nie ma czego duplikowac" );
					}	
			 		break;

			 	case 'q':	// Zakończ działanie programu
			 		run = 0;
			 			// Przed wyjściem jeszcze wyczyść stos (zapobiega wyciekowi pamięci)
			 			if(IMPL == 1){
			 			while(pop(&stos, &buf1));										
			 			}
			 			else if (IMPL == 2){
			 				free(stos.top);
			 			}

			 		break;

			 	default:
			 		fprintf(stderr,"%s\n", "Error: Nieznane polecenie.");
			}// switch	
		}// else
	}// while

	return 0;
}



//				Testy			dla IMPL = 1
//
//	Dane podawane na stdin:		f p 0 f p P f p q
//							
//	Rezulatat					// Stos jest pusty
								// Stos jest pusty
								// ===top===
								//     0
								// ===top===
								//     0
								// Stos jest pusty
								// Stos jest pusty


//	Dane podawane na stdin:		1 5 4 3 1 2 r + * r / - + p 	Oczekiwane: 4
//  Rezultat: 					
								// ===top===
								//     4



//	Dane podawane na stdin:		1 0 1 2 0 3 0 4 0 P P P P P P P P P f
//  Rezultat: 
								// Stos jest pusty

//	Dane podawane na stdin:		99 221 324 34 138 5398 123 2435 c
//  Rezultat: 					// Stos jest pusty

	
//	Dane podawane na stdin:		-234 235 + p
//  Rezultat: 
								// ===top===
								//     1


//	Dane podawane na stdin:		12342134124 f
//  Rezultat: 
								// ===top===
								//     -542767764
//	Komentarz:					
//								Liczby wykraczające poza zakres int 32 nie są zapisywane poprawnie

//	Dane podawane na stdin:		999999999999999999999 99999999999999999999999 + f 
//  Rezultat: 					
								// ===top===
								//     -2
// Komentarz:
//								Takżę w kontkcie działania na liczbach - wynik wychodzący poza zakres int32 jest źle interpretowany


//	Dane podawane na stdin:		1 0 d f 
//  Rezultat: 
								// ===top===
								//     0
								//     0
								//     1


//	Dane:						Te same działania dla IMPL = 2
//  Rezultat: 					Analogicznie do IMPL = 1

//	Dane:						IMPL = 2, oraz STACK_LIM = 3
//	Dane podawane na stdin:		9 9 9 9
//								
//  Rezultat: 					
								// program: funkcje.c:32: push: 
								// Assertion `stack->ile < STACK_LIM' failed.
								// Przerwane (zrzut pamięci)
// Komentarz:
//								Przepełnienie stosu prowadzi do zamknięcia programu

//
//
//	Wnioski:
//
//		Gdy wprowadzane dane są poprawne, to porgram powinien działać poprawnie.
//		Przy niektórych typach niepoprawnych danych program także powinien sobie poradzić
//		Np. wprowadzenie na stdin 3452dfs1231 umieści na stosie liczbę 3452 - dalsze znaki będą pominięte
//		Ograniczenie maksymalnej długości czytanej linii nie powinno mieć wpływu na działanie programu -
//		- przy ustawieniach domyślnych, tj. DL_LINII = 11, lub większych.
//		W wypadku podawania liczb - te dluższe niż 11-cyfrowe nie będą także mieśćiły się w zakresie int
//		W wypadku podawania innych znaków - w kontekście poleceń: interpretowany jest tylko pierwszy podany znak
//
//
//
//	