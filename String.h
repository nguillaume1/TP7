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

  //getters:
    static int max_size();
    int capacity();
    
  //methods:
    bool empty(String* s);
    String(const String& s); //constructeur par copie

    int size() const;
    String& operator=(const String& s);
};


  
  //destructeur:
    ~String();
    
    


};

#endif

