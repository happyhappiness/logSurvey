     statCounter.aborted_requests++;
     storeAbort(entry);
 }
+
+void
+storeClientDumpStats(store_client * thisClient, StoreEntry * output, int clientNumber)
+{
+    if (thisClient->callback_data == NULL)
+	return;
+    storeAppendPrintf(output, "\tClient #%d, %p\n", clientNumber, thisClient->callback_data);
+    storeAppendPrintf(output, "\t\tcopy_offset: %lu\n",
+	thisClient->copyInto.offset);
+    storeAppendPrintf(output, "\t\tcopy_size: %d\n",
+	(int) thisClient->copyInto.length);
+    storeAppendPrintf(output, "\t\tflags:");
+    if (thisClient->flags.disk_io_pending)
+	storeAppendPrintf(output, " disk_io_pending");
+    if (thisClient->flags.store_copying)
+	storeAppendPrintf(output, " store_copying");
+    if (thisClient->flags.copy_event_pending)
+	storeAppendPrintf(output, " copy_event_pending");
+    storeAppendPrintf(output, "\n");
+
+}
