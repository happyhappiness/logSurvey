  *
  * This routine is called when the given swapdir needs reconfiguring 
  */
-static void
-storeAufsDirReconfigure(SwapDir * sd, int index, char *path)
+void
+AUFSSwapDir::reconfigure(int anIndex, char *aPath)
 {
-    int i;
-    int size;
-    int l1;
-    int l2;
-
-    i = GetInteger();
-    size = i << 10;		/* Mbytes to kbytes */
-    if (size <= 0)
-	fatal("storeAufsDirReconfigure: invalid size value");
-    i = GetInteger();
-    l1 = i;
-    if (l1 <= 0)
-	fatal("storeAufsDirReconfigure: invalid level 1 directories value");
-    i = GetInteger();
-    l2 = i;
-    if (l2 <= 0)
-	fatal("storeAufsDirReconfigure: invalid level 2 directories value");
-
-    /* just reconfigure it */
-    if (size == sd->max_size)
-	debug(3, 1) ("Cache dir '%s' size remains unchanged at %d KB\n",
-	    path, size);
-    else
-	debug(3, 1) ("Cache dir '%s' size changed to %d KB\n",
-	    path, size);
-    sd->max_size = size;
-
-    parse_cachedir_options(sd, options, 0);
-
-    return;
+    UFSSwapDir::reconfigure (anIndex, aPath);
+
+    parse_cachedir_options(this, options, 0);
 }
 
 void
-storeAufsDirDump(StoreEntry * entry, SwapDir * s)
+AUFSSwapDir::dump(StoreEntry & entry) const
 {
-    commonUfsDirDump(entry, s);
-    dump_cachedir_options(entry, options, s);
+    UFSSwapDir::dump(entry);
+    dump_cachedir_options(&entry, options, this);
 }
 
 /*
  * storeAufsDirParse *
  * Called when a *new* fs is being setup.
  */
-static void
-storeAufsDirParse(SwapDir * sd, int index, char *path)
+void
+AUFSSwapDir::parse(int anIndex, char *aPath)
 {
-    int i;
-    int size;
-    int l1;
-    int l2;
-    squidufsinfo_t *aioinfo;
-
-    i = GetInteger();
-    size = i << 10;		/* Mbytes to kbytes */
-    if (size <= 0)
-	fatal("storeAufsDirParse: invalid size value");
-    i = GetInteger();
-    l1 = i;
-    if (l1 <= 0)
-	fatal("storeAufsDirParse: invalid level 1 directories value");
-    i = GetInteger();
-    l2 = i;
-    if (l2 <= 0)
-	fatal("storeAufsDirParse: invalid level 2 directories value");
-
-    aioinfo = (squidufsinfo_t *)xmalloc(sizeof(squidufsinfo_t));
-    if (aioinfo == NULL)
-	fatal("storeAufsDirParse: couldn't xmalloc() squidufsinfo_t!\n");
-
-    sd->index = index;
-    sd->path = xstrdup(path);
-    sd->max_size = size;
-    sd->fsdata = aioinfo;
-    aioinfo->l1 = l1;
-    aioinfo->l2 = l2;
-    aioinfo->swaplog_fd = -1;
-    aioinfo->map = NULL;	/* Debugging purposes */
-    aioinfo->suggest = 0;
-    aioinfo->io.storeDirUnlinkFile = storeAufsDirIOUnlinkFile;
-    sd->init = commonUfsDirInit;
-    sd->newfs = commonUfsDirNewfs;
-    sd->dump = storeAufsDirDump;
-    sd->freefs = commonUfsDirFree;
-    sd->dblcheck = commonUfsCleanupDoubleCheck;
-    sd->statfs = commonUfsDirStats;
-    sd->maintainfs = commonUfsDirMaintain;
-    sd->checkobj = storeAufsDirCheckObj;
-    sd->refobj = commonUfsDirRefObj;
-    sd->unrefobj = commonUfsDirUnrefObj;
-    sd->callback = aioCheckCallbacks;
-    sd->sync = aioSync;
-    sd->obj.create = storeAufsCreate;
-    sd->obj.open = storeAufsOpen;
-    sd->obj.close = storeAufsClose;
-    sd->obj.read = storeAufsRead;
-    sd->obj.write = storeAufsWrite;
-    sd->obj.unlink = storeAufsUnlink;
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
