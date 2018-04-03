	wordlistDestroy(&ftpState->cwd_message);
    }
    storeAppendPrintf(e, "<H2>\n");
    storeAppendPrintf(e, "FTP Directory: ");
    /* "ftp://" == 6 characters */
    assert(strlen(ftpState->title_url) >= 6);
    for (i = 6, j = 0; ftpState->title_url[i]; j = i) {
	storeAppendPrintf(e, "<A HREF=\"");
	i += strcspn(&ftpState->title_url[i], "/");
	if (ftpState->title_url[i] == '/')
	    i++;
	for (k = 0; k < i; k++)
	    storeAppendPrintf(e, "%c", ftpState->title_url[k]);
	storeAppendPrintf(e, "\">");
	for (k = j; k < i - 1; k++)
	    storeAppendPrintf(e, "%c", ftpState->title_url[k]);
	if (ftpState->title_url[k] != '/')
	    storeAppendPrintf(e, "%c", ftpState->title_url[k++]);
	storeAppendPrintf(e, "</A>");
	if (k < i)
	    storeAppendPrintf(e, "%c", ftpState->title_url[k++]);
	if (i == j) {
	    /* Error guard, or "assert" */
	    storeAppendPrintf(e, "ERROR: Failed to parse URL: %s\n",
		ftpState->title_url);
	    debug(9, 0) ("Failed to parse URL: %s\n", ftpState->title_url);
	    break;
	}
    }
    storeAppendPrintf(e, "</H2>\n");
    storeAppendPrintf(e, "<PRE>\n");
    dirup = ftpHtmlifyListEntry("<internal-dirup>", ftpState);
