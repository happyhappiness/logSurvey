      cacheinfo *obj;
      StoreEntry *sentry;
 {
-    static char *msg = "{ \"Not_Implemented_yet.\"}\n";
-    storeAppend(sentry, msg, strlen(msg));
+    storeAppendPrintf(sentry, "{ \"Not_Implemented_yet.\"}\n");
 }
 
 void server_list(obj, sentry)
      cacheinfo *obj;
      StoreEntry *sentry;
 {
-    static char tempbuf[MAX_LINELEN];
     edge *e = NULL;
     dom_list *d = NULL;
 
-    storeAppend(sentry, open_bracket, (int) strlen(open_bracket));
+    storeAppendPrintf(sentry, "{\n");
 
     if (getFirstEdge() == (edge *) NULL) {
-	sprintf(tempbuf, "{There are no neighbors installed.}\n");
-	storeAppend(sentry, tempbuf, strlen(tempbuf));
+	storeAppendPrintf(sentry, "{There are no neighbors installed.}\n");
     }
     for (e = getFirstEdge(); e; e = getNextEdge(e)) {
 	if (e->host == NULL)
 	    fatal_dump("Found an edge without a hostname!");
-	sprintf(tempbuf, "\n{Hostname:    %s}\n", e->host);
-	storeAppend(sentry, tempbuf, strlen(tempbuf));
-	sprintf(tempbuf, "{Edge type:   %s}\n",
+	storeAppendPrintf(sentry, "\n{Hostname:    %s}\n", e->host);
+	storeAppendPrintf(sentry, "{Edge type:   %s}\n",
 	    e->type == EDGE_PARENT ? "parent" : "neighbor");
-	storeAppend(sentry, tempbuf, strlen(tempbuf));
-	sprintf(tempbuf, "{Status:      %s}\n",
+	storeAppendPrintf(sentry, "{Status:      %s}\n",
 	    e->neighbor_up ? "Up" : "Down");
-	storeAppend(sentry, tempbuf, strlen(tempbuf));
-	sprintf(tempbuf, "{UDP PORT:    %d}\n", e->udp_port);
-	storeAppend(sentry, tempbuf, strlen(tempbuf));
-	sprintf(tempbuf, "{ASCII PORT:  %d}\n", e->ascii_port);
-	storeAppend(sentry, tempbuf, strlen(tempbuf));
-	sprintf(tempbuf, "{ACK DEFICIT: %d}\n", e->ack_deficit);
-	storeAppend(sentry, tempbuf, strlen(tempbuf));
-	sprintf(tempbuf, "{PINGS SENT:  %d}\n", e->num_pings);
-	storeAppend(sentry, tempbuf, strlen(tempbuf));
-	sprintf(tempbuf, "{PINGS ACKED: %d}\n", e->pings_acked);
-	storeAppend(sentry, tempbuf, strlen(tempbuf));
+	storeAppendPrintf(sentry, "{UDP PORT:    %d}\n", e->udp_port);
+	storeAppendPrintf(sentry, "{ASCII PORT:  %d}\n", e->ascii_port);
+	storeAppendPrintf(sentry, "{ACK DEFICIT: %d}\n", e->ack_deficit);
+	storeAppendPrintf(sentry, "{PINGS SENT:  %d}\n", e->num_pings);
+	storeAppendPrintf(sentry, "{PINGS ACKED: %d}\n", e->pings_acked);
 	if (e->last_fail_time) {
-	    sprintf(tempbuf, "{Last failed connect() at: %s}\n",
+	    storeAppendPrintf(sentry, "{Last failed connect() at: %s}\n",
 		mkhttpdlogtime(&(e->last_fail_time)));
-	    storeAppend(sentry, tempbuf, strlen(tempbuf));
 	}
-	sprintf(tempbuf, "{DOMAIN LIST: ");
-	storeAppend(sentry, tempbuf, strlen(tempbuf));
+	storeAppendPrintf(sentry, "{DOMAIN LIST: ");
 	for (d = e->domains; d; d = d->next) {
 	    if (d->do_ping)
-		sprintf(tempbuf, "%s ", d->domain);
+		storeAppendPrintf(sentry, "%s ", d->domain);
 	    else
-		sprintf(tempbuf, "!%s ", d->domain);
-	    storeAppend(sentry, tempbuf, strlen(tempbuf));
+		storeAppendPrintf(sentry, "!%s ", d->domain);
 	}
-	storeAppend(sentry, close_bracket, strlen(close_bracket));	/* } */
+	storeAppendPrintf(sentry, "}\n");
     }
-    storeAppend(sentry, close_bracket, strlen(close_bracket));
+    storeAppendPrintf(sentry, "}\n");
 }
 
 
