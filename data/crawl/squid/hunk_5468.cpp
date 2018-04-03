 		
 }
 
-/*
- * SHM manipulation routines
- */
-
-void *
-storeDiskdShmGet(SwapDir * sd, off_t * shm_offset)
-{
-    char *buf = NULL;
-    diskdinfo_t *diskdinfo = (diskdinfo_t *)sd->fsdata;
-    int i;
-    for (i = 0; i < diskdinfo->shm.nbufs; i++) {
-	if (CBIT_TEST(diskdinfo->shm.inuse_map, i))
-	    continue;
-	CBIT_SET(diskdinfo->shm.inuse_map, i);
-	*shm_offset = i * SHMBUF_BLKSZ;
-	buf = diskdinfo->shm.buf + (*shm_offset);
-	break;
-    }
-    assert(buf);
-    assert(buf >= diskdinfo->shm.buf);
-    assert(buf < diskdinfo->shm.buf + (diskdinfo->shm.nbufs * SHMBUF_BLKSZ));
-    diskd_stats.shmbuf_count++;
-    if (diskd_stats.max_shmuse < diskd_stats.shmbuf_count)
-	diskd_stats.max_shmuse = diskd_stats.shmbuf_count;
-    return buf;
-}
-
-void
-storeDiskdShmPut(SwapDir * sd, off_t offset)
-{
-    int i;
-    diskdinfo_t *diskdinfo = (diskdinfo_t *)sd->fsdata;
-    assert(offset >= 0);
-    assert(offset < diskdinfo->shm.nbufs * SHMBUF_BLKSZ);
-    i = offset / SHMBUF_BLKSZ;
-    assert(i < diskdinfo->shm.nbufs);
-    assert(CBIT_TEST(diskdinfo->shm.inuse_map, i));
-    CBIT_CLR(diskdinfo->shm.inuse_map, i);
-    diskd_stats.shmbuf_count--;
-}
-
-
-
-
 /* ========== LOCAL FUNCTIONS ABOVE, GLOBAL FUNCTIONS BELOW ========== */
 
 void
-storeDiskdDirStats(SwapDir * SD, StoreEntry * sentry)
+DiskdSwapDir::statfs(StoreEntry & sentry)const
 {
-    diskdinfo_t *diskdinfo = (diskdinfo_t *)SD->fsdata;
-    commonUfsDirStats (SD, sentry);
-    storeAppendPrintf(sentry, "Pending operations: %d\n", diskdinfo->away);
+    UFSSwapDir::statfs (sentry);
+    DiskdIO *DIO = dynamic_cast<DiskdIO *>(IO);
+    storeAppendPrintf(&sentry, "Pending operations: %d\n", DIO->away);
 }
 
 static void
 storeDiskdDirParseQ1(SwapDir * sd, const char *name, const char *value, int reconfiguring)
 {
-    diskdinfo_t *diskdinfo = (diskdinfo_t *)sd->fsdata;
-    int old_magic1 = diskdinfo->magic1;
-    diskdinfo->magic1 = atoi(value);
+    DiskdIO *IO = dynamic_cast<DiskdIO *>(((DiskdSwapDir *)sd)->IO);
+    int old_magic1 = IO->magic1;
+    IO->magic1 = atoi(value);
     if (!reconfiguring)
 	return;
-    if (old_magic1 < diskdinfo->magic1) {
+    if (old_magic1 < IO->magic1) {
        /*
 	* This is because shm.nbufs is computed at startup, when
 	* we call shmget().  We can't increase the Q1/Q2 parameters
