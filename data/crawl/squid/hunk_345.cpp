     }
 }
 
+/// Either make the entry accessible to all or throw.
+/// This method assumes it is called only when no more entry slots are expected.
+void
+Rock::Rebuild::finalizeOrThrow(const sfileno fileNo, LoadingEntry &le)
+{
+    // walk all map-linked slots, starting from inode, and mark each
+    Ipc::StoreMapAnchor &anchor = sd->map->writeableEntry(fileNo);
+    Must(le.size > 0); // paranoid
+    uint64_t mappedSize = 0;
+    SlotId slotId = anchor.start;
+    while (slotId >= 0 && mappedSize < le.size) {
+        LoadingSlot slot = loadingSlot(slotId); // throws if we have not loaded that slot
+        Must(!slot.finalized()); // no loops or stealing from other entries
+        Must(slot.mapped()); // all our slots should be in the sd->map
+        Must(!slot.freed()); // all our slots should still be present
+        slot.finalized(true);
+
+        Ipc::StoreMapSlice &mapSlice = sd->map->writeableSlice(fileNo, slotId);
+        Must(mapSlice.size > 0); // paranoid
+        mappedSize += mapSlice.size;
+        slotId = mapSlice.next;
+    }
+    /* no hodgepodge entries: one entry - one full chain and no leftovers */
+    Must(slotId < 0);
+    Must(mappedSize == le.size);
+
+    if (!anchor.basics.swap_file_sz)
+        anchor.basics.swap_file_sz = le.size;
+    EBIT_SET(anchor.basics.flags, ENTRY_VALIDATED);
+    le.state(LoadingEntry::leLoaded);
+    sd->map->closeForWriting(fileNo, false);
+    ++counts.objcount;
+}
+
+/// Either make the entry accessible to all or free it.
+/// This method must only be called when no more entry slots are expected.
 void
-Rock::Rebuild::validateOneEntry()
+Rock::Rebuild::finalizeOrFree(const sfileno fileNo, LoadingEntry &le)
 {
-    LoadingEntry &e = entries[validationPos];
-    switch (e.state) {
+    try {
+        finalizeOrThrow(fileNo, le);
+    } catch (const std::exception &ex) {
+        freeBadEntry(fileNo, ex.what());
+    }
+}
 
-    case LoadingEntry::leEmpty:
-        break; // no entry hashed to this position
+void
+Rock::Rebuild::validateOneEntry(const sfileno fileNo)
+{
+    LoadingEntry entry = loadingEntry(fileNo);
+    switch (entry.state()) {
 
     case LoadingEntry::leLoading:
-        freeBadEntry(validationPos, "partially stored");
+        finalizeOrFree(fileNo, entry);
         break;
 
-    case LoadingEntry::leLoaded:
-        break; // we have already unlocked this entry
-
-    case LoadingEntry::leCorrupted:
-        break; // we have already removed this entry
+    case LoadingEntry::leEmpty: // no entry hashed to this position
+    case LoadingEntry::leLoaded: // we have already unlocked this entry
+    case LoadingEntry::leCorrupted: // we have already removed this entry
+    case LoadingEntry::leIgnored: // we have already discarded this entry
+        break;
     }
 }
 
+void
+Rock::Rebuild::validateOneSlot(const SlotId slotId)
+{
+    const LoadingSlot slot = loadingSlot(slotId);
+    // there should not be any unprocessed slots left
+    Must(slot.freed() || (slot.mapped() && slot.finalized()));
+}
+
 /// Marks remaining bad entry slots as free and unlocks the entry. The map
 /// cannot do this because Loading entries may have holes in the slots chain.
 void
