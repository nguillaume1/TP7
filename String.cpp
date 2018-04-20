#include "String.h"


//-----GETTERS---------------
int String::capacity() {
  return capacity_;
}

int String::length(){
  return length_;
}

const char* String::data(){
  return data_;
}



//------METHODS--------------
bool String::empty(){
  
  return length_ == 0; //retourne True si le tableau est vide, sinon False
}


void String::reserve(int new_size){
  
  char* new_tab;
  new_tab = new char[new_size]; //creation du nouveau tableau
  
  for (int i=0; i<= length_; i++){
    new_tab[i] = data_[i]; // remplissage du nouveau tableau avec le string
  }
  delete [] data_;
  
  data_ = new_tab;
  capacity_ = new_size;
}


//----------CONSTRUCTEURS-----------

//Définition du constructeur à partir d'une c-string
String::String(char* c_string, int capacite){ 

  // Calcul de la valeur de la longeur
  int i=0;
  while (c_string[i] != '\0'){ // Boucle pour calculer la valeur de la longeur
    ++i;
    length_=i;
  }

  //max_size;
  capacity_= capacite; //Correspond à la taille du string
  data_= c_string ;
}



//Définition de l'opérateur =(char*)
String& String::operator= (const char* c_string){

  //définition de la taille du nouveau string
  int s = 0;
  while(c_string[s] != '\0')
  {
    ++s;
  }

  length_ = s; 

  //définition de la capacité
  if(length_ >= capacity_){
    capacity_ = length_ +1;
  }

  //creation du nouveau tableau et copie des elelements
  char* str;
  str = new char[capacity_];
  for(int i = 0; i < length_; ++i){
    str[i] = c_string[i];
  }

  str[length_] = '\0';
  
  
  
  return *this;    
}


//Definition de l'operateur +(string)
String operator+(const String& lhs, const String& rhs){
  int size = lhs.length_ + rhs.length_;
  
  //creation du nouveau string
  String new_str(lhs.data_, size+1);


  //remplissage du string avec le string de droite
  for (int i = new_str.length_; i < size+1 ; ++i){
    new_str.data_[i] = rhs.data_[i-lhs.length_];
  }

  //Mise a jour des longueurs
  new_str.length_ += rhs.length_;
  new_str.data_[new_str.length_] = '\0';

  return new_str;
}


//---------DESTRUCTEUR-----------
String::~String(){
  delete [] data_;
}



String::String(const String& s){ //constructeur par copie
  length_=s.length_;
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




