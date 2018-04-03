    RESERVED_FD = XMIN(100, Squid_MaxFD / 4);
}

/* MinGW needs also a stub of _comm_close() */
void
_comm_close(int fd, char const *file, int line)
{
    fatal ("Not implemented");
}
