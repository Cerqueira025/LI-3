#ifndef USERS_H
#define USERS_H

//typedef struct users user;
typedef struct User {
  char* id;
  char* name;
  char* email;
  char* phone_number; //atenção ao formato
  char* birth_date; //aaaa/MM/dd -> [aaaa,MM,dd]
  char* sex;
  char* passport;
  char* country_code; //atenção /0
  char* address;
  char* account_creation;
  char* pay_method;
  char* account_status;
} User;


struct User* newUser(char* id, char* name, char* email, char* phone_number, char* birth_date, 
                    char* sex, char* passport, char* country_code, char* address, 
                    char* account_creation, char* pay_method, char* account_status);
void freeUser(User* user);
void printUser(const User* user);

#endif