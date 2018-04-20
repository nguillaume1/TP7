#ifndef STRING_H
#define LIST_H

#include <cstdio>
#include <cstdlib>

class String{

  friend String operator+(const String& lhs, const String& rhs);

  protected:
    static int max_size_;
    int capacity_;
    int length_;
    char* data_;
    

  public:
  // Constructeur à partir d'une c-string
    String(char* c_string, int capacite );

  //GETTERS:
    static int max_size();
    int capacity();
    int length();
    const char* data();
    
  //METHODS:
    bool empty();

    String(const String& s); //constructeur par copie
    int size() const;

    void reserve(int new_size=0);

  
  //DESTRUCTOR:
    ~String();
    
  //OPERATEURS:
    String& operator= (const char* c_string);
    
    

};

String operator+(const String& lhs, const String& rhs);


#endif

