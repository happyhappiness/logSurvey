    entry = gopherState->entry;

    if (gopherState->conversion == HTML_INDEX_PAGE) {
	storeAppendPrintf(entry,
	    "<HTML><HEAD><TITLE>Gopher Index %s</TITLE></HEAD>\n"
	    "<BODY><H1>%s<BR>Gopher Search</H1>\n"
	    "<p>This is a searchable Gopher index. Use the search\n"
	    "function of your browser to enter search terms.\n"
	    "<ISINDEX></BODY></HTML>\n",
	    storeUrl(entry), storeUrl(entry));
	/* now let start sending stuff to client */
	storeBufferFlush(entry);
	gopherState->data_in = 1;

	return;
    }
    if (gopherState->conversion == HTML_CSO_PAGE) {
	storeAppendPrintf(entry,
	    "<HTML><HEAD><TITLE>CSO Search of %s</TITLE></HEAD>\n"
	    "<BODY><H1>%s<BR>CSO Search</H1>\n"
	    "<P>A CSO database usually contains a phonebook or\n"
	    "directory.  Use the search function of your browser to enter\n"
	    "search terms.</P><ISINDEX></BODY></HTML>\n",
	    storeUrl(entry), storeUrl(entry));
	/* now let start sending stuff to client */
	storeBufferFlush(entry);
	gopherState->data_in = 1;
