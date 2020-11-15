#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// Array che conterranno i valori delle varie stringhe
char Str_iniz [128];
char Key [128];
char Str_cript [128];
char Str_decr [128];

int main()
{

  int i;
  char choice;
  time_t t;
  srand((unsigned) time(&t)); // Generazione di caratteri casuali

  printf("Inserire un testo da cifrare di lunghezza massima 128 caratteri\nATTENZIONE: I caratteri eccedenti non verranno considerati:\n");
  fgets(Str_iniz, 128, stdin); // Inserisco la stringa digitata dall'utente nell'array

  printf("La stringa inserita contiene %lu caratteri\n", strlen(Str_iniz) - 1); //mostro all'utente la lunghezza del testo inserito

  int counter = 0; // Inserisco la variabile di controllo
  do{

   printf("Scelga una delle seguenti opzioni:\n0: Terminare programma\n1: Inserire manualmente una chiave di cifratura\n2: Generare casualmente una chiave di cifratura\n");
   scanf("%c", &choice);

   switch (choice) //Distinguo le 3 scelte possibili
     {
     case '0':
     printf("Ha deciso di terminare il programma\nArrivederci");
     counter = 1;
     break;

     case '1': // Chiedo all'utente di digitare una chiave di cifratura
     printf("Digitare una chiave che abbia caratteri maggiori o uguali a quelli della Stringa iniziale:\n");
     fgets(Key, 128, stdin);
     counter = 1;
     break;

     case '2': // Genero una chiave di cifratura casuale
     printf("La chiave é:\n");
     for (i= 0; i < strlen(Str_iniz)-1; i++)
      {
      Key[i] = (rand()%96)+32; // Escludo i caratteri che possono causare problemi
      printf("%c", Key[i]);
      }
     counter = 1;
     break;

     }
  char c;
  while((c= getchar()) != '\n' && c != EOF);  //pulisco il buffer

    }while(!counter); // Utilizzo do-while in modo da ripetere l domanda in caso vengano inseriti numeri diversi da 0,1,2


    printf("\nLa stringa cifrata è:\n" );
    for (i = 0; i < strlen(Str_iniz) - 1; i++)
      {
      Str_cript[i] = Str_iniz[i] ^ Key[i]; // Tramite lo XOR cifro la stringa
      printf("%c", Str_cript[i]); // Stampo la stringa cifrata
      }
    printf("\nLa stringa decifrata è:\n");
    for (i = 0; i < strlen(Str_iniz) - 1; i++)
      {
      Str_decr[i] = Str_cript[i] ^ Key[i];// Tramite lo XOR decifro la stringa
      printf("%c", Str_decr[i]);// Stampo la stringa decifrata
      }
}
