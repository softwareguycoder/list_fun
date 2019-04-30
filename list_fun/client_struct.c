// client_struct.c - Provides implementations of functions that create and/or
// manipulate a CLIENTSTRUCT instance (CLIENTSTRUCT is a structure that
// provides information about an individual client connection).
//

#include "stdafx.h"

#include "client_struct.h"

///////////////////////////////////////////////////////////////////////////////
// CreateClientStruct - Allocates memory for, and initializes, a new instance
// of a CLIENTSTRUCT structure with the socket handle and IP address provided.
//

void CreateClientStruct(LPCLIENTSTRUCT* lppResult,
		int nClientSocket, const char* pszClientIPAddress) {

	if (lppResult == NULL) {
		// We need the address of storage where the address of the instantiated
		// structure should be placed.
		return;
	}

	if (pszClientIPAddress == NULL || strlen(pszClientIPAddress) == 0) {
		// The client IP address needs to be filled in; nothing to do.
		fprintf(stderr, CLIENT_IP_ADDR_UNK);

		exit(ERROR);
	}

	// Allocate memory for a new CLIENTSTRUCT instance
	LPCLIENTSTRUCT lpClientStruct = (LPCLIENTSTRUCT) malloc(1*sizeof(CLIENTSTRUCT));
	if (lpClientStruct == NULL) {
		fprintf(stderr,
				"Failed to allocate storage for client information structure.\n");
		exit(ERROR);
	}

	// Clear all the memory to zero -- but only after successful allocation
	memset(lpClientStruct, 0, sizeof(CLIENTSTRUCT));

	// Save the client socket handle into the nSocket field of the structure
	lpClientStruct->nSocket = nClientSocket;

	// Initialize the pszIPAddress string field of the client structure with the
	// IP address passed to us.
	strcpy(lpClientStruct->szIPAddress, pszClientIPAddress);

	/* A client isn't 'connected' until the HELO protocol command is issued by the client.
	 * This is to allow clients to 'get ready' before they start being sent other chatters'
	 * messages. */
	lpClientStruct->bConnected = FALSE;

	// Set the result variable to hold the address of the newly-allocated-and-initialized
	// structure
	*lppResult = lpClientStruct;
}

void FindClientByID(void* pvSearchKey, void* pvData) {
	// TODO: Add implementation code here
}

///////////////////////////////////////////////////////////////////////////////
// FreeClient function - Releases operating system resources consumed by the
// client information structure.
//

void FreeClient(void** ppClientStruct) {
	if (ppClientStruct == NULL || *ppClientStruct == NULL) {
		// Null pointer passed for the thing to be freed; nothing to do.
		return;
	}

	memset(((LPCLIENTSTRUCT) (*ppClientStruct))->szIPAddress, 0, IPADDRLEN + 1);

	FreeBuffer(ppClientStruct);

	if ((*ppClientStruct) == NULL) {
		fprintf(stdout, "CLIENSTRUCT instance freed successfully.\n");
	}
}
