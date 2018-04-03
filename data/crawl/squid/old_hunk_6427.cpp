}

int
send_request(int fd, const char *url)
{
    char buf[4096];
    int len;
    time_t w;
    struct _r *r;
    struct _r **R;
    buf[0] = '\0';
    strcat(buf, "GET ");
    strcat(buf, url);
    strcat(buf, " HTTP/1.0\r\n");
    strcat(buf, "Accept: */*\r\n");
    strcat(buf, "Proxy-Connection: Keep-Alive\r\n");
    if (opt_ims && (lrand48() & 0x03) == 0) {
	w = time(NULL) - (lrand48() & 0x3FFFF);
	strcat(buf, "If-Modified-Since: ");
	strcat(buf, mkrfc850(&w));
	strcat(buf, "\r\n");
    }
    strcat(buf, "\r\n");
    len = strlen(buf);
    if (write(fd, buf, len) < 0) {
	close(fd);
	perror("write");
	return -1;
    }
    r = calloc(1, sizeof(struct _r));
    r->url = strdup(url);
    for (R = &Requests; *R; R = &(*R)->next);
    *R = r;
    fprintf(stderr, "REQUESTED %s\n", url);
    noutstanding++;
    return 0;
}
