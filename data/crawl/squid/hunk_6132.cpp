 eventDump(StoreEntry * sentry)
 {
     struct ev_entry *e = tasks;
-    storeAppendPrintf(sentry, "%s\t%s\n",
+    storeAppendPrintf(sentry, "%s\t%s\t%s\n",
 	"Operation",
-	"Next Execution");
+	"Next Execution",
+	"Weight");
     while (e != NULL) {
-	storeAppendPrintf(sentry, "%s\t%f seconds\n",
-	    e->name, e->when - current_dtime);
+	storeAppendPrintf(sentry, "%s\t%f seconds\t%d\n",
+	    e->name, e->when - current_dtime, e->weight);
 	e = e->next;
     }
 }