#include <cstdio>
#include "String.h"

//getters
int String::capacity() {
  return capacity_;
}

int String::size() const{ //retourne la taille de la chaine de caractère
  return length_;
}

// Retourne un pointeur vers un tableau contenant la chaîne de caractère avec un 0 dans la dernière case
const char* String::c_str(){
	return data_;
}


//METHODES
bool String::empty(String* s){
  if (&s == '\0'){
    return true;
  }
  else{
    return false;
  }
}


//CONSTRUCTEURS
String::String(){
}

String::String(const String& s){ //constructeur par copie
  length_=s.size();
  data_=new char[length_];
  for (int i=0; i<length_;i++){
    data_[i]=s.data_[i];
  }
} 



// Remplace la chaîne par une copie de la chaîne s passée en paramètre
// Si *this et s correspondent au même objet, la fonction n'a pas d'effet.
String& String::operator=(const String& s){

  //On commence par vérifier que les deux chaînes sont différentes
	
	bool equal = true;
	if(this->length_ != s.length_ or this->capacity_ != s.capacity_){
		equal = false;
	}
	else{
		int i = 0;
		while(s.data_[i]!= '\0'){
			if(s.data_[i]!=this->data_[i]){
				equal = false;
			}
			i++;
		}
	}
	
	//Si les deux chaînes sont différentes, la fonction agit.
	
	if(equal==false){
		length_ = s.length_;
		capacity_ = s.capacity_;
		delete[] data_;
		data_ = new char[capacity_ + 1];
		for(int i = 0; i<length_; i++){
			data_[i] = s.data_[i];
		}
	}
	
	else{
		printf("Les deux chaînes sont identiques.\n"); 
	}
	return *this;
}

