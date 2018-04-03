
    if (gopherState->conversion == HTML_INDEX_PAGE) {
	char *html_url = html_quote(storeUrl(entry));
	storeAppendPrintf(entry,
	    "<HTML><HEAD><TITLE>Gopher Index %s</TITLE></HEAD>\n"
	    "<BODY><H1>%s<BR>Gopher Search</H1>\n"
	    "<p>This is a searchable Gopher index. Use the search\n"
	    "function of your browser to enter search terms.\n"
	    "<ISINDEX></BODY></HTML>\n",
	    html_url, html_url);
	/* now let start sending stuff to client */
	storeBufferFlush(entry);
	gopherState->data_in = 1;
