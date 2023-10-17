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
  memset(userTable.hash_table, 0, sizeof(userTable.hash_table));
  // Lê os usuários do arquivo CSV e insere na tabela de hash
  readUsersFromFile(&userTable, "users.csv");

  // Libere a memória alocada
  //freeUserTable(&userTable);
  /*void loadUsersFromFile() {
  FILE *file = fopen("users.csv", "r");
  if (file == NULL) {
    printf("Failed to open the file.\n");
    return;
  }

  char buffer[MAX_USER_LENGTH];
  User* user_list = NULL;
  int n_users = 0;

  while (fgets(buffer, MAX_USER_LENGTH, file) != NULL) {
    // Aloque espaço para um novo usuário
    User* temp = (User*)realloc(user_list, (n_users+1) * sizeof(User));
      if (temp == NULL) {
        printf("Memory allocation failed.\n");
        break;
      }
      user_list = temp;

    User temp_user;
    sscanf(buffer, "%[^;]%[^;]%[^;]%[^;]%d/%d/%d;%c;%[^;]%[^;]%[^;]%d/%d/%d %d:%d:%d;%[^;],%[^;]",
           temp_user.id, temp_user.name,
           temp_user.email, temp_user.phone_number,
           &temp_user.birth_date[0], &temp_user.birth_date[1], 
           &temp_user.birth_date[2], &temp_user.sex,
           temp_user.passport, temp_user.country_code,
           temp_user.address, &temp_user.account_creation[0],
           &temp_user.account_creation[1], &temp_user.account_creation[2],
           &temp_user.account_creation[3], &temp_user.account_creation[4],
           &temp_user.account_creation[5], temp_user.pay_method, 
           temp_user.account_status);

    temp_user.name = strdup(temp_user.name);
    temp_user.email = strdup(temp_user.email);
    temp_user.address = strdup(temp_user.address);

    user_list[return_hash(temp_user.id)] = temp_user;
    n_users++;
  }
  fclose(file);
}
*/
const char* userIdToPrint = "AlícSá-Mendes";
User* userToPrint = findUser(&userTable, userIdToPrint);

if (userToPrint != NULL) {
    printUser(userToPrint);
} else {
    printf("Usuário com ID %s não encontrado\n", userIdToPrint);
}

  return 0;
}