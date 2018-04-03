#ifndef __COMM_H__
#define __COMM_H__

#include "StoreIOBuffer.h"
#include "Array.h"

typedef void IOFCB(int fd, StoreIOBuffer recievedData, comm_err_t flag, int xerrno, void *data);
typedef void IOWCB(int fd, char *buffer, size_t len, comm_err_t flag, int xerrno, void *data);
/* fill sb with up to length data from fd */
extern void comm_fill_immediate(int fd, StoreIOBuffer sb, IOFCB *callback, void *data);

