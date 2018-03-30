#ifndef STRING_H
#define STRING_H

class String{
  protected:
    static int max_size_;
    int capacity_;
    int length_;
    char* data_;
    
  public:
   //constructeurs
    String();//constructeur par défaut
    String(const String& s); //constructeur par copie

  //getters:
    static int max_size();
    int capacity();
    int size() const;
    const char* c_str();
    
    
  //methodes:
    bool empty(String* s);
    

   //Opérateurs 
    String& operator=(const String& s);
    friend String operator+(const String& , const char* );
    

  //destructeur:
    ~String();
    

};

#endif

