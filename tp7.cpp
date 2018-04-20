#include "String.h"
#include <stdio.h>

int main(){

//Test du constructeur à partir d'une c-string
char* tableau;
tableau=new char[8];
tableau="Marie";
String str(tableau, 8);
printf ("La longueur de Marie est : %d\n", str.length());
printf ("La capacité du tableau est : %d\n", str.capacity());
//printf ("La taille maximale du tableau est : %d\n", str.max_size());
printf ("Data: %s\n", str.data()); 
printf("\nEst ce que le sting est vide? \n 0 = Faux \n 1 = Vrai \n Réponse: %d\n", str.empty());


/*printf("\nTEST RESERVE \n");
printf("Capacité du tableau avant reserve: %d\n", str.capacity());
str.reserve(20);
printf("Capacité du tableau après reserve: %d\n", str.capacity());
*/

printf("\nTEST OPERATEUR =(char*) \n");
char* tableau2;
tableau2=new char[15];
tableau2="Super Cloe";
String str2(tableau2, 15);

printf ("Data avant operateur: %s\n", str.data()); 
str = str2;
printf ("Data apres operateur: %s\n", str.data()); 



printf("\nTEST OPERATEUR +(sting) \n");
String test0(str+str2);
printf ("Data: %s\n", test0.data()); 



printf("resize: %s\n", str.resize(4));

//test de Hello world
  //std::cout << "Hello World!" << std::endl;
  //Tests
  String test(); //test du constructeur par defaut
  String test2(test); // test du constructeur par copie*/
  
  return 0;
  

}

