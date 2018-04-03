    }
}


/* This will be called when data is ready to be read from fd.  Read until
 * error or connection closed. */
static void
ftpReadReply(int fd, void *data)
{
    FtpStateData *ftpState = data;
    LOCAL_ARRAY(char, buf, SQUID_TCP_SO_RCVBUF);
