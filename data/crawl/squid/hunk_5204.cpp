     return x;
 }
 
+SwapDirOption *
+DiskdIO::getOptionTree() const
+{
+    SwapDirOptionVector *result = new SwapDirOptionVector;
+    result->options.push_back(new SwapDirOptionAdapter<DiskdIO>(*const_cast<DiskdIO *>(this), &DiskdIO::optionQ1Parse, &DiskdIO::optionQ1Dump));
+    result->options.push_back(new SwapDirOptionAdapter<DiskdIO>(*const_cast<DiskdIO *>(this), &DiskdIO::optionQ2Parse, &DiskdIO::optionQ2Dump));
+    return result;
+}
+
+bool
+DiskdIO::optionQ1Parse(const char *name, const char *value, int reconfiguring)
+{
+    if (strcmp(name, "Q1") != 0)
+        return false;
+
+    int old_magic1 = magic1;
+
+    magic1 = atoi(value);
+
+    if (!reconfiguring)
+        return true;
+
+    if (old_magic1 < magic1) {
+        /*
+        * This is because shm.nbufs is computed at startup, when
+        * we call shmget().  We can't increase the Q1/Q2 parameters
+        * beyond their initial values because then we might have
+        * more "Q2 messages" than shared memory chunks, and this
+        * will cause an assertion in storeDiskdShmGet().
+        */
+        /* TODO: have DiskdIO hold a link to the swapdir, to allow detailed reporting again */
+        debug(3, 1) ("WARNING: cannot increase cache_dir Q1 value while Squid is running.\n");
+        magic1 = old_magic1;
+        return true;
+    }
+
+    if (old_magic1 != magic1)
+        debug(3, 1) ("cache_dir new Q1 value '%d'\n",
+                     magic1);
+
+    return true;
+}
+
+void
+DiskdIO::optionQ1Dump(StoreEntry * e) const
+{
+    storeAppendPrintf(e, " Q1=%d", magic1);
+}
+
+bool
+DiskdIO::optionQ2Parse(const char *name, const char *value, int reconfiguring)
+{
+    if (strcmp(name, "Q2") != 0)
+        return false;
+
+    int old_magic2 = magic2;
+
+    magic2 = atoi(value);
+
+    if (!reconfiguring)
+        return true;
+
+    if (old_magic2 < magic2) {
+        /* See comments in Q1 function above */
+        debug(3, 1) ("WARNING: cannot increase cache_dir Q2 value while Squid is running.\n");
+        magic2 = old_magic2;
+        return true;
+    }
+
+    if (old_magic2 != magic2)
+        debug(3, 1) ("cache_dir new Q2 value '%d'\n",
+                     magic2);
+
+    return true;
+}
+
+void
+DiskdIO::optionQ2Dump(StoreEntry * e) const
+{
+    storeAppendPrintf(e, " Q2=%d", magic2);
+}
+
+void
+DiskdIO::init()
+{
+    int x;
+    int rfd;
+    int ikey;
+    const char *args[5];
+    char skey1[32];
+    char skey2[32];
+    char skey3[32];
+
+    ikey = (getpid() << 10) + (instanceID << 2);
+    ikey &= 0x7fffffff;
+    smsgid = msgget((key_t) ikey, 0700 | IPC_CREAT);
+
+    if (smsgid < 0) {
+        debug(50, 0) ("storeDiskdInit: msgget: %s\n", xstrerror());
+        fatal("msgget failed");
+    }
+
+    rmsgid = msgget((key_t) (ikey + 1), 0700 | IPC_CREAT);
+
+    if (rmsgid < 0) {
+        debug(50, 0) ("storeDiskdInit: msgget: %s\n", xstrerror());
+        fatal("msgget failed");
+    }
+
+    shm.init(ikey, magic2);
+    snprintf(skey1, 32, "%d", ikey);
+    snprintf(skey2, 32, "%d", ikey + 1);
+    snprintf(skey3, 32, "%d", ikey + 2);
+    args[0] = "diskd";
+    args[1] = skey1;
+    args[2] = skey2;
+    args[3] = skey3;
+    args[4] = NULL;
+    x = ipcCreate(IPC_STREAM,
+                  Config.Program.diskd,
+                  args,
+                  "diskd",
+                  &rfd,
+                  &wfd);
 
+    if (x < 0)
+        fatalf("execl: %s", Config.Program.diskd);
+
+    if (rfd != wfd)
+        comm_close(rfd);
+
+    fd_note(wfd, "squid -> diskd");
+
+    commSetTimeout(wfd, -1, NULL, NULL);
+
+    commSetNonBlocking(wfd);
+
+    comm_quick_poll_required();
+}
+
+/*
+ * Sync any pending data. We just sit around and read the queue
+ * until the data has finished writing.
+ */
+void
+DiskdIO::sync()
+{
+    static time_t lastmsg = 0;
+
+    while (away > 0) {
+        if (squid_curtime > lastmsg) {
+            debug(47, 1) ("storeDiskdDirSync: %d messages away\n",
+                          away);
+            lastmsg = squid_curtime;
+        }
+
+        callback();
+    }
+}
+
+
+/*
+ * Handle callbacks. If we have more than magic2 requests away, we block
+ * until the queue is below magic2. Otherwise, we simply return when we
+ * don't get a message.
+ */
+int
+DiskdIO::callback()
+{
+    diomsg M;
+    int x;
+    int retval = 0;
+
+    DiskdIO *DIO = this;//dynamic_cast<DiskdIO *>(IO);
+
+    if (DIO->away >= DIO->magic2) {
+        diskd_stats.block_queue_len++;
+        retval = 1;
+        /* We might not have anything to do, but our queue
+         * is full.. */
+    }
+
+    if (diskd_stats.sent_count - diskd_stats.recv_count >
+            diskd_stats.max_away) {
+        diskd_stats.max_away = diskd_stats.sent_count - diskd_stats.recv_count;
+    }
+
+    while (1) {
+#ifdef	ALWAYS_ZERO_BUFFERS
+        memset(&M, '\0', sizeof(M));
+#endif
+
+        x = msgrcv(DIO->rmsgid, &M, msg_snd_rcv_sz, 0, IPC_NOWAIT);
+
+        if (x < 0)
+            break;
+        else if (x != msg_snd_rcv_sz) {
+            debug(47, 1) ("storeDiskdDirCallback: msgget returns %d\n",
+                          x);
+            break;
+        }
+
+        diskd_stats.recv_count++;
+        --DIO->away;
+        DIO->storeDiskdHandle(&M);
+        retval = 1;		/* Return that we've actually done some work */
+
+        if (M.shm_offset > -1)
+            DIO->shm.put ((off_t) M.shm_offset);
+    }
+
+    return retval;
+}
+
+void
+DiskdIO::statfs(StoreEntry & sentry)const
+{
+    storeAppendPrintf(&sentry, "Pending operations: %d\n", away);
+}
+
+DiskdIOModule::DiskdIOModule() : initialised(false) {}
+
+DiskdIOModule &
+DiskdIOModule::GetInstance()
+{
+    if (!Instance)
+        Instance = new DiskdIOModule;
+
+    return *Instance;
+}
+
+void
+DiskdIOModule::init()
+{
+    /* We may be reused - for instance in coss - eventually.
+     * When we do, we either need per-using-module stats (
+     * no singleton pattern), or we need to refcount the 
+     * initialisation level and handle multiple clients.
+     * RBC - 20030718.
+     */
+    assert(!initialised);
+    memset(&diskd_stats, '\0', sizeof(diskd_stats));
+    cachemgrRegister("diskd", "DISKD Stats", storeDiskdStats, 0, 1);
+
+    debug(47, 1) ("diskd started\n");
+    initialised = true;
+}
+
+void
+DiskdIOModule::shutdown()
+{
+    initialised = false;
+}
+
+UFSStrategy *
+DiskdIOModule::createSwapDirIOStrategy()
+{
+    return new DiskdIO;
+}
+
+DiskdIOModule *DiskdIOModule::Instance = NULL;
+
+diskd_stats_t diskd_stats;
+
+void
+storeDiskdStats(StoreEntry * sentry)
+{
+    storeAppendPrintf(sentry, "sent_count: %d\n", diskd_stats.sent_count);
+    storeAppendPrintf(sentry, "recv_count: %d\n", diskd_stats.recv_count);
+    storeAppendPrintf(sentry, "max_away: %d\n", diskd_stats.max_away);
+    storeAppendPrintf(sentry, "max_shmuse: %d\n", diskd_stats.max_shmuse);
+    storeAppendPrintf(sentry, "open_fail_queue_len: %d\n", diskd_stats.open_fail_queue_len);
+    storeAppendPrintf(sentry, "block_queue_len: %d\n", diskd_stats.block_queue_len);
+    diskd_stats.max_away = diskd_stats.max_shmuse = 0;
+    storeAppendPrintf(sentry, "\n             OPS SUCCESS    FAIL\n");
+    storeAppendPrintf(sentry, "%7s %7d %7d %7d\n",
+                      "open", diskd_stats.open.ops, diskd_stats.open.success, diskd_stats.open.fail);
+    storeAppendPrintf(sentry, "%7s %7d %7d %7d\n",
+                      "create", diskd_stats.create.ops, diskd_stats.create.success, diskd_stats.create.fail);
+    storeAppendPrintf(sentry, "%7s %7d %7d %7d\n",
+                      "close", diskd_stats.close.ops, diskd_stats.close.success, diskd_stats.close.fail);
+    storeAppendPrintf(sentry, "%7s %7d %7d %7d\n",
+                      "unlink", diskd_stats.unlink.ops, diskd_stats.unlink.success, diskd_stats.unlink.fail);
+    storeAppendPrintf(sentry, "%7s %7d %7d %7d\n",
+                      "read", diskd_stats.read.ops, diskd_stats.read.success, diskd_stats.read.fail);
+    storeAppendPrintf(sentry, "%7s %7d %7d %7d\n",
+                      "write", diskd_stats.write.ops, diskd_stats.write.success, diskd_stats.write.fail);
+}
