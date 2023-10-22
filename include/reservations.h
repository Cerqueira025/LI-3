#ifndef RESERVATIONS_H
#define RESERVATIONS_H

typedef struct Reservation {
  int id;
  char* user_id;
  int hotel_id;
  char* hotel_name;
  int hotel_stars;
  int city_tax;
  char* address;
  int begin_date[3]; //aaaa/MM/dd  -> [aaaa, MM, dd]
  int end_date[3];
  int price_per_night;
  char* includes_breakfast; //0-> Falso  &&  1-> Verdadeiro
  char* room_details;
  int rating;
  char* comment;
} Reservation;

struct Reservation* newReservation(int id, char* user_id, int hotel_id, char* hotel_name, int hotel_stars, int city_tax, char* address, int begin_date[3], int end_date[3], int price_per_night, char* includes_breakfast, char* room_details, int rating, char* comment);
int parse_reservations();

#endif