 
         for (i = 0; i < e->n_addresses; ++i) {
             storeAppendPrintf(sentry, "Address[%d] : %s\n", i,
-                              e->addresses[i].NtoA(ntoabuf,MAX_IPSTRLEN) );
+                              e->addresses[i].toStr(ntoabuf,MAX_IPSTRLEN) );
         }
 
         storeAppendPrintf(sentry, "Status     : %s\n",
