#include <stdio.h>

struct flights
{
  int id;
  char* airline;
  char* plane_model;
  int total_seats;
  char* origin;  //char origin[3];  -> try  
  char* destination; //char destination[3]; -> ver questão do /0
  int schedule_departure_date[6]; // aaaa/MM/dd hh:mm:ss  -> [aaaa, MM, dd, hh, mm, ss]
  int chedule_arrival_date[6]; 
  int real_departure_date[6];
  int real_arrival_date[6];
  char* pilot;
  char* copilot;
  char* notes;
};



void loadFlightsFromFile(){

}