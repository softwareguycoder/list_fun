// list_fun.c - Implementations for the functions in the list_fun application.
//

#include "stdafx.h"
#include "list_fun.h"

#include "client_struct.h"

// Forward declaration of ReportLIstMemberCount prototype
void ReportListMemberCount(POSITION* pHead);

///////////////////////////////////////////////////////////////////////////////
// AddToList

void AddToList(POSITION** ppListHead, void** ppvData) {
	if (ppvData == NULL || *ppvData == NULL) {
		return;
	}

	if (ppListHead == NULL || *ppListHead == NULL) {
		return;
	}

	if (!AddTail(ppListHead, *ppvData)) {
		DestroyList(ppListHead, FreeClient);
		HandleError("ERROR: Failed to add element to list.\n");
	}

	ReportListMemberCount(*ppListHead);
}

///////////////////////////////////////////////////////////////////////////////
// AddToListHead function

void AddToListHead(POSITION** ppNewListHead, void** ppvData) {
	if (ppNewListHead == NULL) {
		return;
	}

	if (ppvData == NULL || *ppvData == NULL) {
		return;
	}

	CreateNewList(ppNewListHead, ppvData);

	if (*ppNewListHead == NULL) {
		HandleError("ERROR: Could not add head to list.\n");
	}

	// We make a variable here so it can be watched in the
	// debugger.
	ReportListMemberCount(*ppNewListHead);
}

///////////////////////////////////////////////////////////////////////////////
// DeleteFromTheMiddleTest function

void DeleteFromTheMiddleTest() {
	printf("Starting the 'delete from the middle' test...\n");

	LPCLIENTSTRUCT lpCS1 = NULL;
	LPCLIENTSTRUCT lpCS2 = NULL;
	LPCLIENTSTRUCT lpCS3 = NULL;
	LPCLIENTSTRUCT lpCS4 = NULL;
	LPCLIENTSTRUCT lpCS5 = NULL;

	POSITION *pHead = NULL;

	MakeElement(&lpCS1);
	MakeElement(&lpCS2);
	MakeElement(&lpCS3);
	MakeElement(&lpCS4);
	MakeElement(&lpCS5);

	printf("Now the list has 0 members.\n");

	AddToListHead(&pHead, (void**)&lpCS1);
	AddToList(&pHead, (void**)&lpCS2);
	AddToList(&pHead, (void**)&lpCS3);
	AddToList(&pHead, (void**)&lpCS4);
	AddToList(&pHead, (void**)&lpCS5);

	printf("Now the list should have 5 members.\n");

	PrintAllClientIDs(&pHead);

	printf("Now removing everything and destroying the list...\n");

	DestroyList(&pHead, FreeClient);

	FreeBuffer((void**) &lpCS1);
	FreeBuffer((void**) &lpCS2);
	FreeBuffer((void**) &lpCS3);
	FreeBuffer((void**) &lpCS4);
	FreeBuffer((void**) &lpCS5);

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

void MakeElement(LPCLIENTSTRUCT *ppClientStruct) {
	if (ppClientStruct == NULL) {
		return;
	}

	int nTestingClientSocket = 0;
	nTestingClientSocket = rand();

	CreateClientStruct(ppClientStruct, nTestingClientSocket, "localhost");
	if ((*ppClientStruct) == NULL) {
		HandleError("Failed to create CLIENTSTRUCT instance\n");
	}

	fprintf(stdout, "CLIENTSTRUCT instance created successfully.\n");
}

///////////////////////////////////////////////////////////////////////////////
// PyramidAddTest function

void PyramidAddTest() {
	// 'pyramid' test of the linked list, first we add elements
	// and then we remove them one by one

	printf("Starting 'pyramid test'...\n");

	LPCLIENTSTRUCT lpCS1 = NULL;
	LPCLIENTSTRUCT lpCS2 = NULL;
	LPCLIENTSTRUCT lpCS3 = NULL;
	LPCLIENTSTRUCT lpCS4 = NULL;
	LPCLIENTSTRUCT lpCS5 = NULL;

	POSITION *pHead = NULL;

	MakeElement(&lpCS1);
	MakeElement(&lpCS2);
	MakeElement(&lpCS3);
	MakeElement(&lpCS4);
	MakeElement(&lpCS5);

	printf("Now the list has 0 members.\n");

	AddToListHead(&pHead, (void**)&lpCS1);
	AddToList(&pHead, (void**)&lpCS2);
	AddToList(&pHead, (void**)&lpCS3);
	AddToList(&pHead, (void**)&lpCS4);
	AddToList(&pHead, (void**)&lpCS5);

	printf("Now the list should have 5 members.\n");

	PrintAllClientIDs(&pHead);

	printf("Now removing everything and destroying the list...\n");

	DestroyList(&pHead, FreeClient);

	/* still have to free the lpCS's */

	FreeBuffer((void**) &lpCS1);
	FreeBuffer((void**) &lpCS2);
	FreeBuffer((void**) &lpCS3);
	FreeBuffer((void**) &lpCS4);
	FreeBuffer((void**) &lpCS5);

	FreeBuffer((void**) &pHead);

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
