	else if (!strncmp(entries[x].name, "port", 4))
	    portnum = atoi(entries[x].val);
	else {
	    printf("<P><STRONG>Unknown CGI parameter: %s</STRONG></P>\n",
		entries[x].name);
	    noargs_html();
	    exit(0);
