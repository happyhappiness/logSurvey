    mb.Printf("%d, %d\r\n",
              conn->remote.GetPort(),
              conn->local.GetPort());
    comm_write_mbuf(conn->fd, &mb, NULL, state);
    comm_read(conn->fd, state->buf, BUFSIZ, Ident::ReadReply, state);
    commSetTimeout(conn->fd, Ident::TheConfig.timeout, Ident::Timeout, state);
}

void
Ident::ReadReply(int fd, char *buf, size_t len, comm_err_t flag, int xerrno, void *data)
{
    IdentStateData *state = (IdentStateData *)data;
    char *ident = NULL;
    char *t = NULL;

    assert(buf == state->buf);
    assert(fd == state->conn->fd);

    if (flag != COMM_OK || len <= 0) {
        state->conn->close();
