// position_tests.c - Implementations of unit tests that test the creation
// and deallocation of POSITION structure instances
//

#include "stdafx.h"
#include "list_fun.h"

#include "position_tests.h"

//////////////////////////////////////////////////////////////////////////////
// Internal functions

BOOL CreatePositionTest() {
  LPPOSITION pPosition = NULL;

  CreatePosition(&pPosition);

  if (!AssertIsNotNull("CreatePositionTest",
      "Expected non-NULL value for created POSITION structure instance.\n",
      pPosition)) {
    return FALSE;
  }

  if (!AssertIsNull("CreatePositionTest",
      "Expected NULL value for pPosition->pPrev member\n",
      pPosition->pPrev)) {
    return FALSE;
  }

  if (!AssertIsNull("CreatePositionTest",
      "Expected NULL value for pPosition->pNext member\n",
      pPosition->pNext)) {
    return FALSE;
  }

  if (!AssertIsNull("CreatePositionTest",
      "Expected NULL value for pPosition->pvData member\n",
      pPosition->pvData)) {
    return FALSE;
  }

  return TRUE;
}

void SetUp() {
  // TODO: Add code here to initialize the test session
}

void TearDown() {
  // TODO: Add code here to tear down the test session
}

//////////////////////////////////////////////////////////////////////////////
// Exposed functions

void RunAllPositionTests() {
  LPTESTSESSION lpSession = NULL;

  StartUnitTestSession(SetUp, TearDown, &lpSession);

  ExecuteTest(lpSession,
      "CreatePositionTest", CreatePositionTest);

  EndUnitTestSession(lpSession);
}
