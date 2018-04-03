     for (n = lru_list.head; n; n = n->next) {
 	q = n->data;
 	storeAppendPrintf(sentry, "%#06x %4d %5d %10.3f %9.3f\n",
-	    (int) q->id, q->sz, q->nsends,
+	    (int) q->id, (int) q->sz, q->nsends,
 	    tvSubDsec(q->start_t, current_time),
 	    tvSubDsec(q->sent_t, current_time));
     }
