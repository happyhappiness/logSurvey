     storeAppendPrintf(sentry, "{\tReserved number of file descriptors:  %4d}\n",
 	RESERVED_FD);
 
-    storeAppendPrintf(sentry, "{Stop List:}\n");
-    if ((p = Config.http_stoplist)) {
-	storeAppendPrintf(sentry, "{\tHTTP:}\n");
-	while (p) {
-	    storeAppendPrintf(sentry, "{\t\t%s}\n", p->key);
-	    p = p->next;
-	}
-    }
-    if ((p = Config.gopher_stoplist)) {
-	storeAppendPrintf(sentry, "{\tGOPHER:}\n");
-	while (p) {
-	    storeAppendPrintf(sentry, "{\t\t%s}\n", p->key);
-	    p = p->next;
-	}
-    }
-    if ((p = Config.ftp_stoplist)) {
-	storeAppendPrintf(sentry, "{\tFTP:}\n");
-	while (p) {
-	    storeAppendPrintf(sentry, "{\t\t%s}\n", p->key);
-	    p = p->next;
-	}
-    }
     storeAppendPrintf(sentry, "{Internal Data Structures:}\n");
     storeAppendPrintf(sentry, "{\tHot Object Cache Items %d}\n",
 	meta_data.hot_vm);