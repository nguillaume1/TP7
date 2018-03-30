#include "String.h"
#include <iostream>

int main() {
  //test de Hello world
  std::cout << "Hello World!" << std::endl;
  //Tests
  String test; //test du constructeur par defaut
  String test2(test); // test du constructeur par copie
  
  return 0;
}
