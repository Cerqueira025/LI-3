#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"
#include "defines.h"
#include "parser.h"
#include "passengers.h"
#include "reservations.h"

struct Reservation* newReservation(int id, char* user_id, int hotel_id, char* hotel_name, int hotel_stars, int city_tax, char* address, int begin_date[3], int end_date[3], int price_per_night, char* includes_breakfast, char* room_details, int rating, char* comment) {

	struct Reservation* new_Reservation = malloc(sizeof(struct Reservation));
	new_Reservation->id=id;
	new_Reservation->user_id=strdup(user_id);
	new_Reservation->hotel_id=hotel_id;
	new_Reservation->hotel_name=strdup(hotel_name);
	new_Reservation->hotel_stars=hotel_stars;
	new_Reservation->city_tax=city_tax;
	new_Reservation->address=strdup(address);
  for (int i=0;i<3;i++) {
	  new_Reservation->begin_date[i]=begin_date[i];
  }
  for (int i=0;i<3;i++) {
	  new_Reservation->end_date[i]=end_date[i];
  }
	new_Reservation->price_per_night=price_per_night;
	new_Reservation->includes_breakfast=strdup(includes_breakfast);
	new_Reservation->room_details=strdup(room_details);
	new_Reservation->rating=rating;
	new_Reservation->comment=strdup(comment);
	return new_Reservation;
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

int parse_reservations() {
	char buffer[240];
	
	FILE* reservations_file = fopen("reservations_100.csv","r");

	if(reservations_file == NULL) return 1;

	fgets(buffer, 240, reservations_file); // ignora o cabeçalho

  struct Reservation* reservation_table[42000];

	while(fgets(buffer, 240, reservations_file)) {

		char* buffer_aux = buffer;
		int id;
    char* user_id = malloc(99*sizeof(char));	
    int hotel_id;
    char* hotel_name = malloc(99*sizeof(char));	
    int hotel_stars;
    int city_tax;
    char* address = malloc(99*sizeof(char));	
    int begin_date[3];
    int end_date[3];
    int price_per_night;
    char* includes_breakfast = malloc(99*sizeof(char));	
    char* room_details = malloc(99*sizeof(char));	
    int rating;
    char* comment = malloc(99*sizeof(char));	

		sscanf(buffer_aux, "Book%d;%[^;];HTL%d;%[^;];%d;%d;%[^;];%d/%d/%d;%d/%d/%d;%d;%[^;];%[^;];%d,%[^\n]",
            &id, user_id, &hotel_id, hotel_name, &hotel_stars, &city_tax, address, &begin_date[0], &begin_date[1], &begin_date[2], &end_date[0], &end_date[1], &end_date[2], &price_per_night, includes_breakfast, room_details, &rating, comment);
  

		struct Reservation* reservation = newReservation(id,user_id,hotel_id,hotel_name,hotel_stars,city_tax,address,begin_date,end_date,price_per_night,includes_breakfast,room_details, rating, comment);
    reservation_table[id] = reservation;

		free(user_id);
		free(hotel_name);
		free(address);
		free(includes_breakfast);
		free(room_details);
		free(comment);

	}
		printf("%s\n\n",reservation_table[12]->address);

	fclose(reservations_file);
	return 0;
}