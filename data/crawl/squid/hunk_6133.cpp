     int i;
     storeAppendPrintf(sentry, "Internal DNS Statistics:\n");
     storeAppendPrintf(sentry, "\nThe Queue:\n");
-    storeAppendPrintf(sentry, "  ID   SIZE SENDS   DELAY\n");
-    storeAppendPrintf(sentry, "------ ---- ----- --------\n");
+    storeAppendPrintf(sentry, "                       DELAY SINCE\n");
+    storeAppendPrintf(sentry, "  ID   SIZE SENDS FIRST SEND LAST SEND\n");
+    storeAppendPrintf(sentry, "------ ---- ----- ---------- ---------\n");
     for (n = lru_list.head; n; n = n->next) {
 	q = n->data;
-	storeAppendPrintf(sentry, "%#06x %4d %5d %8.3f\n",
+	storeAppendPrintf(sentry, "%#06x %4d %5d %10.3f %9.3f\n",
 	    (int) q->id, q->sz, q->nsends,
-	    tvSubDsec(q->start_t, current_time));
+	    tvSubDsec(q->start_t, current_time),
+	    tvSubDsec(q->sent_t, current_time));
     }
     storeAppendPrintf(sentry, "\nNameservers:\n");
     storeAppendPrintf(sentry, "IP ADDRESS      # QUERIES # REPLIES\n");
