#include <stdio.h>

struct reservations
{
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
  int includes_breakfast; //0-> Falso  &&  1-> Verdadeiro
  char* room_details;
  int rating;
  char* comment;
};

void loadReservationsFromFile(){
  
}