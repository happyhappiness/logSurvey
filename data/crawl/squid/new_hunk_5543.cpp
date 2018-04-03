#include "squid.h"

#include "store_ufs.h"
#include "ufscommon.h"

MemPool *ufs_state_pool = NULL;
static int ufs_initialised = 0;

static STDUMP storeUfsDirDump;
static STCHECKOBJ storeUfsDirCheckObj;
static void storeUfsDirIOUnlinkFile(char *path);

STSETUP storeFsSetup_ufs;

/*
 * storeUfsDirCheckObj
 *
