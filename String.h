#ifndef STRING_H
#define STRING_H

#include <cstdio>
#include <cstdlib>

class String{

  friend String operator+(const String& lhs, const String& rhs);
  //friend String operator+(const String& lhs, const char* rhs);

  protected:
    static const int max_size_;
    int capacity_;
    int length_;
    char* data_;
    
  public:

  //----------CONSTRUCTORS-------------
    String(char* c_string, int capacite ); // Constructeur à partir d'une c-string
    String();//constructeur par défaut
    String(const String& s); //constructeur par copie


  //------------GETTERS-----------------
    int max_size();
    int capacity();
    int length();
    const char* data();
    const char* c_str();
    
    
    
  //-----------METHODS--------------------
    bool empty();
    int size() const;
    void reserve(int new_size);
    void resize(int n, char c = '\0'); 
  
  //----------DESTRUCTOR------------------
    ~String();
    
    
    
  //----------OPERATEURS------------------
    String& operator= (const char* c_string);
    String& operator=(char c);
    //String& operator=(const String& s);
    //friend String operator+(const String& , const char* );
    

    
  //----------SETTERS---------------------
    void clear();
    


};

String operator+(const String& lhs, const String& rhs);
//String operator+(const String& lhs, const char* rhs); 

#endif

