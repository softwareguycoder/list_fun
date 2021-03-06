// client_struct.h - Defines the interface for the CLIENTSTRUCT structure
//

#ifndef __CLIENT_STRUCT_H__
#define __CLIENT_STRUCT_H__

#include "stdafx.h"
#include "list_fun_symbols.h"

/**
 * @brief Structure that contains information about connected clients.
 */
typedef struct _tagCLIENTSTRUCT {
	char szIPAddress[IPADDRLEN + 1];
	int nSocket;
	BOOL bConnected;
} CLIENTSTRUCT, *LPCLIENTSTRUCT;

/**
 * @brief Creates an instance of a CLIENTSTRUCT structure and fills it with info
 * about the client.
 * @param lppResult Address of a pointer variable that will receive the results
 * of the create operation.
 * @param nClientSocket Client's server endpoint socket file descriptor.
 * @param pszClientIPAddress Client's IP address as a string (i.e., 268.7.34.2)
 * @remarks Supplies a reference to an instance of CLIENTSTRUCT filled with the
 * socket for sending data back to clients in reply to protocol commands or
 * chat messages.
 */
void CreateClientStruct(LPCLIENTSTRUCT* lppResult,
		int nClientSocket, const char* pszClientIPAddress);

/**
 * @brief Releases the memory allocated for a client structure pointer back
 * to the system.
 * @param ppClientStruct Address of a pointer to a CLIENTSTRUCT instance
 * whose memory is to be freed.
 */
void FreeClient(void** ppClientStruct);

#endif /* __CLIENT_STRUCT_H__ */
