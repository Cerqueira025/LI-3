#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"
#include "defines.h"
#include "parser.h"
#include "passengers.h"
#include "users.h"
#include "flights.h"
#include "reservations.h"


int main() {
  parse_users();
  parse_reservations();
  parse_flight();

  return 0;
}