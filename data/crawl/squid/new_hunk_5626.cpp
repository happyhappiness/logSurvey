    }
    if (gopherState->conversion == HTML_CSO_PAGE) {
	char *html_url = html_quote(storeUrl(entry));
	gopherHTMLHeader(entry, "CSO Search of %s", html_url);
	storeAppendPrintf(entry,
	    "<P>A CSO database usually contains a phonebook or\n"
	    "directory.  Use the search function of your browser to enter\n"
	    "search terms.</P><ISINDEX>\n");
	gopherHTMLFooter(entry);
	/* now let start sending stuff to client */
	storeBufferFlush(entry);
	gopherState->data_in = 1;
