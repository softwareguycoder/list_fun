// list_fun.c - Implementations for the functions in the list_fun application.
//

#include "stdafx.h"
#include "list_fun.h"

#include "client_struct.h"

// Forward declaration of ReportLIstMemberCount prototype
void ReportListMemberCount(POSITION* pHead);

///////////////////////////////////////////////////////////////////////////////
// AddToList

void AddToList(void *pvData, POSITION * pHead) {
	if (pvData == NULL) {
		return;
	}

	if (pHead == NULL) {
		return;
	}

	if (!AddTail(&pHead, pvData)) {
		DestroyList(&pHead, FreeClient);
		HandleError("ERROR: Failed to add element to list.\n");
	}

	ReportListMemberCount(pHead);
}

///////////////////////////////////////////////////////////////////////////////
// AddToListHead function

POSITION * AddToListHead(void *pvData) {
	POSITION *pListHead = CreateNewList(pvData);
	if (pListHead == NULL) {
		DestroyList(&pListHead, FreeClient);
		HandleError("ERROR: Could not add head to list.\n");
	}

	// We make a variable here so it can be watched in the
	// debugger.
	ReportListMemberCount(pListHead);
	return pListHead;
}

///////////////////////////////////////////////////////////////////////////////
// DeleteFromTheMiddleTest function

void DeleteFromTheMiddleTest() {
	printf("Starting the 'delete from the middle' test...\n");

	LPCLIENTSTRUCT lpCS1 = MakeElement();
	lpCS1->nSocket = 1;
	LPCLIENTSTRUCT lpCS2 = MakeElement();
	lpCS2->nSocket = 2;
	LPCLIENTSTRUCT lpCS3 = MakeElement();
	lpCS3->nSocket = 3;
	LPCLIENTSTRUCT lpCS4 = MakeElement();
	lpCS4->nSocket = 4;
	LPCLIENTSTRUCT lpCS5 = MakeElement();
	lpCS5->nSocket = 5;

	printf("Now the list has 0 members.\n");

	POSITION *pHead = AddToListHead(lpCS1);
	AddToList(lpCS2, pHead);
	AddToList(lpCS3, pHead);
	AddToList(lpCS4, pHead);
	AddToList(lpCS5, pHead);

	printf("Now the list should have 5 members.\n");

	PrintAllClientIDs(&pHead);

	printf("Now removing everything and destroying the list...\n");

	DestroyList(&pHead, FreeClient);

	printf("List deallocation complete.\n");
}

///////////////////////////////////////////////////////////////////////////////
// HandleError function

void HandleError(const char *pszMessage) {
	if (pszMessage == NULL || pszMessage[0] == '\0') {
		return;
	}
	fprintf(stderr, "%s", pszMessage);
	exit(ERROR);
}

///////////////////////////////////////////////////////////////////////////////
// MakeElement function

LPCLIENTSTRUCT MakeElement() {
	LPCLIENTSTRUCT lpResult = CreateClientStruct(rand(), "localhost");
	if (lpResult == NULL) {
		HandleError("Failed to create CLIENTSTRUCT instance #1\n");
	}
	fprintf(stdout, "CLIENTSTRUCT instance created successfully.\n");
	return lpResult;
}

///////////////////////////////////////////////////////////////////////////////
// PyramidAddTest function

void PyramidAddTest() {
	// 'pyramid' test of the linked list, first we add elements
	// and then we remove them one by one

	printf("Starting 'pyramid test'...\n");

	LPCLIENTSTRUCT lpCS1 = MakeElement();
	LPCLIENTSTRUCT lpCS2 = MakeElement();
	LPCLIENTSTRUCT lpCS3 = MakeElement();
	LPCLIENTSTRUCT lpCS4 = MakeElement();
	LPCLIENTSTRUCT lpCS5 = MakeElement();

	printf("Now the list has 0 members.\n");

	POSITION *pHead = AddToListHead(lpCS1);
	AddToList(lpCS2, pHead);
	AddToList(lpCS3, pHead);
	AddToList(lpCS4, pHead);
	AddToList(lpCS5, pHead);

	printf("Now the list should have 5 members.\n");

	PrintAllClientIDs(&pHead);

	printf("Now removing everything and destroying the list...\n");

	DestroyList(&pHead, FreeClient);

	printf("List deallocation complete.\n");

	PrintAllClientIDs(&pHead);
}

///////////////////////////////////////////////////////////////////////////////
// PrintAllClientIDs function

void PrintAllClientIDs(POSITION** ppHead) {
	if (ppHead == NULL || *ppHead == NULL) {
		fprintf(stdout, "There are zero elements in the linked list.\n");
		return;
	}

	POSITION* pos = GetHeadPosition(ppHead);
	if (pos == NULL) {
		fprintf(stdout, "There are zero elements in the linked list.\n");
		return;
	}

	do {
		LPCLIENTSTRUCT lpCS = (LPCLIENTSTRUCT) (pos->pvData);
		if (lpCS == NULL) {
			return;
		}

		printf("Client #%d is in the list.\n", lpCS->nSocket);
	} while ((pos = GetNext(pos)) != NULL);
}

///////////////////////////////////////////////////////////////////////////////
// ReportListMemberCount function

void ReportListMemberCount(POSITION * pHead) {
	int nCount = GetCount(&pHead);
	fprintf(stdout, "Now the list has %d members.\n", nCount);
}

int main() {
	// Use current time as seed for random generator
	srand(time(0));

	PyramidAddTest();

	DeleteFromTheMiddleTest();

	return 0;
}
