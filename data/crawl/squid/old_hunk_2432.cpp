{
    debugs(9, 4, HERE << io.conn << ": '" << entry->url() << "'" );

    if (SENT_PASV == state && io.conn->fd == data.conn->fd) {
        /* stupid ftp.netscape.com */
        flags.pasv_supported = false;