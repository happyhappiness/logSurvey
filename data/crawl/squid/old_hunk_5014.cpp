
#include "DiskIO/DiskDaemon/diomsg.h"

#undef assert
#include <assert.h>


const int diomsg::msg_snd_rcv_sz = sizeof(diomsg) - sizeof(mtyp_t);
#define DEBUG(LEVEL) if ((LEVEL) <= DebugLevel)
