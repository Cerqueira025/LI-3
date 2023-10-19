#ifndef USERS_H
#define USERS_H

//typedef struct users user;
typedef struct User {
  char* id;
  char* name;
  char* email;
  char* phone_number; //atenção ao formato
  int birth_date[3]; //aaaa/MM/dd -> [aaaa,MM,dd]
  char sex;
  char* passport;
  char* country_code; //atenção /0
  char* address;
  int account_creation[6];
  char* pay_method;
  char* account_status;
  struct User* next;
} User;

typedef struct UserTable {
  User* hash_table[HASH_SIZE];
} UserTable;

User* createUser(const char* id, const char* name, const char* email, const char* phone_number,
                int birth_date[3], char sex, const char* passport, const char country_code[2],
                const char* address, int account_creation[6], const char* pay_method, const char* account_status);

void insertUser(UserTable* table, User* user);
void freeUser(User* user);
void freeUserTable(UserTable* table);
User* findUser(UserTable* table, char* id);
void printUser(const User* user);

#endif