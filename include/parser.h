#ifndef PARSER_H
#define PARSER_H
#include "users.h"

int return_hash(char* user_id);
void readUsersFromFile(UserTable* table, const char* filename);

//void loadUsersFromFile();

#endif