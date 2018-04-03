
#endif /* USE_SSL */

/// check FD after clientHttp[s]ConnectionOpened, adjust HttpSockets as needed
static bool
OpenedHttpSocket(int fd, const char *msgIfFail)
{
    if (fd < 0) {
        Must(NHttpSockets > 0); // we tried to open some
        --NHttpSockets; // there will be fewer sockets than planned
        Must(HttpSockets[NHttpSockets] < 0); // no extra fds received

        if (!NHttpSockets) // we could not open any listen sockets at all
            fatal(msgIfFail);

        return false;
    }
    return true;
}

/// find any unused HttpSockets[] slot and store fd there or return false
static bool
AddOpenedHttpSocket(int fd)
{
    bool found = false;
    for (int i = 0; i < NHttpSockets && !found; i++) {
        if ((found = HttpSockets[i] < 0))
            HttpSockets[i] = fd;
    }
    return found;
}

static void
clientHttpConnectionsOpen(void)
