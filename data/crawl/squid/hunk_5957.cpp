 	    (int) n->next_ping_time,
 	    (int) n->last_use_time);
 	for (x = n->hosts; x; x = x->next)
-	    logfilePrintf(lf, " %s", x->name);
+	    logfilePrintf(lf, " %s", hashKeyStr(&x->hash));
 	logfilePrintf(lf, "\n");
 	count++;
 #undef RBUF_SZ
