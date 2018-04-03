     idns_query *q;
     int i;
     int j;
+    char buf[MAX_IPSTRLEN];
     storeAppendPrintf(sentry, "Internal DNS Statistics:\n");
     storeAppendPrintf(sentry, "\nThe Queue:\n");
     storeAppendPrintf(sentry, "                       DELAY SINCE\n");
