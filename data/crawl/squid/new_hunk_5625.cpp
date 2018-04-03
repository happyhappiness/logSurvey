
    if (gopherState->conversion == HTML_INDEX_PAGE) {
	char *html_url = html_quote(storeUrl(entry));
	gopherHTMLHeader(entry, "Gopher Index %s", html_url);
	storeAppendPrintf(entry,
	    "<p>This is a searchable Gopher index. Use the search\n"
	    "function of your browser to enter search terms.\n"
	    "<ISINDEX>\n");
	gopherHTMLFooter(entry);
	/* now let start sending stuff to client */
	storeBufferFlush(entry);
	gopherState->data_in = 1;
