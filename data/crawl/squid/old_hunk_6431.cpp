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
    int len;
    time_t w;
    struct sockaddr_in S;
    if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
	perror("socket");
	return -1;
    }
    memset(&S, '\0', sizeof(struct sockaddr_in));
    S.sin_family = AF_INET;
