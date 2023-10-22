#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"
#include "defines.h"
#include "parser.h"
#include "passengers.h"
#include "users.h"

int return_hash(char* user_id) {
  unsigned int total = 0;
  for (int i=0;user_id[i];i++) {
    total+=user_id[i];
    total*=user_id[i];
  }
  return total%10000;
}