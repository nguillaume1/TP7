#include <cstdio>
#include "String.h"

const int String::max_size_=100;
//-----------------------------------------GETTERS---------------------------------------------------

int String::capacity() {
  return capacity_;
}


int String::length(){
  return length_;
}

const char* String::data(){
  return data_;
}

int String::max_size(){
  return max_size_;
}


int String::size() const{ //retourne la taille de la chaine de caractère

  return length_;
}

//-----------------------------------------METHODS---------------------------------------------------



//booléen qui retourne True si le tableau est vide, sinon False
bool String::empty(){
  
  return length_ == 0;
}



//change la capacité du tableau du string en creatant un nouveau tableau
void String::reserve(int new_size){
  
  char* new_tab;
  new_tab = new char[new_size]; //creation du nouveau tableau
  
  for (int i=0; i<= length_; i++){
    new_tab[i] = data_[i]; // remplissage du nouveau tableau avec le string
  }
  
  delete this -> data_;
  data_ = new_tab;

  //Mise a jour des longeurs
  capacity_ = new_size;
}



//complete le tableau d'un caractere c, si la valeur de n est supérieure à la capacité
/*
void String::resize (int n, char c){
  char* tmp = new char[n];
  
  if (n >= capacity_){
    this->reserve(int(n-capacity_)+1);
  }

  for (int i=0; i<n; ++i){
    if (i<length_){
      tmp[i]=data_[i];
    }
    else{
      tmp[i]=c;
    }
  }
  length_=n;
  tmp[length_]= '\0';
  delete [] data_;
  data_ = tmp; 
}
*/



//-----------------------------------------SETTERS---------------------------------------------------

// Efface la chaîne de caractères sans modifier la capacité
void String::clear(){
	length_ = 0;
	data_[0] = '\0';
}


// Retourne un pointeur vers un tableau contenant la chaîne de caractère avec un 0 dans la dernière case
const char* String::c_str(){
	return data_;
}



//-----------------------------------------CONSTRUCTEURS--------------------------------------------

//Définition du constructeur à partir d'une c-string
String::String(char * c_string, int capacite){ 

  // Calcul de la valeur de la longeur
  int i=0;
  while (c_string[i] != '\0'){ // Boucle pour calculer la valeur de la longeur
    ++i;
    length_=i;
  }


  capacity_= capacite; //Correspond à la taille du string
  data_= c_string ;
}

//constructeur par défaut
String::String(){
}



/*
//constructeur par copie
String::String(const String& s){ 
  length_=s.length_;
  data_=new char[length_];
  for (int i=0; i<length_;i++){

    data_[i]=s.data_[i];
  } 
  capacity_=s.capacity_;
  max_size_=s.max_size_;
}
*/
//-----------------------------------------OPERATORS = ----------------------------------------------


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


//Définition de l'opérateur =(char)
String& String::operator=(char c){
  char * str;
  str = new char[capacity_];
  str[0]=c;
  str[1]='\0';
  length_=1;
  data_=str;
  
  return *this;
}

/*
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
*/

//-----------------------------------------OPERATORS + ---------------------------------------------

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



/*
String operator+(const String& lhs, const char* rhs){
  String sum_s(lhs);

  int s = 0;
  while(rhs[s] != '\0'){
    ++s;
  }
  
  int sum = sum_s.length_ + s;

  if (sum >= sum_s.capacity_){
    sum_s.reserve(int(sum-sum_s.capacity_) +1);
  }

  for (unsigned int i = sum_s.length_; i<sum; ++i){
    sum_s.data_[i] = rhs[i-sum_s.length_];
  }

  sum_s.length_ = sum;

  sum_s.data_[sum_s.length_] = '\0';
  
  return sum_s;
}
*/


/*
// Retourne un nouveau String dont la valeur correpond à la concaténation de lhs et de rhs
String operator+(const String& lhs,const char* rhs){ 
  
  int sizeCounter = 0;
  for (int i = 0 ; rhs[i] != '\0' ; i++){
    sizeCounter ++;
  }
  String newString = String();
  
  if (lhs.size() + sizeCounter > newString.max_size()){
    printf("Il y a trop de caractères");
  }
	else {
		newString.reserve(lhs.size() + sizeCounter);
    for(size_t i = 0; i < lhs.size(); i++){
      newString.data_[i] = lhs.data_[i];		
    }
    for(size_t i = lhs.size(); i < lhs.size() + sizeCounter; i++){
      newString.data_[i] = rhs[i-lhs.size()];		
    }
    newString.length_ = lhs.size() + sizeCounter;
    newString.data_[newString.size()]='\0';
	}	
	return newString;
}
*/

//-----------------------------------------DESTRUCTEUR----------------------------------------------

String::~String(){
  delete [] data_;
}

