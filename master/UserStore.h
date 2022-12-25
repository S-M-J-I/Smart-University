#ifndef USERSTORE_H
#define USERSTORE_H

class User{
public:
  String studentName;
  int id;

  User(){}


  User(String studentName, int id){
    this->studentName = studentName;
    this->id = id;
  }
};

#endif
