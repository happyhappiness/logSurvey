     }
     for (e = getFirstEdge(); e; e = getNextEdge(e)) {
 	if (e->host == NULL)
-	    fatal_dump("Found an edge without a hostname!\n");
+	    fatal_dump("Found an edge without a hostname!");
 	sprintf(tempbuf, "\n{Hostname:    %s}\n", e->host);
 	storeAppend(sentry, tempbuf, strlen(tempbuf));
 	sprintf(tempbuf, "{Edge type:   %s}\n",
