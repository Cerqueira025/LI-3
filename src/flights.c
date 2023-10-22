#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"
#include "defines.h"
#include "flights.h"

struct Flight* new_Flight(int id, char* airplane, char* plane_model, int total_seats, char* origin, char* destination, int schedule_departure_date[6], int schedule_arrival_date[6], int real_departure_date[6], int real_arrival_date[6], char* pilot, char* copilot, char* notes) {

	struct Flight* new_Flight = malloc(sizeof(struct Flight));
	new_Flight->id=id;
	new_Flight->airline=strdup(airplane);
	new_Flight->plane_model=strdup(plane_model);
	new_Flight->total_seats=total_seats;
	new_Flight->origin=strdup(origin);
	new_Flight->destination=strdup(destination);
  for (int i=0;i<6;i++) {
    new_Flight->schedule_departure_date[i]=schedule_departure_date[i];
  }
  for (int i=0;i<6;i++) {
    new_Flight->schedule_arrival_date[i]=schedule_arrival_date[i];
  }
  for (int i=0;i<6;i++) {
    new_Flight->real_departure_date[i]=real_departure_date[i];
  }
  for (int i=0;i<6;i++) {
    new_Flight->real_arrival_date[i]=real_arrival_date[i];
  }
	new_Flight->pilot=strdup(pilot);
	new_Flight->copilot=strdup(copilot);
  new_Flight->notes=strdup(notes);
	return new_Flight;
}


int parse_flight() {

	char buffer[240];
	
	FILE* flights = fopen("flights.csv","r");

	if(flights == NULL) return 1;

	fgets(buffer, 240, flights); // ignora o cabeçalho

  struct Flight flights_table[1000];
  
	while(fgets(buffer, 240, flights)) {

		char* buffer_aux = buffer;
    int id;
    char* airline=malloc(99*sizeof(char));
    char* plane_model=malloc(99*sizeof(char));
    int total_seats;
    char* origin=malloc(99*sizeof(char));    
    char* destination=malloc(99*sizeof(char));
    int schedule_departure_date[6];
    int schedule_arrival_date[6]; 
    int real_departure_date[6];
    int real_arrival_date[6];
    char* pilot=malloc(99*sizeof(char));
    char* copilot=malloc(99*sizeof(char));
    char* notes=malloc(999*sizeof(char)); 

		sscanf(buffer_aux, "%d;%[^;];%[^;];%d;%[^;];%[^;];%d/%d/%d %d:%d:%d;%d/%d/%d %d:%d:%d;%d/%d/%d %d:%d:%d;%d/%d/%d %d:%d:%d;%[^;];%[^;];%[^\n]",
            &id, airline, plane_model, &total_seats, origin, destination, &schedule_departure_date[0], &schedule_departure_date[1], &schedule_departure_date[2], &schedule_departure_date[3], &schedule_departure_date[4],&schedule_departure_date[5], &schedule_arrival_date[0], &schedule_arrival_date[1], &schedule_arrival_date[2], &schedule_arrival_date[3], &schedule_arrival_date[4], &schedule_arrival_date[4], &real_departure_date[0], &real_departure_date[1], &real_departure_date[2], &real_departure_date[3], &real_departure_date[4], &real_departure_date[5], &real_arrival_date[0], &real_arrival_date[1], &real_arrival_date[2], &real_arrival_date[3], &real_arrival_date[4], &real_arrival_date[5], pilot, copilot, notes);

    struct Flight* newFlight = new_Flight(id,airline,plane_model,total_seats,origin,destination,schedule_departure_date,schedule_arrival_date,real_departure_date,real_arrival_date,pilot,copilot,notes);
		flights_table[id] = *newFlight;

		free(airline);
		free(plane_model);
		free(origin);
		free(destination);
		free(pilot);
		free(copilot);
	}

  //teste	
  printf("%s\n\n",flights_table[76].notes);

	fclose(flights);
	return 0;
}
