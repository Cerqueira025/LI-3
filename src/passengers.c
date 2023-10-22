#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"
#include "defines.h"
#include "parser.h"
#include "passengers.h"

struct Passenger* new_Passenger(int flight_id, char* user_id) {
	struct Passenger* new_Passenger=malloc(sizeof(struct Passenger));
	new_Passenger->flight_id=flight_id;
	new_Passenger->user_id=strdup(user_id);
	return new_Passenger;
}


int parse_passenger() {
	char buffer[240];
	
	FILE* passengers = fopen("passengers.csv","r");
	if(passengers == NULL) return 1;

	fgets(buffer, 240, passengers); // ignora o cabeÃ§alho

  	GHashTable *hash = g_hash_table_new(g_str_hash, g_str_equal);

	while(fgets(buffer, 240, passengers)) {
		char* buffer_aux = buffer;
    	int flight_id;
    	char* user_id=malloc(99*sizeof(char));

		sscanf(buffer_aux, "%d;%[^\n]", &flight_id, user_id);
            
    	struct Passenger* newPassenger = new_Passenger(flight_id, user_id);
    	g_hash_table_insert(hash, (newPassenger->user_id), newPassenger);

		free(user_id);
	}

	//teste	
    struct Passenger* pssgr = g_hash_table_lookup(hash,"ManMartins-Abreu");
	printf("Passanger id: %d\n\n",pssgr->flight_id);

	fclose(passengers);
	return 0;
}
