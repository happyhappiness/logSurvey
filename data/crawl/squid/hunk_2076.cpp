 }
 
 int
-UFSSwapDir::callback()
+Fs::Ufs::UFSSwapDir::callback()
 {
     return IO->callback();
 }
 
 void
-UFSSwapDir::sync()
+Fs::Ufs::UFSSwapDir::sync()
 {
     IO->sync();
 }
 
 void
-UFSSwapDir::swappedOut(const StoreEntry &e)
+Fs::Ufs::UFSSwapDir::swappedOut(const StoreEntry &e)
 {
     cur_size += fs.blksize * sizeInBlocks(e.swap_file_sz);
     ++n_disk_objects;
 }
 
 StoreSearch *
-UFSSwapDir::search(String const url, HttpRequest *request)
+Fs::Ufs::UFSSwapDir::search(String const url, HttpRequest *request)
 {
     if (url.size())
         fatal ("Cannot search by url yet\n");
 
-    return new StoreSearchUFS (this);
-}
-
-CBDATA_CLASS_INIT(StoreSearchUFS);
-StoreSearchUFS::StoreSearchUFS(RefCount<UFSSwapDir> aSwapDir) : sd(aSwapDir), walker (sd->repl->WalkInit(sd->repl)), current (NULL), _done (false)
-{}
-
-/* do not link
-StoreSearchUFS::StoreSearchUFS(StoreSearchUFS const &);
-*/
-
-StoreSearchUFS::~StoreSearchUFS()
-{
-    walker->Done(walker);
-    walker = NULL;
+    return new Fs::Ufs::StoreSearchUFS (this);
 }
 
 void
-StoreSearchUFS::next(void (aCallback)(void *cbdata), void *aCallbackArgs)
+Fs::Ufs::UFSSwapDir::logEntry(const StoreEntry & e, int op) const
 {
-    next();
-    aCallback(aCallbackArgs);
+    StoreSwapLogData *s = new StoreSwapLogData;
+    s->op = (char) op;
+    s->swap_filen = e.swap_filen;
+    s->timestamp = e.timestamp;
+    s->lastref = e.lastref;
+    s->expires = e.expires;
+    s->lastmod = e.lastmod;
+    s->swap_file_sz = e.swap_file_sz;
+    s->refcount = e.refcount;
+    s->flags = e.flags;
+    memcpy(s->key, e.key, SQUID_MD5_DIGEST_LENGTH);
+    s->finalize();
+    file_write(swaplog_fd,
+               -1,
+               s,
+               sizeof(StoreSwapLogData),
+               NULL,
+               NULL,
+               FreeObject);
 }
 
-bool
-StoreSearchUFS::next()
+int
+Fs::Ufs::UFSSwapDir::DirClean(int swap_index)
 {
-    /* the walker API doesn't make sense. the store entries referred to are already readwrite
-     * from their hash table entries
-     */
+    DIR *dir_pointer = NULL;
 
-    if (walker)
-        current = const_cast<StoreEntry *>(walker->Next(walker));
+    LOCAL_ARRAY(char, p1, MAXPATHLEN + 1);
+    LOCAL_ARRAY(char, p2, MAXPATHLEN + 1);
 
-    if (current == NULL)
-        _done = true;
+    int files[20];
+    int swapfileno;
+    int fn;         /* same as swapfileno, but with dirn bits set */
+    int n = 0;
+    int k = 0;
+    int N0, N1, N2;
+    int D0, D1, D2;
+    UFSSwapDir *SD;
+    N0 = NumberOfUFSDirs;
+    D0 = UFSDirToGlobalDirMapping[swap_index % N0];
+    SD = dynamic_cast<UFSSwapDir *>(INDEXSD(D0));
+    assert (SD);
+    N1 = SD->l1;
+    D1 = (swap_index / N0) % N1;
+    N2 = SD->l2;
+    D2 = ((swap_index / N0) / N1) % N2;
+    snprintf(p1, MAXPATHLEN, "%s/%02X/%02X",
+             SD->path, D1, D2);
+    debugs(36, 3, HERE << "Cleaning directory " << p1);
+    dir_pointer = opendir(p1);
 
-    return current != NULL;
-}
+    if (dir_pointer == NULL) {
+        if (errno == ENOENT) {
+            debugs(36, DBG_CRITICAL, HERE << "WARNING: Creating " << p1);
+#if _SQUID_MSWIN_
 
-bool
-StoreSearchUFS::error() const
-{
-    return false;
-}
+            if (mkdir(p1) == 0)
+#else
 
-bool
-StoreSearchUFS::isDone() const
-{
-    return _done;
-}
+            if (mkdir(p1, 0777) == 0)
+#endif
 
-StoreEntry *
-StoreSearchUFS::currentItem()
-{
-    return current;
+                return 0;
+        }
+
+        debugs(50, DBG_CRITICAL, HERE << p1 << ": " << xstrerror());
+        safeunlink(p1, 1);
+        return 0;
+    }
+
+    dirent_t *de;
+    while ((de = readdir(dir_pointer)) != NULL && k < 20) {
+        if (sscanf(de->d_name, "%X", &swapfileno) != 1)
+            continue;
+
+        fn = swapfileno;    /* XXX should remove this cruft ! */
+
+        if (SD->validFileno(fn, 1))
+            if (SD->mapBitTest(fn))
+                if (UFSSwapDir::FilenoBelongsHere(fn, D0, D1, D2))
+                    continue;
+
+        files[k] = swapfileno;
+        ++k;
+    }
+
+    closedir(dir_pointer);
+
+    if (k == 0)
+        return 0;
+
+    qsort(files, k, sizeof(int), rev_int_sort);
+
+    if (k > 10)
+        k = 10;
+
+    for (n = 0; n < k; ++n) {
+        debugs(36, 3, HERE << "Cleaning file "<< std::setfill('0') << std::hex << std::uppercase << std::setw(8) << files[n]);
+        snprintf(p2, MAXPATHLEN + 1, "%s/%08X", p1, files[n]);
+        safeunlink(p2, 0);
+        ++statCounter.swap.files_cleaned;
+    }
+
+    debugs(36, 3, HERE << "Cleaned " << k << " unused files from " << p1);
+    return k;
 }
