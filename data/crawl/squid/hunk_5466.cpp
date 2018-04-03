 
 #include "ufscommon.h"
 
+#include "SwapDir.h"
+
 diskd_stats_t diskd_stats;
 
-MemPool *diskd_state_pool = NULL;
 static int diskd_initialised = 0;
 
-static STINIT storeDiskdDirInit;
-static STDUMP storeDiskdDirDump;
-static STCHECKOBJ storeDiskdDirCheckObj;
-static void storeDiskdDirStats(SwapDir *, StoreEntry *);
 static void storeDiskdStats(StoreEntry * sentry);
-static void storeDiskdDirSync(SwapDir *);
-static void storeDiskdDirIOUnlinkFile(char *path);
 
 /* The only externally visible interface */
 STSETUP storeFsSetup_diskd;
 
-static void
-storeDiskdDirInit(SwapDir * sd)
+
+
+void
+DiskdSwapDir::init()
 {
     int x;
-    int i;
     int rfd;
     int ikey;
     const char *args[5];
     char skey1[32];
     char skey2[32];
     char skey3[32];
-    diskdinfo_t *diskdinfo = (diskdinfo_t *)sd->fsdata;
+    DiskdIO *DIO = dynamic_cast<DiskdIO *>(IO);
 
-    ikey = (getpid() << 10) + (sd->index << 2);
+    ikey = (getpid() << 10) + (index << 2);
     ikey &= 0x7fffffff;
-    diskdinfo->smsgid = msgget((key_t) ikey, 0700 | IPC_CREAT);
-    if (diskdinfo->smsgid < 0) {
+    DIO->smsgid = msgget((key_t) ikey, 0700 | IPC_CREAT);
+    if (DIO->smsgid < 0) {
 	debug(50, 0) ("storeDiskdInit: msgget: %s\n", xstrerror());
 	fatal("msgget failed");
     }
-    diskdinfo->rmsgid = msgget((key_t) (ikey + 1), 0700 | IPC_CREAT);
-    if (diskdinfo->rmsgid < 0) {
+    DIO->rmsgid = msgget((key_t) (ikey + 1), 0700 | IPC_CREAT);
+    if (DIO->rmsgid < 0) {
 	debug(50, 0) ("storeDiskdInit: msgget: %s\n", xstrerror());
 	fatal("msgget failed");
     }
-    diskdinfo->shm.nbufs = (int)(diskdinfo->magic2 * 1.3);
-    diskdinfo->shm.id = shmget((key_t) (ikey + 2),
-	diskdinfo->shm.nbufs * SHMBUF_BLKSZ, 0600 | IPC_CREAT);
-    if (diskdinfo->shm.id < 0) {
-	debug(50, 0) ("storeDiskdInit: shmget: %s\n", xstrerror());
-	fatal("shmget failed");
-    }
-    diskdinfo->shm.buf = (char *)shmat(diskdinfo->shm.id, NULL, 0);
-    if (diskdinfo->shm.buf == (void *) -1) {
-	debug(50, 0) ("storeDiskdInit: shmat: %s\n", xstrerror());
-	fatal("shmat failed");
-    }
-    diskdinfo->shm.inuse_map = (char *)xcalloc((diskdinfo->shm.nbufs + 7) / 8, 1);
-    diskd_stats.shmbuf_count += diskdinfo->shm.nbufs;
-    for (i = 0; i < diskdinfo->shm.nbufs; i++) {
-	CBIT_SET(diskdinfo->shm.inuse_map, i);
-	storeDiskdShmPut(sd, i * SHMBUF_BLKSZ);
-    }
+    DIO->shm.init(ikey, DIO->magic2);
     snprintf(skey1, 32, "%d", ikey);
     snprintf(skey2, 32, "%d", ikey + 1);
     snprintf(skey3, 32, "%d", ikey + 2);
