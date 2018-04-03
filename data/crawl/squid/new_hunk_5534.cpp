#include "squid.h"

#include "store_asyncufs.h"
#include "ufscommon.h"

MemPool *squidaio_state_pool = NULL;
MemPool *aufs_qread_pool = NULL;
MemPool *aufs_qwrite_pool = NULL;
static int asyncufs_initialised = 0;

static STDUMP storeAufsDirDump;
static STCHECKOBJ storeAufsDirCheckObj;
static void storeAufsDirIOUnlinkFile(char *path);


/* The MAIN externally visible function */
STSETUP storeFsSetup_aufs;

/*
 * storeAufsDirCheckObj
 *
