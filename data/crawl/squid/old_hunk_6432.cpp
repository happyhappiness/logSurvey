    if (connect(s, (struct sockaddr *) &S, sizeof(S)) < 0) {
	close(s);
	perror("connect");
	return -1;
    }
    buf[0] = '\0';
    strcat(buf, "GET ");
    strcat(buf, url);
    strcat(buf, " HTTP/1.0\r\n");
    strcat(buf, "Accept: */*\r\n");
    if (opt_ims && (lrand48() & 0x03) == 0) {
	w = time(NULL) - (lrand48() & 0x3FFFF);
	strcat(buf, "If-Modified-Since: ");
	strcat(buf, mkrfc850(&w));
	strcat(buf, "\r\n");
    }
    strcat(buf, "\r\n");
    len = strlen(buf);
    if (write(s, buf, len) < 0) {
	close(s);
	perror("write");
	return -1;
    }
/*
 * if (fcntl(s, F_SETFL, O_NDELAY) < 0)
 * perror("fcntl O_NDELAY");
 */
    return s;
}

void
read_url(int fd, void *junk)
{
    static char buf[8192];
    char *t;
    int s;
    if (fgets(buf, 8191, stdin) == NULL) {
	printf("Done Reading URLS\n");
	fd_close(0);
	return;
    }
    if ((t = strchr(buf, '\n')))
	*t = '\0';
    s = request(buf);
    if (s < 0) {
	max_connections = nfds - 1;
	printf("NOTE: max_connections set at %d\n", max_connections);
    }
    fd_open(s, read_reply, NULL);
}

void
