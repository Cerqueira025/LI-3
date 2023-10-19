#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"
#include "defines.h"
#include "parser.h"
#include "passengers.h"
#include "users.h"


int main() {
  UserTable userTable;
  for (int i = 0; i < HASH_SIZE; i++) {
    userTable.hash_table[i] = NULL;
  }
  memset(userTable.hash_table, 0, sizeof(userTable.hash_table));
  // Lê os usuários do arquivo CSV e insere na tabela de hash
  readUsersFromFile(&userTable, "users.csv");

  char* userIdToPrint = "AlícSá-Mendes";
  User* userToPrint = findUser(&userTable, userIdToPrint);

if (userToPrint != NULL) {
    printUser(userToPrint);
} else {
    printf("Usuário com ID %s não encontrado\n", userIdToPrint);
}
  // Libere a memória alocada
  freeUserTable(&userTable);

  return 0;
}