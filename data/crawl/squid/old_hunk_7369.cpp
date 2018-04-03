
    conn = &fd_table[fd];
    memset(conn, '\0', sizeof(FD_ENTRY));
    return fd;
}


