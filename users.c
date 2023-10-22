#include <stdio.h>
#include <glib.h>
#include <string.h>
#include <stdlib.h>

struct user{
  char* id;
  char* name;
  char* email;
  char* phone_number; //atenção ao formato
  char* birth_date; //aaaa/MM/dd -> [aaaa,MM,dd]
  char* sex;
  char* passport;
  char* country_code; //atenção /0
  char* address;
  char* account_creation;
  char* pay_method;
  char* account_status;
};


struct user* newUser(char* id, char* name, char* email, char* phone_number, char* birth_date, char* sex, char* passport, char* country_code, char* address, char* account_creation, char* pay_method, char* account_status) {

	struct user* new_User=malloc(sizeof(struct user));
	new_User->id=strdup(id);
	new_User->name=strdup(name);
	new_User->email=strdup(email);
	new_User->phone_number=strdup(phone_number);
	new_User->birth_date=strdup(birth_date);
	new_User->sex=strdup(sex);
	new_User->passport=strdup(passport);
	new_User->country_code=strdup(country_code);
	new_User->address=strdup(address);
	new_User->account_creation=strdup(account_creation);
	new_User->pay_method=strdup(pay_method);
	new_User->account_status=strdup(account_status);
	return new_User;
}


/*
char userGender(struct user *u){
	return u->gender;
}

char *nameUser(struct user *u){
	return strdup(u->username);
}

char *userRealName(struct user *u){
	return strdup(u->name);
}

char *getBirthDate(struct user *u){
	return u->birth_date;
}
*/

int parse_users() {
	char buffer[240];
	
	FILE* users = fopen("users_100.csv","r");

	if(users == NULL) return 1;

	fgets(buffer, 240, users); // ignora o cabeçalho


	/*id;name;email;phone_number;birth_date;sex;passport;country_code;address;account_creation;pay_method;account_status
	AlícSá-Mendes;Alícia Sá-Mendes;alícsá-mendes@li3.pt;(351) 259 545 254;1979/11/27;F;CA279133;PT;Avenida Gabriela Guerreiro, 42518-827 Rio Maior;2016/09/10 17:34:41;debit_card;active
	*/
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
  

		struct user* u = newUser(id,name,email,phone_number,birth_date,sex,passport,country_code,address,account_creation,pay_method,account_status);
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
		struct user* usr = g_hash_table_lookup(hash,"EmíVaz-Assunção1873");
		printf("%s\n\n",usr->phone_number);

	fclose(users);
	return 0;
}



int main() {
	parse_users();

	return 0;
}