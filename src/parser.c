#include <stdio.h>
#include <glib.h>
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

/**
 * Função que lê o ficheiro csv e guarda a informação dos users numa hash table 
 * - o indice em que é guardada cada user é determinado pelo função return_hash
*/
int parse_users() {
  char buffer[240];
	
	FILE* users = fopen("users_100.csv","r");

	if(users == NULL) return 1;

	fgets(buffer, 240, users); // ignora o cabeçalho

	GHashTable *hash = g_hash_table_new(g_str_hash, g_str_equal);

	while(fgets(buffer, 240, users)) {

		char* buffer_aux = buffer;
		char* id = malloc(99*sizeof(char));		   	   
		char* name = malloc(99*sizeof(char)); 		   	   
		char* email = malloc(99*sizeof(char)); 	   	   
		char* phone_number = malloc(99*sizeof(char)); 	   
		char* birth_date = malloc(99*sizeof(char));   	   
		char* sex = malloc(99*sizeof(char)); 		   	   
		char* passport = malloc(99*sizeof(char)); 	   	   
		char* country_code = malloc(99*sizeof(char)); 	   
		char* address = malloc(999*sizeof(char)); 	   	   
		char* account_creation = malloc(99*sizeof(char)); 
		char* pay_method = malloc(99*sizeof(char)); 	   
		char* account_status = malloc(99*sizeof(char)); 

		sscanf(buffer_aux, "%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%999[^;];%99[^;];%99[^;];%99[^\n]",
            id, name, email, phone_number, birth_date, sex, passport, country_code, address, account_creation, pay_method, account_status);
  

		struct User* u = newUser(id,name,email,phone_number,birth_date,sex,passport,country_code,address,account_creation,pay_method,account_status);
		g_hash_table_insert(hash, (u->id), u);

		free(id);
		free(name);
		free(email);
		free(phone_number);
		free(birth_date);
		free(sex);
		free(passport);
		free(country_code);
		free(address);
		free(account_creation);
		free(pay_method);
		free(account_status);

	}
		struct User* usr = g_hash_table_lookup(hash,"EmíVaz-Assunção1873");
		printf("%s\n\n",usr->phone_number);

	fclose(users);
	return 0;
}