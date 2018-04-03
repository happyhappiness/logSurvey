 
     assert (dynamic_cast<UFSSwapDir *>(SD.getRaw()) == this);
 
-    debugs(47, 4, "UFSSwapDir::replacementRemove: remove node " << e << " from dir " << index);
+    debugs(47, 4, HERE << "remove node " << e << " from dir " << index);
 
     repl->Remove(repl, e, &e->repl);
 }
 
 void
-UFSSwapDir::dump(StoreEntry & entry) const
+Fs::Ufs::UFSSwapDir::dump(StoreEntry & entry) const
 {
     storeAppendPrintf(&entry, " %" PRIu64 " %d %d", maxSize() >> 20, l1, l2);
     dumpOptions(&entry);
 }
 
 char *
-UFSSwapDir::fullPath(sfileno filn, char *fullpath) const
+Fs::Ufs::UFSSwapDir::fullPath(sfileno filn, char *fullpath) const
 {
     LOCAL_ARRAY(char, fullfilename, MAXPATHLEN);
     int L1 = l1;
