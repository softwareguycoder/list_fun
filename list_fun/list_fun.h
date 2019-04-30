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

void AddToList(void *pvData, POSITION* pHead);
POSITION* AddToListHead(void *pvData);
void DeleteFromTheMiddleTest();
void HandleError(const char *pszMessage);
LPCLIENTSTRUCT MakeElement();
void PrintAllClientIDs(POSITION** ppHead);
void PyramidAddTest();

#endif //__LIST_FUN_H__
