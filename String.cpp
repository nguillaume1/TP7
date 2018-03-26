String::String(const String& s){ //constructeur par copie
  length_=s.size();
  data_=new char[length_];
  for (int i=0; i<length_;i++){
    data[i]=s[i];
  } 
