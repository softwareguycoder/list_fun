// list_fun.h - Defines the interface for the list_fun application
//

#ifndef __LIST_FUN_H__
#define __LIST_FUN_H__

#include "list_fun_symbols.h"

/**
 * @brief Forward declaration of POSITION structure
 */
typedef struct _tagPOSITION POSITION;
typedef struct _tagCLIENTSTRUCT CLIENTSTRUCT, *LPCLIENTSTRUCT;

void AddToList(POSITION** ppListHead, void** ppvData);
void AddToListHead(POSITION** ppNewListHead, void** ppvData);
void DeleteFromTheMiddleTest();
void HandleError(const char *pszMessage);
void MakeElement(LPCLIENTSTRUCT *ppClientStruct);
void PrintAllClientIDs(POSITION** ppHead);
void PyramidAddTest();

#endif //__LIST_FUN_H__
