                               ntohs(conn->me.sin_port));
             storeAppendPrintf(s, "\tnrequests: %d\n",
                               conn->nrequests);
-            storeAppendPrintf(s, "\tdefer: n %d, until %ld\n",
-                              conn->defer.n, (long int) conn->defer.until);
         }
 
         storeAppendPrintf(s, "uri %s\n", http->uri);
