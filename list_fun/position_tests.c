// position_tests.c - Implementations of unit tests that test the creation
// and deallocation of POSITION structure instances
//

#include "stdafx.h"
#include "list_fun.h"

#include "position_tests.h"

//////////////////////////////////////////////////////////////////////////////
// Global variables

LPPOSITION lpPosition = NULL;

//////////////////////////////////////////////////////////////////////////////
// Internal functions

void CreateNewPosition() {
  CreatePosition(&lpPosition);
}

BOOL CreatePositionTest() {
  CreateNewPosition();

  if (!AssertIsNotNull("CreatePositionTest",
      "Expected non-NULL value for created POSITION structure instance.\n",
      lpPosition)) {
    FreeBuffer((void**)&lpPosition);
    return FALSE;
  }

  if (!AssertIsNull("CreatePositionTest",
      "Expected NULL value for pPosition->pPrev member\n",
      lpPosition->pPrev)) {
    FreeBuffer((void**)&lpPosition);
    return FALSE;
  }

  if (!AssertIsNull("CreatePositionTest",
      "Expected NULL value for pPosition->pNext member\n",
      lpPosition->pNext)) {
    FreeBuffer((void**)&lpPosition);
    return FALSE;
  }

  if (!AssertIsNull("CreatePositionTest",
      "Expected NULL value for pPosition->pvData member\n",
      lpPosition->pvData)) {
    FreeBuffer((void**)&lpPosition);
    return FALSE;
  }

  FreeBuffer((void**)&lpPosition);

  return TRUE;
}

void PositionTestSetUp() {
  // TODO: Add code here to initialize the test session
}

void PositionTestTearDown() {
  // TODO: Add code here to tear down the test session
}

//////////////////////////////////////////////////////////////////////////////
// Exposed functions

void RunAllPositionTests() {
  LPTESTSESSION lpSession = NULL;

  StartUnitTestSession(PositionTestSetUp,
      PositionTestTearDown, &lpSession);

  ExecuteTest(lpSession,
      "CreatePositionTest", CreatePositionTest);

  EndUnitTestSession(lpSession);
}
