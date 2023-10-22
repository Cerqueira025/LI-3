#ifndef FLIGHTS_H
#define FLIGHTS_H

typedef struct Flight {
  int id;
  char* airline;
  char* plane_model;
  int total_seats;
  char* origin;  //char origin[3];  -> try  
  char* destination; //char destination[3]; -> ver questão do /0
  int schedule_departure_date[6]; // aaaa/MM/dd hh:mm:ss  -> [aaaa, MM, dd, hh, mm, ss]
  int schedule_arrival_date[6]; 
  int real_departure_date[6];
  int real_arrival_date[6];
  char* pilot;
  char* copilot;
  char* notes;
} Flight;

struct Flight* new_Flight(int id, char* airplane, char* plane_model, int total_seats, char* origin, char* destination, int schedule_departure_date[6], int schedule_arrival_date[6], int real_departure_date[6], int real_arrival_date[6], char* pilot, char* copilot, char* notes);
int parse_flight();

#endif