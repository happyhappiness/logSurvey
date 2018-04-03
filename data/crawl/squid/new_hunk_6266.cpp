    S.sin_port = htons(port);
    S.sin_family = AF_INET;
    if (debug)
	fprintf(stderr, "%s (%s) %d %s\n", host, inet_ntoa(S.sin_addr), (int) port, path);
    s = socket(PF_INET, SOCK_STREAM, 0);
    if (s < 0) {
	perror("socket");
	return -errno;
    }
    x = connect(s, (struct sockaddr *) &S, sizeof(S));
    if (x < 0) {
	perror(host);
	return -errno;
    }
    snprintf(request, URL_BUF_SZ,
	"GET %s HTTP/1.1\r\n"
