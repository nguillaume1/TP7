#ifndef STRING_H
#define LIST_H

class String{
  protected:
    static int max_size_;
    int capacity_;
    int length_;
    char* data_;
    

  public:

  //getters:
    static int max_size();
    int capacity();
    
  //methods:
    bool empty(String* s);

    String(const String& s); //constructeur par copie
    int size() const;
}


  
  //destructeur:
    ~String();
    
    


};

#endif

