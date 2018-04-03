                               fd_table[fd].bytes_read, fd_table[fd].bytes_written);
             storeAppendPrintf(s, "\tFD desc: %s\n", fd_table[fd].desc);
             storeAppendPrintf(s, "\tin: buf %p, used %ld, free %ld\n",
-                              conn->in.buf.c_str(), (long int) conn->in.buf.length(), (long int) conn->in.buf.spaceSize());
+                              conn->inBuf.rawContent(), (long int) conn->inBuf.length(), (long int) conn->inBuf.spaceSize());
             storeAppendPrintf(s, "\tremote: %s\n",
                               conn->clientConnection->remote.toUrl(buf,MAX_IPSTRLEN));
             storeAppendPrintf(s, "\tlocal: %s\n",
