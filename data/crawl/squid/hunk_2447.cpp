         fatal("COSS requires max-size to be set to something other than -1!\n");
 }
 
+void
+CossSwapDir::swappedOut(const StoreEntry &e)
+{
+    cur_size += fs.blksize * sizeInBlocks(e.swap_file_sz);
+    ++n_disk_objects;
+}
+
 void
 CossSwapDir::dump(StoreEntry &entry)const
 {
-    storeAppendPrintf(&entry, " %lu", (max_size >> 10));
+    storeAppendPrintf(&entry, " %"PRIu64, maxSize() >> 20);
     dumpOptions(&entry);
 }
 
-CossSwapDir::CossSwapDir() : SwapDir ("coss"), swaplog_fd(-1), count(0), current_membuf (NULL), current_offset(0), numcollisions(0),  blksz_bits(0), io (NULL), ioModule(NULL), currentIOOptions(new ConfigOptionVector()), stripe_path(NULL)
+CossSwapDir::CossSwapDir() : SwapDir ("coss"), swaplog_fd(-1), count(0), current_membuf (NULL), current_offset(0), numcollisions(0),  blksz_bits(0), io (NULL), ioModule(NULL), currentIOOptions(new ConfigOptionVector()), stripe_path(NULL), cur_size(0), n_disk_objects(0)
 {
     membufs.head = NULL;
     membufs.tail = NULL;
