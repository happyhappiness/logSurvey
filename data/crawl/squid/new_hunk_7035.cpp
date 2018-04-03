void
sig_intr(int sig)
{
    fd_close(0);
    printf("\rWaiting for open connections to finish...\n");
    signal(sig, SIG_DFL);
}

void
read_reply(int fd, void *data)
{
    static char buf[READ_BUF_SZ];
    if (read(fd, buf, READ_BUF_SZ) <= 0) {
	fd_close(fd);
	reqpersec++;
	nrequests++;
    }
}

int
request(url)
     char *url;
{
    int s;
    char buf[4096];
