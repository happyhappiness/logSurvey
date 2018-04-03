     MemBuf mb;
     mb.init();
     mb.Printf("%d, %d\r\n",
-              ntohs(state->my_peer.sin_port),
-              ntohs(state->me.sin_port));
+              state->my_peer.GetPort(),
+              state->me.GetPort());
     comm_write_mbuf(fd, &mb, NULL, state);
     comm_read(fd, state->buf, BUFSIZ, identReadReply, state);
     commSetTimeout(fd, Config.Timeout.ident, identTimeout, state);
