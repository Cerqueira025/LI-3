#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"
#include "defines.h"
#include "parser.h"
#include "passengers.h"
#include "users.h"

struct User* newUser(char* id, char* name, char* email, char* phone_number, char* birth_date, char* sex, char* passport, char* country_code, char* address, char* account_creation, char* pay_method, char* account_status) {

	struct User* new_User=malloc(sizeof(struct User));
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


void printUser(const User* user) {
  if (user == NULL) {
    printf("Usuário inválido\n");
  } else {
    printf("ID: %s\n", user->id);
    printf("Nome: %s\n", user->name);
    printf("Email: %s\n", user->email);
    printf("Número de telefone: %s\n", user->phone_number);
    printf("Data de nascimento: %04d/%02d/%02d\n", user->birth_date[0], user->birth_date[1], user->birth_date[2]);
    printf("Sexo: %s\n", user->sex);
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