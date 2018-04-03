    MemBuf mb;
    mb.init();
    mb.Printf("%d, %d\r\n",
              state->my_peer.GetPort(),
              state->me.GetPort());
    comm_write_mbuf(fd, &mb, NULL, state);
    comm_read(fd, state->buf, BUFSIZ, identReadReply, state);
    commSetTimeout(fd, Config.Timeout.ident, identTimeout, state);
