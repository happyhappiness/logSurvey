             storeAppendPrintf(s, "\tFD desc: %s\n", fd_table[fd].desc);
             storeAppendPrintf(s, "\tin: buf %p, offset %ld, size %ld\n",
                               conn->in.buf, (long int) conn->in.notYetUsed, (long int) conn->in.allocatedSize);
-            storeAppendPrintf(s, "\tpeer: %s:%d\n",
-                              conn->peer.NtoA(buf,MAX_IPSTRLEN),
-                              conn->peer.GetPort());
-            storeAppendPrintf(s, "\tme: %s:%d\n",
-                              conn->me.NtoA(buf,MAX_IPSTRLEN),
-                              conn->me.GetPort());
+            storeAppendPrintf(s, "\tremote: %s\n",
+                              conn->clientConn->remote.ToURL(buf,MAX_IPSTRLEN));
+            storeAppendPrintf(s, "\tlocal: %s\n",
+                              conn->clientConn->local.ToURL(buf,MAX_IPSTRLEN));
             storeAppendPrintf(s, "\tnrequests: %d\n",
                               conn->nrequests);
         }