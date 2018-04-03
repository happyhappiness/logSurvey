 void
 DelayTaggedBucket::stats (StoreEntry *entry) const
 {
-    storeAppendPrintf(entry, " %s:", tag.unsafeBuf());
+    storeAppendPrintf(entry, " " SQUIDSTRINGPH , SQUIDSTRINGPRINT(tag));
     theBucket.stats (entry);
 }
 
