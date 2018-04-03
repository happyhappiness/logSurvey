 	} else {
 	    debug(11, 5, "httpStart: FD %d: EINPROGRESS.\n", sock);
 	    comm_set_select_handler(sock, COMM_SELECT_LIFETIME,
-		(PF) httpLifetimeExpire, (void *) data);
+		(PF) httpLifetimeExpire, (void *) httpState);
 	    comm_set_select_handler(sock, COMM_SELECT_WRITE,
-		(PF) httpConnInProgress, (void *) data);
+		(PF) httpConnInProgress, (void *) httpState);
 	    return COMM_OK;
 	}
     }
     /* Install connection complete handler. */
     fd_note(sock, entry->url);
     comm_set_select_handler(sock, COMM_SELECT_LIFETIME,
-	(PF) httpLifetimeExpire, (void *) data);
+	(PF) httpLifetimeExpire, (void *) httpState);
     comm_set_select_handler(sock, COMM_SELECT_WRITE,
-	(PF) httpSendRequest, (void *) data);
+	(PF) httpSendRequest, (void *) httpState);
     return COMM_OK;
 }
+
+void httpReplyHeaderStats(entry)
+     StoreEntry *entry;
+{
+    storeAppendPrintf(entry, open_bracket);
+    storeAppendPrintf(entry, "{HTTP Reply Headers}\n");
+    storeAppendPrintf(entry, "{Headers parsed: %d}\n",
+	ReplyHeaderStats.parsed);
+    storeAppendPrintf(entry, "{          Date: %d}\n",
+	ReplyHeaderStats.date);
+    storeAppendPrintf(entry, "{ Last-Modified: %d}\n",
+	ReplyHeaderStats.lm);
+    storeAppendPrintf(entry, "{       Expires: %d}\n",
+	ReplyHeaderStats.exp);
+    storeAppendPrintf(entry, "{  Content-Type: %d}\n",
+	ReplyHeaderStats.ctype);
+    storeAppendPrintf(entry, "{Content-Length: %d}\n",
+	ReplyHeaderStats.clen);
+    storeAppendPrintf(entry, close_bracket);
+}
