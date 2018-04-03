
#include "ufscommon.h"

#include "SwapDir.h"

diskd_stats_t diskd_stats;

static int diskd_initialised = 0;

static void storeDiskdStats(StoreEntry * sentry);

/* The only externally visible interface */
STSETUP storeFsSetup_diskd;



void
DiskdSwapDir::init()
{
    int x;
    int rfd;
    int ikey;
    const char *args[5];
    char skey1[32];
    char skey2[32];
    char skey3[32];
    DiskdIO *DIO = dynamic_cast<DiskdIO *>(IO);

    ikey = (getpid() << 10) + (index << 2);
    ikey &= 0x7fffffff;
    DIO->smsgid = msgget((key_t) ikey, 0700 | IPC_CREAT);
    if (DIO->smsgid < 0) {
	debug(50, 0) ("storeDiskdInit: msgget: %s\n", xstrerror());
	fatal("msgget failed");
    }
    DIO->rmsgid = msgget((key_t) (ikey + 1), 0700 | IPC_CREAT);
    if (DIO->rmsgid < 0) {
	debug(50, 0) ("storeDiskdInit: msgget: %s\n", xstrerror());
	fatal("msgget failed");
    }
    DIO->shm.init(ikey, DIO->magic2);
    snprintf(skey1, 32, "%d", ikey);
    snprintf(skey2, 32, "%d", ikey + 1);
    snprintf(skey3, 32, "%d", ikey + 2);
