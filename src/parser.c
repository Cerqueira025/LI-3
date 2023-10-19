#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"
#include "defines.h"
#include "parser.h"
#include "passengers.h"
#include "users.h"


int return_hash(char* user_id) {
  unsigned int total = 0;
  for (int i=0;user_id[i];i++) {
    total+=user_id[i];
    total*=user_id[i];
  }
  return total%10000;
}
/*#include <stdint.h>

// Função de hash FNV-1a
uint32_t fnv1a_hash(const char *str) {
    uint32_t hash = 2166136261u;
    
    while (*str) {
        hash ^= (uint8_t)*str++;
        hash *= 16777619u;
    }
    
    return hash;
}
*/
/**
 * Função que lê o ficheiro csv e guarda a informação dos users numa hash table 
 * - o indice em que é guardada cada user é determinado pelo função return_hash
*/
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
        u->next = NULL;

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

        //u = &user_list[return_hash(u->id)];
        insertUser(table, u);
    }
    fclose(file);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        freeUser(&user_list[i]);
    }
}