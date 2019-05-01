// position_tests.c - Implementations of unit tests that test the creation
// and deallocation of POSITION structure instances
//

#include "stdafx.h"
#include "list_fun.h"

#include "position_tests.h"

//////////////////////////////////////////////////////////////////////////////
// Internal functions

void SetUp() {
  // TODO: Add code here to initialize the test session
}

void TearDown() {
  // TODO: Add code here to tear down the test session
}

//////////////////////////////////////////////////////////////////////////////
// Exposed functions

void RunAllPositionTests(){
  LPTESTSESSION lpSession = NULL;

  StartUnitTestSession(SetUp, TearDown, &lpSession);

  // TODO: Add code to execute tests here

  EndUnitTestSession(lpSession);
}
