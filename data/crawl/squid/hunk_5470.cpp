  *
  * This routine is called when the given swapdir needs reconfiguring 
  */
-static void
-storeDiskdDirReconfigure(SwapDir * sd, int index, char *path)
+void
+DiskdSwapDir::reconfigure(int anIndex, char *aPath)
 {
-    int i;
-    int size;
-    int l1;
-    int l2;
-
-    i = GetInteger();
-    size = i << 10;		/* Mbytes to kbytes */
-    if (size <= 0)
-	fatal("storeDiskdDirReconfigure: invalid size value");
-    i = GetInteger();
-    l1 = i;
-    if (l1 <= 0)
-	fatal("storeDiskdDirReconfigure: invalid level 1 directories value");
-    i = GetInteger();
-    l2 = i;
-    if (l2 <= 0)
-	fatal("storeDiskdDirReconfigure: invalid level 2 directories value");
-
-    /* just reconfigure it */
-    if (size == sd->max_size)
-	debug(3, 1) ("Cache dir '%s' size remains unchanged at %d KB\n",
-	    path, size);
-    else
-	debug(3, 1) ("Cache dir '%s' size changed to %d KB\n",
-	    path, size);
-    sd->max_size = size;
-    parse_cachedir_options(sd, options, 1);
+    UFSSwapDir::reconfigure (anIndex, aPath);
+
+    parse_cachedir_options(this, options, 1);
 }
 
 void
-storeDiskdDirDump(StoreEntry * entry, SwapDir * s)
+DiskdSwapDir::dump(StoreEntry & entry)const
 {
-    commonUfsDirDump (entry, s);
-    dump_cachedir_options(entry, options, s);
+    UFSSwapDir::dump (entry);
+    dump_cachedir_options(&entry, options, this);
 }
 
 /*
  * storeDiskdDirParse
  *
  * Called when a *new* fs is being setup.
  */
-static void
-storeDiskdDirParse(SwapDir * sd, int index, char *path)
+void
+DiskdSwapDir::parse(int anIndex, char *aPath)
 {
-    int i;
-    int size;
-    int l1;
-    int l2;
-    diskdinfo_t *diskdinfo;
-
-    i = GetInteger();
-    size = i << 10;		/* Mbytes to kbytes */
-    if (size <= 0)
-	fatal("storeDiskdDirParse: invalid size value");
-    i = GetInteger();
-    l1 = i;
-    if (l1 <= 0)
-	fatal("storeDiskdDirParse: invalid level 1 directories value");
-    i = GetInteger();
-    l2 = i;
-    if (l2 <= 0)
-	fatal("storeDiskdDirParse: invalid level 2 directories value");
-
-    sd->fsdata = diskdinfo = (diskdinfo_t *)xcalloc(1, sizeof(*diskdinfo));
-    sd->index = index;
-    sd->path = xstrdup(path);
-    sd->max_size = size;
-    diskdinfo->commondata.l1 = l1;
-    diskdinfo->commondata.l2 = l2;
-    diskdinfo->commondata.swaplog_fd = -1;
-    diskdinfo->commondata.map = NULL;	/* Debugging purposes */
-    diskdinfo->commondata.suggest = 0;
-    diskdinfo->commondata.io.storeDirUnlinkFile = storeDiskdDirIOUnlinkFile;
-    diskdinfo->magic1 = 64;
-    diskdinfo->magic2 = 72;
-    sd->init = storeDiskdDirInit;
-    sd->newfs = commonUfsDirNewfs;
-    sd->dump = storeDiskdDirDump;
-    sd->freefs = commonUfsDirFree;
-    sd->dblcheck = commonUfsCleanupDoubleCheck;
-    sd->statfs = storeDiskdDirStats;
-    sd->maintainfs = commonUfsDirMaintain;
-    sd->checkobj = storeDiskdDirCheckObj;
-    sd->refobj = commonUfsDirRefObj;
-    sd->unrefobj = commonUfsDirUnrefObj;
-    sd->callback = storeDiskdDirCallback;
-    sd->sync = storeDiskdDirSync;
-    sd->obj.create = storeDiskdCreate;
-    sd->obj.open = storeDiskdOpen;
-    sd->obj.close = storeDiskdClose;
-    sd->obj.read = storeDiskdRead;
-    sd->obj.write = storeDiskdWrite;
-    sd->obj.unlink = storeDiskdUnlink;
-    sd->log.open = commonUfsDirOpenSwapLog;
-    sd->log.close = commonUfsDirCloseSwapLog;
-    sd->log.write = commonUfsDirSwapLog;
-    sd->log.clean.start = commonUfsDirWriteCleanStart;
-    sd->log.clean.nextentry = commonUfsDirCleanLogNextEntry;
-    sd->log.clean.done = commonUfsDirWriteCleanDone;
-
-    parse_cachedir_options(sd, options, 0);
-
-    /* Initialise replacement policy stuff */
-    sd->repl = createRemovalPolicy(Config.replPolicy);
+    UFSSwapDir::parse(anIndex, aPath);
+
+    parse_cachedir_options(this, options, 0);
 }
 
 /*
