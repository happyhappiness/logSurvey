    Comm::AcceptLimiter::Instance().kick();
}

/*
 * Close the socket fd in use by a connection.
 */
void
_comm_close(Comm::Connection *conn, char const *file, int line)
{
    _comm_close(conn->fd, file, line);
    conn->fd = -1;
}

/*
 * Close the socket fd.
 *
