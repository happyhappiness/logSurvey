     storeAppendPrintf(sentry, "------ ---- ----- --------\n");
     for (n = lru_list.head; n; n = n->next) {
 	q = n->data;
-	storeAppendPrintf(sentry, "%#06hx %4d %5d %8.3f\n",
-	    q->id, q->sz, q->nsends,
+	storeAppendPrintf(sentry, "%#06x %4d %5d %8.3f\n",
+	    (int) q->id, q->sz, q->nsends,
 	    tvSubDsec(q->start_t, current_time));
     }
     storeAppendPrintf(sentry, "\nNameservers:\n");
