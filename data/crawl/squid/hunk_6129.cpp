 eventDump(StoreEntry * sentry)
 {
     struct ev_entry *e = tasks;
+    if (last_event_ran)
+	storeAppendPrintf(sentry, "Last event to run: %s\n\n", last_event_ran);
     storeAppendPrintf(sentry, "%s\t%s\t%s\t%s\n",
 	"Operation",
 	"Next Execution",