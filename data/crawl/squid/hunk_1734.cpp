             storeAppendPrintf(s, "\tin: buf %p, offset %ld, size %ld\n",
                               conn->in.buf, (long int) conn->in.notYetUsed, (long int) conn->in.allocatedSize);
             storeAppendPrintf(s, "\tremote: %s\n",
-                              conn->clientConnection->remote.ToURL(buf,MAX_IPSTRLEN));
+                              conn->clientConnection->remote.toUrl(buf,MAX_IPSTRLEN));
             storeAppendPrintf(s, "\tlocal: %s\n",
-                              conn->clientConnection->local.ToURL(buf,MAX_IPSTRLEN));
+                              conn->clientConnection->local.toUrl(buf,MAX_IPSTRLEN));
             storeAppendPrintf(s, "\tnrequests: %d\n",
                               conn->nrequests);
         }
