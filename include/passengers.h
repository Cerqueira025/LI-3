#ifndef PASSENGERS_H
#define PASSENGERS_H

typedef struct Passenger{
  int flight_id;
  char* user_id;
} Passenger;

struct Passenger* new_Passenger(int flight_id, char* user_id);
int parse_passenger();

#endif