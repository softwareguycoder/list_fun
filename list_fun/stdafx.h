// stdafx.h - Precompiled header for the application
//

#ifndef __STDAFX_H__
#define __STDAFX_H__

#define _GNU_SOURCE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <signal.h>

#include <../../list_core/list_core/include/list_core.h>

typedef enum { FALSE, TRUE } BOOL;

#endif //__STDAFX_H__
