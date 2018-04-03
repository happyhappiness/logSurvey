    storeAppendPrintf(e, "FTP Directory: %s\n",
	html_quote(strBuf(ftpState->title_url)));
    storeAppendPrintf(e, "</TITLE>\n");
    storeAppendPrintf(e, "<STYLE type=\"text/css\"><!--BODY{background-color:#ffffff; font-family:verdana,sans-serif}--></STYLE>\n");
    if (ftpState->flags.use_base)
	storeAppendPrintf(e, "<BASE HREF=\"%s\">\n",
	    html_quote(strBuf(ftpState->base_href)));
