 {
     dlink_node *n;
     idns_query *q;
+    int i;
     storeAppendPrintf(sentry, "Internal DNS Statistics:\n");
     storeAppendPrintf(sentry, "\nThe Queue:\n");
-	storeAppendPrintf(sentry, " ID  SIZE SENDS   DELAY\n");
-	storeAppendPrintf(sentry, "---- ---- ----- --------\n");
+    storeAppendPrintf(sentry, "  ID   SIZE SENDS   DELAY\n");
+    storeAppendPrintf(sentry, "------ ---- ----- --------\n");
     for (n = lru_list.head; n; n = n->next) {
 	q = n->data;
-	storeAppendPrintf(sentry, "%#04hx %4d %5d %8.3f\n",
-		q->id, q->sz, q->nsends,
-		tvSubDsec(q->start, current_time));
+	storeAppendPrintf(sentry, "%#06hx %4d %5d %8.3f\n",
+	    q->id, q->sz, q->nsends,
+	    tvSubDsec(q->start_t, current_time));
+    }
+    storeAppendPrintf(sentry, "\nNameservers:\n");
+    storeAppendPrintf(sentry, "IP ADDRESS      # QUERIES # REPLIES\n");
+    storeAppendPrintf(sentry, "--------------- --------- ---------\n");
+    for (i = 0; i < nns; i++) {
+	storeAppendPrintf(sentry, "%-15s %9d %9d\n",
+	    inet_ntoa(nameservers[i].S.sin_addr),
+	    nameservers[i].nqueries,
+	    nameservers[i].nreplies);
     }
 }
 
