         assert(anchor.basics.swap_file_sz != static_cast<uint64_t>(-1));
         // perhaps we loaded a later slot (with entrySize) earlier
         totalSize = anchor.basics.swap_file_sz;
-    } else
-    if (totalSize && !anchor.basics.swap_file_sz) {
+    } else if (totalSize && !anchor.basics.swap_file_sz) {
         anchor.basics.swap_file_sz = totalSize;
         assert(anchor.basics.swap_file_sz != static_cast<uint64_t>(-1));
-    } else
-    if (totalSize != anchor.basics.swap_file_sz) {
+    } else if (totalSize != anchor.basics.swap_file_sz) {
         le.state = LoadingEntry::leCorrupted;
         freeBadEntry(fileno, "size mismatch");
         return;
