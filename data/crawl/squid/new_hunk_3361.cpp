Ident::Timeout(int fd, void *data)
{
    IdentStateData *state = (IdentStateData *)data;
    debugs(30, 3, HERE << "FD " << fd << ", " << state->conn.remote);
    comm_close(&(state->conn));
}

void
Ident::ConnectDone(Comm::Connection *conn, Vector<Comm::Connection*> *unused, comm_err_t status, int xerrno, void *data)
{
    IdentStateData *state = (IdentStateData *)data;

    if (status != COMM_OK) {
        if (status == COMM_TIMEOUT) {
            debugs(30, 3, "IDENT connection timeout to " << state->conn.remote);
        }
        return;
    }

    assert(conn != NULL && conn == &(state->conn));

    /*
     * see if any of our clients still care
     */
    IdentClient *c;
    for (c = state->clients; c; c = c->next) {
        if (cbdataReferenceValid(c->callback_data))
            break;
    }

    if (c == NULL) {
        /* no clients care */
        comm_close(conn);
        return;
    }

    comm_add_close_handler(conn->fd, Ident::Close, state);

    MemBuf mb;
    mb.init();
    mb.Printf("%d, %d\r\n",
              conn->remote.GetPort(),
              conn->local.GetPort());
    comm_write_mbuf(conn->fd, &mb, NULL, state);
    comm_read(conn->fd, state->buf, BUFSIZ, Ident::ReadReply, state);
    commSetTimeout(conn->fd, Ident::TheConfig.timeout, Ident::Timeout, state);
}

void
