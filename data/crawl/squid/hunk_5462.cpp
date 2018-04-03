     return path;
 }
 
-static void
-storeCossDirOpenSwapLog(SwapDir * sd)
+void
+CossSwapDir::openLog()
 {
-    CossInfo *cs = (CossInfo *) sd->fsdata;
-    char *path;
-    int fd;
-    path = storeCossDirSwapLogFile(sd, NULL);
-    fd = file_open(path, O_WRONLY | O_CREAT | O_BINARY);
-    if (fd < 0) {
-	debug(47, 1) ("%s: %s\n", path, xstrerror());
+    char *logPath;
+    logPath = storeCossDirSwapLogFile(this, NULL);
+    swaplog_fd = file_open(logPath, O_WRONLY | O_CREAT | O_BINARY);
+    if (swaplog_fd < 0) {
+	debug(47, 1) ("%s: %s\n", logPath, xstrerror());
 	fatal("storeCossDirOpenSwapLog: Failed to open swap log.");
     }
-    debug(47, 3) ("Cache COSS Dir #%d log opened on FD %d\n", sd->index, fd);
-    cs->swaplog_fd = fd;
+    debug(47, 3) ("Cache COSS Dir #%d log opened on FD %d\n", index, swaplog_fd);
 }
 
-static void
-storeCossDirCloseSwapLog(SwapDir * sd)
+void
+CossSwapDir::closeLog()
 {
-    CossInfo *cs = (CossInfo *) sd->fsdata;
-    if (cs->swaplog_fd < 0)	/* not open */
+    if (swaplog_fd < 0)	/* not open */
 	return;
-    file_close(cs->swaplog_fd);
+    file_close(swaplog_fd);
     debug(47, 3) ("Cache COSS Dir #%d log closed on FD %d\n",
-	sd->index, cs->swaplog_fd);
-    cs->swaplog_fd = -1;
+	index, swaplog_fd);
+    swaplog_fd = -1;
 }
 
-static void
-storeCossDirInit(SwapDir * sd)
-{
-    CossInfo *cs = (CossInfo *) sd->fsdata;
-    a_file_setupqueue(&cs->aq);
-    storeCossDirOpenSwapLog(sd);
-    storeCossDirRebuild(sd);
-    cs->fd = file_open(sd->path, O_RDWR | O_CREAT);
-    if (cs->fd < 0) {
-	debug(47, 1) ("%s: %s\n", sd->path, xstrerror());
+void
+CossSwapDir::init()
+{
+    a_file_setupqueue(&aq);
+    openLog();
+    storeCossDirRebuild(this);
+    fd = file_open(path, O_RDWR | O_CREAT);
+    if (fd < 0) {
+	debug(47, 1) ("%s: %s\n", path, xstrerror());
 	fatal("storeCossDirInit: Failed to open a COSS directory.");
     }
     n_coss_dirs++;
-    (void) storeDirGetBlkSize(sd->path, &sd->fs.blksize);
+    (void) storeDirGetBlkSize(path, &fs.blksize);
 }
 
 void
-storeCossRemove(SwapDir * sd, StoreEntry * e)
+storeCossRemove(CossSwapDir * sd, StoreEntry * e)
 {
-    CossInfo *cs = (CossInfo *) sd->fsdata;
     CossIndexNode *coss_node = (CossIndexNode *)e->repl.data;
     e->repl.data = NULL;
-    dlinkDelete(&coss_node->node, &cs->index);
+    dlinkDelete(&coss_node->node, &sd->cossindex);
     memPoolFree(coss_index_pool, coss_node);
-    cs->count -= 1;
+    sd->count -= 1;
 }
 
 void
-storeCossAdd(SwapDir * sd, StoreEntry * e)
+storeCossAdd(CossSwapDir * sd, StoreEntry * e)
 {
-    CossInfo *cs = (CossInfo *) sd->fsdata;
     CossIndexNode *coss_node = (CossIndexNode *)memPoolAlloc(coss_index_pool);
     assert(!e->repl.data);
     e->repl.data = coss_node;
-    dlinkAdd(e, &coss_node->node, &cs->index);
-    cs->count += 1;
+    dlinkAdd(e, &coss_node->node, &sd->cossindex);
+    sd->count += 1;
 }
 
 static void
 storeCossRebuildComplete(void *data)
 {
     RebuildState *rb = (RebuildState *)data;
-    SwapDir *sd = rb->sd;
+    CossSwapDir *sd = rb->sd;
     storeCossStartMembuf(sd);
     store_dirs_rebuilding--;
     storeCossDirCloseTmpSwapLog(rb->sd);
