#include "String.h"

#include <stdio.h>
#include <iostream>

int main(){

  //Test du constructeur à partir d'une c-string
  String str((char *)"Marie", 8);
  printf ("La longueur de Marie est : %d\n", str.length());
  printf ("La capacité du tableau est : %d\n", str.capacity());
  //printf ("La taille maximale du tableau est : %d\n", str.max_size());
  printf ("Data: %s\n", str.data()); 
  printf ("Max_size:%d\n", str.max_size());
  printf("\nEst ce que le sting est vide? \n 0 = Faux \n 1 = Vrai \n Réponse: %d\n", str.empty());



  /*
  printf("\nTEST RESIZE \n");
  str.resize(10,'b');
  printf("Test resize: %s\n", str.data() );
  */

  /*
  printf("\nTEST RESERVE \n");
  printf("Capacité du tableau avant reserve: %d\n", str.capacity());
  str.reserve(20);
  printf("Capacité du tableau après reserve: %d\n", str.capacity());
  */

  printf("\nTEST OPERATEUR =(char*) \n");
  String str2((char *)"tessssst", 15);

  printf ("Data avant opération: %s\n", str.data()); 
  str = str2;
  printf ("Data apres opération: %s\n\n", str.data()); 

  printf("\nTEST OPERATEUR =(char) \n");
  printf ("Data avant opération: %s\n", str.data()); 
  str='d';
  printf("Data après opération: %s\n", str.data());

  /*
  printf("\nTEST DESTRUCTEUR \n");
  delete &str;
  printf ("La capacité du tableau après destruction est : %d\n", str.capacity());
  */
  
  
  printf("\nTEST OPERATEUR +(sting) \n");
  printf ("string de gauche: %s\n", str.data()); 
  printf ("string de droite: %s\n", str2.data()); 
  String test0 = str+str2;
  printf ("string additionné: %s\n", test0.data()); 
  
  
  /*
  printf("\nTEST OPERATEUR +(char*) \n");
  String test1((char *)"chat", 7);
  char* tableau = "chien";
  String test2 = test1 + tableau;
  printf ("string de gauche: %s\n", test1.data()); 
  printf ("tableau de droite: %s\n", tableau); 
  printf ("string additionné: %s\n", test2.data()); 
  */
  return 0;

}

