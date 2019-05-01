// list_fun.c - Implementations for the functions in the list_fun application.
//

#include "stdafx.h"
#include "list_fun.h"

#include "client_struct.h"
#include "position_tests.h"

//////////////////////////////////////////////////////////////////////////////
// main applcation logic

int main() {
  fprintf(stdout, "Running POSITION tests...\n");
  RunAllPositionTests();

  fprintf(stdout, "Done.\n");
  return 0;
}

//////////////////////////////////////////////////////////////////////////////
