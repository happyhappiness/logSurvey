             storeAppendPrintf(&e, "Current entries: %9d %.2f%%\n",
                               entryCount, (100.0 * entryCount / limit));
 
+            const unsigned int slotsFree = !freeSlots ? 0 : freeSlots->size();
+            if (slotsFree <= static_cast<const unsigned int>(limit)) {
+                const int usedSlots = limit - static_cast<const int>(slotsFree);
+                storeAppendPrintf(&e, "Used slots:      %9d %.2f%%\n",
+                                  usedSlots, (100.0 * usedSlots / limit));
+            }
             if (limit < 100) { // XXX: otherwise too expensive to count
                 Ipc::ReadWriteLockStats stats;
                 map->updateStats(stats);
