    snprintf(buf, BUFSIZ, "\r\n");
    strcat(msg, buf);

    /* Send the HTTP request */
    bytesWritten = write(conn, msg, strlen(msg));
    if (bytesWritten < 0) {
	perror("client: ERROR: write");
	exit(1);
    } else if (bytesWritten != strlen(msg)) {
	fprintf(stderr, "client: ERROR: Cannot send request?: %s\n", msg);
	exit(1);
    }
    /* Read the data */
    while ((len = read(conn, buf, sizeof(buf))) > 0) {
	if (to_stdout)
	    fwrite(buf, len, 1, stdout);
    }
    (void) close(conn);		/* done with socket */
    exit(0);
    /*NOTREACHED */
    return 0;
}

static int
client_comm_connect(int sock, char *dest_host, u_short dest_port)
{
    const struct hostent *hp;
    static struct sockaddr_in to_addr;

    /* Set up the destination socket address for message to send to. */
    to_addr.sin_family = AF_INET;

    if ((hp = gethostbyname(dest_host)) == 0) {
	return (-1);
    }
    xmemcpy(&to_addr.sin_addr, hp->h_addr, hp->h_length);
    to_addr.sin_port = htons(dest_port);
    return connect(sock, (struct sockaddr *) &to_addr, sizeof(struct sockaddr_in));
}
