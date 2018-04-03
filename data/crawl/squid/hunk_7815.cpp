      cacheinfo *obj;
      StoreEntry *sentry;
 {
-    static char tempbuf[MAX_LINELEN];
-
     if (obj->logfile_status == LOG_ENABLE) {
-	sprintf(tempbuf, "{\"Logfile is Enabled. Filename: %s\"}\n",
+	storeAppendPrintf(sentry, "{\"Logfile is Enabled. Filename: %s\"}\n",
 	    obj->logfilename);
     } else {
-	sprintf(tempbuf, "{\"Logfile is Disabled.\"}\n");
+	storeAppendPrintf(sentry, "{\"Logfile is Disabled.\"}\n");
     }
-    storeAppend(sentry, tempbuf, strlen(tempbuf));
 }
 
 
