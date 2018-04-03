    FD_ENTRY *conn;
    int fd;

    if (mode & O_RDWR)
	fatal_dump("file_open: O_RDWR not allowed");
    if (mode & O_WRONLY)
	mode |= O_APPEND;
#if defined(O_NONBLOCK) && !defined(_SQUID_SUNOS_) && !defined(_SQUID_SOLARIS_)
