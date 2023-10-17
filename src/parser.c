#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"
#include "defines.h"
#include "parser.h"
#include "passengers.h"
#include "users.h"


int return_hash(char* user_id) {
  int total = 0;
  for(int i=0;user_id[i];i++) {
    total+=user_id[i];
    total*=user_id[i];
  }
  return total;
}

void readUsersFromFile(UserTable* table, const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo %s\n", filename);
    return;
  }

  char buffer[MAX_USER_LENGTH];
  int n_users = 0;

  while (fgets(buffer, MAX_USER_LENGTH, file) != NULL) {
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

    insertUser(table, &temp_user); // Inserir o usuário na tabela hash
    n_users++;
  }
  fclose(file);
}
//	id;name;email;phone_number;birth_date;sex;passport;country_code;address;account_creation;pay_method;account_status
