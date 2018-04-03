    }
    /* prints HTML form if no args */
    if (!operation[0] || !strcmp(operation, "empty")) {
	noargs_html(hostname, portnum, url, password);
	exit(0);
    }
    if (hostname[0] == '\0') {
	printf("<H1>ERROR</H1>\n");
	printf("<P><STRONG>You must provide a hostname!\n</STRONG></P><HR>");
	noargs_html(hostname, portnum, url, password);
	exit(0);
    }
    close(0);
