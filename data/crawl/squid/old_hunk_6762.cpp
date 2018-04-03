	    snprintf(buf, BUFSIZ, "Connection: Keep-Alive\r\n");
	strcat(msg, buf);
    }
    snprintf(buf, BUFSIZ, "\r\n");
    strcat(msg, buf);

    if (ping) {
#if HAVE_SIGACTION
	struct sigaction sa, osa;
