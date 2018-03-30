
#include "String.h"

//getters
int String::capacity() {
  return capacity_;
}


//methods
bool String::empty(String* s){
  if (&s == '\0'){
    return true;
  }
  else{
    return false;
  }
}



