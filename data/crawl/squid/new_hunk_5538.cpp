
#include "store_diskd.h"

#include "ufscommon.h"

diskd_stats_t diskd_stats;

MemPool *diskd_state_pool = NULL;
static int diskd_initialised = 0;

static STINIT storeDiskdDirInit;
static STDUMP storeDiskdDirDump;
static STCHECKOBJ storeDiskdDirCheckObj;
static void storeDiskdDirStats(SwapDir *, StoreEntry *);
static void storeDiskdStats(StoreEntry * sentry);
static void storeDiskdDirSync(SwapDir *);
static void storeDiskdDirIOUnlinkFile(char *path);

/* The only externally visible interface */
STSETUP storeFsSetup_diskd;

static void
storeDiskdDirInit(SwapDir * sd)
{
    int x;
    int i;
    int rfd;
