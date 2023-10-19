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

/*void readUsersFromFile(UserTable* table, const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo %s\n", filename);
    return;
  }

  char buffer[MAX_USER_LENGTH];
  int n_users = 0;

  while (fgets(buffer, MAX_USER_LENGTH, file) != NULL) {
    User* u;
    // Allocate memory for each string field
    u->id = (char*)malloc(100);
    u->name = (char*)malloc(100);
    u->email = (char*)malloc(100);
    u->phone_number = (char*)malloc(100);
    u->passport = (char*)malloc(100);
    u->country_code = (char*)malloc(100);
    u->address = (char*)malloc(1000);
    u->pay_method = (char*)malloc(100);
    u->account_status = (char*)malloc(100);

    if (!u->id || !u->name || !u->email || !u->phone_number || !u->passport || !u->country_code || !u->address || !u->pay_method || !u->account_status) {
      printf("Memory allocation failed\n");
      fclose(file);
      return;
    }

    if (sscanf(buffer, "%99[^;];%99[^;];%99[^;];%99[^;];%d/%d/%d;%c;%99[^;];%99[^;];%999[^;];%d/%d/%d %d:%d:%d;%99[^;];%99[^;]",
        u->id, u->name, u->email, u->phone_number, &u->birth_date[0], &u->birth_date[1], &u->birth_date[2],
        &u->sex, u->passport, u->country_code, u->address,
        &u->account_creation[0], &u->account_creation[1], &u->account_creation[2], &u->account_creation[3], &u->account_creation[4], &u->account_creation[5],
        u->pay_method, u->account_status)){


    // Aloca memória dinamicamente para campos de string
    u->name = strdup(u->name);
    u->email = strdup(u->email);
    u->address = strdup(u->address);

    // Cria um novo usuário com os valores copiados
    User* new_user = createUser(u->id, u->name, u->email, u->phone_number,
                               u->birth_date, u->sex, u->passport, u->country_code,
                               u->address, u->account_creation, u->pay_method, u->account_status);

    // Insere o novo usuário na tabela hash
    insertUser(table, new_user);

    // Liberta a memória alocada para temp_user
    freeUser(u);

    n_users++;
                        }
  }
  fclose(file);
}*/

void readUsersFromFile(UserTable* table, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char buffer[1000];
    User user_list[10000]; // Declare an array of user structs
    int n = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        User* u= &user_list[n]; // Get a pointer to the current user struct

        // Allocate memory for each string field
        u->id = (char*)malloc(100);
        u->name = (char*)malloc(100);
        u->email = (char*)malloc(100);
        u->phone_number = (char*)malloc(100);
        u->passport = (char*)malloc(100);
        u->country_code = (char*)malloc(4);
        u->address = (char*)malloc(1000);
        u->pay_method = (char*)malloc(100);
        u->account_status = (char*)malloc(100);

        if (!u->id || !u->name || !u->email || !u->phone_number || !u->passport || !u->country_code || !u->address || !u->pay_method || !u->account_status) {
            printf("Memory allocation failed\n");
            fclose(file); 
            return;
        }

        sscanf(buffer, "%99[^;];%99[^;];%99[^;];%99[^;];%d/%d/%d;%c;%99[^;];%99[^;];%999[^;];%d/%d/%d %d:%d:%d;%99[^;];%99[^\n]",
            u->id, u->name, u->email, u->phone_number, &u->birth_date[0], &u->birth_date[1], &u->birth_date[2],
            &u->sex, u->passport, u->country_code, u->address,
            &u->account_creation[0], &u->account_creation[1], &u->account_creation[2], &u->account_creation[3], &u->account_creation[4], &u->account_creation[5],
            u->pay_method, u->account_status);

        u = &user_list[return_hash(u->id)];
    }
    fclose(file);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        freeUser(&user_list[i]);
    }
}
//	id;name;email;phone_number;birth_date;sex;passport;country_code;address;account_creation;pay_method;account_status
