#endif
}

static void
clientHttpConnectionOpened(int fd, int, http_port_list *s)
{
    if (fd < 0) {
        Must(NHttpSockets > 0); // we tried to open some
        --NHttpSockets; // there will be fewer sockets than planned
        Must(HttpSockets[NHttpSockets] < 0); // no extra fds received

        if (!NHttpSockets) // we could not open any listen sockets at all
            fatal("Cannot open HTTP Port");

        return;
    }

    Must(s);

