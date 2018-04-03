     }
 
     MemBuf mb;
-    memBufDefInit(&mb);
-    memBufPrintf(&mb, "%d, %d\r\n",
-                 ntohs(state->my_peer.sin_port),
-                 ntohs(state->me.sin_port));
+    mb.init();
+    mb.Printf("%d, %d\r\n",
+              ntohs(state->my_peer.sin_port),
+              ntohs(state->me.sin_port));
     comm_old_write_mbuf(fd, &mb, NULL, state);
     comm_read(fd, state->buf, BUFSIZ, identReadReply, state);
     commSetTimeout(fd, Config.Timeout.ident, identTimeout, state);
