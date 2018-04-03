	else {
	    printf("<P><STRONG>Unknown CGI parameter: %s</STRONG></P>\n",
		entries[x].name);
	    noargs_html(query_host, query_port);
	    exit(0);
	}
    }
    if (!got_data) {		/* prints HTML form if no args */
	noargs_html(query_host, query_port);
	exit(0);
    }
    if (hostname[0] == '\0') {
	printf("<H1>ERROR</H1>\n");
	printf("<P><STRONG>You must provide a hostname!\n</STRONG></P><HR>");
	noargs_html(query_host, query_port);
	exit(0);
    }
    close(0);
