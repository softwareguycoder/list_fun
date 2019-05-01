// list_fun.c - Implementations for the functions in the list_fun application.
//

#include "stdafx.h"
#include "list_fun.h"

#include "client_struct.h"

int main() {
  LPTESTSESSION pTestSession = NULL;

  StartUnitTestSession(NULL, NULL, &pTestSession);

  EndUnitTestSession(pTestSession);
}
