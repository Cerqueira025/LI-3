#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"
#include "defines.h"
#include "parser.h"
#include "passengers.h"
#include "users.h"

User* createUser(const char* id, const char* name, const char* email, const char* phone_number,
                int birth_date[3], char sex, const char* passport, const char country_code[2],
                const char* address, int account_creation[6], const char* pay_method, const char* account_status) {
  User* user = (User*)malloc(sizeof(User));
  user->id = strdup(id);
  user->name = strdup(name);
  user->email = strdup(email);
  user->phone_number = strdup(phone_number);
  for (int i = 0; i < 3; i++) {
    user->birth_date[i] = birth_date[i];
  }
  user->sex = sex;
  user->passport = strdup(passport);
  strncpy(user->country_code, country_code, 2);
  user->address = strdup(address);
  for (int i = 0; i < 6; i++) {
    user->account_creation[i] = account_creation[i];
  }
  user->pay_method = strdup(pay_method);
  user->account_status = strdup(account_status);
  user->next = NULL;
  return user;
}

void insertUser(UserTable* table, User* user) {
  int index = return_hash(user->id);
  user->next = table->hash_table[index];
  table->hash_table[index] = user;
}
/*
void freeUser(User* user) {
  free(user->id);
  free(user->name);
  free(user->email);
  free(user->phone_number);
  free(user->passport);
  free(user->address);
  free(user->pay_method);
  free(user->account_status);
  free(user);
}


// Função para liberar a memória alocada para a tabela de hash e usuários
void freeUserTable(UserTable* table) {
  for (int i = 0; i < HASH_SIZE; i++) {
    User* current = table->hash_table[i];
    while (current != NULL) {
      User* temp = current;
      current = current->next;
      freeUser(temp);
    }
  }
}
*/
// Função para buscar um usuário na tabela de hash com base no ID
User* findUser(UserTable* table, char* id) {
  int index = return_hash(id);
  User* current = table->hash_table[index];
  while (current != NULL) {
    if (strcmp(current->id, id) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL; // Usuário não encontrado
}


void printUser(const User* user) {
  if (user == NULL) {
    printf("Usuário inválido\n");
  } else {
    printf("ID: %s\n", user->id);
    printf("Nome: %s\n", user->name);
    printf("Email: %s\n", user->email);
    printf("Número de telefone: %s\n", user->phone_number);
    printf("Data de nascimento: %04d/%02d/%02d\n", user->birth_date[0], user->birth_date[1], user->birth_date[2]);
    printf("Sexo: %c\n", user->sex);
    printf("Passaporte: %s\n", user->passport);
    printf("Código do país: %c%c\n", user->country_code[0], user->country_code[1]);
    printf("Endereço: %s\n", user->address);
    printf("Data de criação da conta: %04d/%02d/%02d %02d:%02d:%02d\n",
           user->account_creation[0], user->account_creation[1], user->account_creation[2],
           user->account_creation[3], user->account_creation[4], user->account_creation[5]);
    printf("Método de pagamento: %s\n", user->pay_method);
    printf("Status da conta: %s\n", user->account_status);
  }
}