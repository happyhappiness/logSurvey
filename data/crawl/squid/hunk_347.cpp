     } else {
         // A new from-network entry is occupying our map slot; let it be, but
         // save us from the trouble of going through the above motions again.
-        LoadingEntry &le = entries[fileno];
-        le.state = LoadingEntry::leIgnored;
-        freeSlotIfIdle(slotId, false);
+        LoadingEntry le = loadingEntry(fileno);
+        le.state(LoadingEntry::leIgnored);
+        freeUnusedSlot(slotId, false);
     }
 }
 
 /// does the header belong to the fileno entry being loaded?
 bool
 Rock::Rebuild::sameEntry(const sfileno fileno, const DbCellHeader &header) const
 {
+    // Header updates always result in multi-start chains and often
+    // result in multi-version chains so we can only compare the keys.
     const Ipc::StoreMap::Anchor &anchor = sd->map->writeableEntry(fileno);
-    const LoadingEntry &le = entries[fileno];
-    // any order will work, but do fast comparisons first:
-    return le.version == header.version &&
-           anchor.start == static_cast<Ipc::StoreMapSliceId>(header.firstSlot) &&
-           anchor.sameKey(reinterpret_cast<const cache_key*>(header.key));
-}
-
-/// is the new header consistent with information already loaded?
-bool
-Rock::Rebuild::canAdd(const sfileno fileno, const SlotId slotId, const DbCellHeader &header) const
-{
-    if (!sameEntry(fileno, header)) {
-        debugs(79, 7, "cannot add; wrong entry");
-        return false;
-    }
-
-    const LoadingEntry &le = entries[slotId];
-    // We cannot add a slot that was already declared free or mapped.
-    if (le.freed || le.mapped) {
-        debugs(79, 7, "cannot add; freed/mapped: " << le.freed << le.mapped);
-        return false;
-    }
-
-    if (slotId == header.firstSlot) {
-        // If we are the inode, the anchored flag cannot be set yet.
-        if (entries[fileno].anchored) {
-            debugs(79, 7, "cannot add; extra anchor");
-            return false;
-        }
-
-        // And there should have been some other slot for this entry to exist.
-        if (le.more < 0) {
-            debugs(79, 7, "cannot add; missing slots");
-            return false;
-        }
-
-        return true;
-    }
-
-    // We are the continuation slice so the more field is reserved for us.
-    if (le.more >= 0) {
-        debugs(79, 7, "cannot add; foreign slot");
-        return false;
-    }
-
-    return true;
+    return anchor.sameKey(reinterpret_cast<const cache_key*>(header.key));
 }
 
 /// handle freshly loaded (and validated) db slot header
 void
 Rock::Rebuild::useNewSlot(const SlotId slotId, const DbCellHeader &header)
 {
-    LoadingEntry &slice = entries[slotId];
-    assert(!slice.freed); // we cannot free what was not loaded
-
     const cache_key *const key =
         reinterpret_cast<const cache_key*>(header.key);
-    const sfileno fileno = sd->map->anchorIndexByKey(key);
+    const sfileno fileno = sd->map->fileNoByKey(key);
     assert(0 <= fileno && fileno < dbEntryLimit);
 
-    LoadingEntry &le = entries[fileno];
-    debugs(47,9, "entry " << fileno << " state: " << le.state << ", inode: " <<
+    LoadingEntry le = loadingEntry(fileno);
+    debugs(47,9, "entry " << fileno << " state: " << le.state() << ", inode: " <<
            header.firstSlot << ", size: " << header.payloadSize);
 
-    switch (le.state) {
+    switch (le.state()) {
 
     case LoadingEntry::leEmpty: {
         startNewEntry(fileno, slotId, header);
         break;
     }
 
     case LoadingEntry::leLoading: {
-        if (canAdd(fileno, slotId, header)) {
-            addSlotToEntry(fileno, slotId, header);
+        if (sameEntry(fileno, header)) {
+            addSlotToEntry(fileno, slotId, header); // may fail
         } else {
             // either the loading chain or this slot is stale;
             // be conservative and ignore both (and any future ones)
-            le.state = LoadingEntry::leCorrupted;
             freeBadEntry(fileno, "duplicated");
-            freeSlotIfIdle(slotId, slotId == header.firstSlot);
+            freeUnusedSlot(slotId, true);
             ++counts.dupcount;
         }
         break;
