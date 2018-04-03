     qsort((char *) list,
 	N,
 	sizeof(ipcache_entry *),
-	(QS *) ipcache_reverseLastRef);
+	ipcache_reverseLastRef);
     for (k = 0; k < N; k++)
 	ipcacheStatPrint(*(list + k), sentry);
     storeAppendPrintf(sentry, close_bracket);
     xfree(list);
 }
 
 static void
-dummy_handler(const ipcache_addrs * addrs, void *u3)
+dummy_handler(const ipcache_addrs * addrsnotused, void *datanotused)
 {
     return;
 }
