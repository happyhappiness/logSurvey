 void
 DelayTaggedBucket::stats (StoreEntry *entry) const
 {
-    storeAppendPrintf(entry, " %s:", tag.buf());
+    storeAppendPrintf(entry, " %s:", tag.c_str());
     theBucket.stats (entry);
 }
 
-DelayTagged::Id::Id(DelayTagged::Pointer aDelayTagged, String &aTag) : theTagged(aDelayTagged)
+DelayTagged::Id::Id(DelayTagged::Pointer aDelayTagged, string &aTag) : theTagged(aDelayTagged)
 {
     theBucket = new DelayTaggedBucket(aTag);
     DelayTaggedBucket::Pointer const *existing = theTagged->buckets.find(theBucket, DelayTaggedCmp);
