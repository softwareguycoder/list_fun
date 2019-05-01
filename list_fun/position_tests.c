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

void DestroyThePosition() {
  DestroyPosition(&lpPosition);
}

BOOL CreatePositionTest() {
  CreateNewPosition();

  if (!AssertIsNotNull("CreatePositionTest",
      "Expected non-NULL value for created POSITION structure instance.\n",
      lpPosition)) {
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  if (!AssertIsNull("CreatePositionTest",
      "Expected NULL value for pPosition->pPrev member\n",
      lpPosition->pPrev)) {
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  if (!AssertIsNull("CreatePositionTest",
      "Expected NULL value for pPosition->pNext member\n",
      lpPosition->pNext)) {
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  if (!AssertIsNull("CreatePositionTest",
      "Expected NULL value for pPosition->pvData member\n",
      lpPosition->pvData)) {
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  FreeBuffer((void**) &lpPosition);

  return TRUE;
}

BOOL CreateAndInitializePositionTest() {
  CreateNewPosition();

  if (!AssertIsNotNull("CreateAndInitializePositionTest",
      "Expected non-NULL value for created POSITION structure instance.\n",
      lpPosition)) {
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  if (!AssertIsNull("CreateAndInitializePositionTest",
      "Expected NULL value for pPosition->pPrev member\n",
      lpPosition->pPrev)) {
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  if (!AssertIsNull("CreateAndInitializePositionTest",
      "Expected NULL value for pPosition->pNext member\n",
      lpPosition->pNext)) {
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  if (!AssertIsNull("CreateAndInitializePositionTest",
      "Expected NULL value for pPosition->pvData member\n",
      lpPosition->pvData)) {
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
#pragma GCC diagnostic ignored "-Wint-conversion"
  /* initialize position structure with randomized addresses */
  InitializePosition(lpPosition, rand(), rand(), rand());
#pragma GCC diagnostic pop

  if (!AssertIsNotNull("CreateAndInitializePositionTest",
      "Expected non-NULL value for pPosition->pPrev member\n",
      lpPosition->pPrev)) {
    /* get rid of the randomized pointer member values before they hurt
     * somebody */
    memset(lpPosition, 0, sizeof(POSITION));
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  if (!AssertIsNotNull("CreateAndInitializePositionTest",
      "Expected non-NULL value for pPosition->pNext member\n",
      lpPosition->pNext)) {
    /* get rid of the randomized pointer member values before they hurt
     * somebody */
    memset(lpPosition, 0, sizeof(POSITION));
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  if (!AssertIsNotNull("CreateAndInitializePositionTest",
      "Expected non-NULL value for pPosition->pvData member\n",
      lpPosition->pvData)) {
    /* get rid of the randomized pointer member values before they hurt
     * somebody */
    memset(lpPosition, 0, sizeof(POSITION));
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  /* get rid of the randomized pointer member values before they hurt
   * somebody */
  memset(lpPosition, 0, sizeof(POSITION));

  FreeBuffer((void**) &lpPosition);

  return TRUE;
}

BOOL CreateAndDestroyPositionTest() {
  CreateNewPosition();

  if (!AssertIsNotNull("CreateAndDestroyPositionTest",
      "Expected non-NULL value for created POSITION structure instance.\n",
      lpPosition)) {
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  if (!AssertIsNull("CreateAndDestroyPositionTest",
      "Expected NULL value for pPosition->pPrev member\n",
      lpPosition->pPrev)) {
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  if (!AssertIsNull("CreateAndDestroyPositionTest",
      "Expected NULL value for pPosition->pNext member\n",
      lpPosition->pNext)) {
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  if (!AssertIsNull("CreateAndDestroyPositionTest",
      "Expected NULL value for pPosition->pvData member\n",
      lpPosition->pvData)) {
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
#pragma GCC diagnostic ignored "-Wint-conversion"
  /* initialize position structure with randomized addresses,
   * and we don't give a crap about the compiler warnings that
   * this code would otherwise produce */
  InitializePosition(lpPosition, rand(), rand(), rand());
#pragma GCC diagnostic pop

  if (!AssertIsNotNull("CreateAndDestroyPositionTest",
      "Expected non-NULL value for pPosition->pPrev member\n",
      lpPosition->pPrev)) {
    /* get rid of the randomized pointer member values before they hurt
     * somebody */
    memset(lpPosition, 0, sizeof(POSITION));
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  if (!AssertIsNotNull("CreateAndDestroyPositionTest",
      "Expected non-NULL value for pPosition->pNext member\n",
      lpPosition->pNext)) {
    /* get rid of the randomized pointer member values before they hurt
     * somebody */
    memset(lpPosition, 0, sizeof(POSITION));
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  if (!AssertIsNotNull("CreateAndDestroyPositionTest",
      "Expected non-NULL value for pPosition->pvData member\n",
      lpPosition->pvData)) {
    /* get rid of the randomized pointer member values before they hurt
     * somebody */
    memset(lpPosition, 0, sizeof(POSITION));
    FreeBuffer((void**) &lpPosition);
    return FALSE;
  }

  DestroyThePosition();

  return TRUE;
}

void PositionTestSetUp() {
  srand(time(NULL));
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

  /*ExecuteTest(lpSession,
      "CreatePositionTest", CreatePositionTest);
  ExecuteTest(lpSession,
      "CreateAndInitializePositionTest",
      CreateAndInitializePositionTest);*/
  ExecuteTest(lpSession,
      "CreateAndDestroyPositionTest",
      CreateAndDestroyPositionTest);
  ExecuteTest(lpSession,
      "CreateAndDestroyPositionTest",
      CreateAndDestroyPositionTest);
  ExecuteTest(lpSession,
      "CreateAndDestroyPositionTest",
      CreateAndDestroyPositionTest);

  EndUnitTestSession(&lpSession);
}
