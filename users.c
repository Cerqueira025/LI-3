#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Added for string functions

typedef struct user {
    char* id;
    char* name;
    char* email;
    char* phone_number;
    int birth_date[3];
    char sex;
    char* passport;
    char* country_code;
    char* address;
    int account_creation[6];
    char* pay_method;
    char* account_status;
} user;

void freeUser(user* u) {
    free(u->id);
    free(u->name);
    free(u->email);
    free(u->phone_number);
    free(u->passport);
    free(u->country_code);
    free(u->address);
    free(u->pay_method);
    free(u->account_status);
}


int hash_function(char* user_id) {
  unsigned int total = 0;
  for (int i=0;user_id[i];i++) {
    total+=user_id[i];
    total*=user_id[i];
  }
  return total%10000;
}

void loadUsersFromFile() {
    FILE* file = fopen("users.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char buffer[1000];
    user user_list[10000]; // Declare an array of user structs
    int n = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        user* u= &user_list[n]; // Get a pointer to the current user struct

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

        u = &user_list[hash_function(u->id)];

        printf("User ID: %s\n", user_list[hash_function("MaVaz1704")].id);
        printf("Account Status: %s\n", user_list[hash_function("MaVaz1704")].account_status);
        printf("User_key: %d\n\n",hash_function("MaVaz1704"));
    }
    fclose(file);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        freeUser(&user_list[i]);
    }
}

int main() {
    loadUsersFromFile();
    return 0;
}