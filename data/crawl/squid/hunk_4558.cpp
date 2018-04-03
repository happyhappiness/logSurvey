 void
 DelayTaggedBucket::stats (StoreEntry *entry) const
 {
-    storeAppendPrintf(entry, " %s:", tag.c_str());
+    storeAppendPrintf(entry, " %s:", tag.buf());
     theBucket.stats (entry);
 }
 
-DelayTagged::Id::Id(DelayTagged::Pointer aDelayTagged, string &aTag) : theTagged(aDelayTagged)
+DelayTagged::Id::Id(DelayTagged::Pointer aDelayTagged, String &aTag) : theTagged(aDelayTagged)
 {
     theBucket = new DelayTaggedBucket(aTag);
     DelayTaggedBucket::Pointer const *existing = theTagged->buckets.find(theBucket, DelayTaggedCmp);
