    }
    if (gopherState->conversion == HTML_CSO_PAGE) {
	char *html_url = html_quote(storeUrl(entry));
	storeAppendPrintf(entry,
	    "<HTML><HEAD><TITLE>CSO Search of %s</TITLE></HEAD>\n"
	    "<BODY><H1>%s<BR>CSO Search</H1>\n"
	    "<P>A CSO database usually contains a phonebook or\n"
	    "directory.  Use the search function of your browser to enter\n"
	    "search terms.</P><ISINDEX></BODY></HTML>\n",
	    html_url, html_url);
	/* now let start sending stuff to client */
	storeBufferFlush(entry);
	gopherState->data_in = 1;
