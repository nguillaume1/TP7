
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


//CONSTRUCTEURS


String::String(const String& s){ //constructeur par copie
  length_=s.size();
  data_=new char[length_];
  for (int i=0; i<length_;i++){
    data[i]=s[i];
  } 






int String::size() const{ //retourne la taille de la chaine de caractère
  return length;
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
		while(s.tab_[i]!= '\0'){
			if(s.tab_[i]!=this->tab_[i]){
				equal = false;
			}
			i++;
		}
	}
	
	//Si les deux chaînes sont différentes, la fonction agit.
	
	if(equal==false){
		length_ = s.length_;
		capacity_ = s.capacity_;
		delete[] tab_;
		tab_ = new char[capacity_ + 1];
		for(size_t i = 0; i<length_; i++){
			tab_[i] = s.tab_[i];
		}
	}
	
	else{
		printf("Les deux chaînes sont identiques.\n"); 
	}
	
	return *this;
}


