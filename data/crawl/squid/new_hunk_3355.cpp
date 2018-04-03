#endif
}

/// process clientHttpConnectionsOpen result
static void
clientHttpConnectionOpened(int fd, int, http_port_list *s)
{
    if (!OpenedHttpSocket(fd, "Cannot open HTTP Port"))
        return;

    Must(s);

