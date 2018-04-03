    debug(53, 3) ("urnFindMinRtt: Counted %d URLs\n", i);

    if (urls == NULL) {		/* unkown URN error */
        debug(52, 3) ("urnTranslateDone: unknown URN %s\n", storeUrl(e));
        err = errorCon(ERR_URN_RESOLVE, HTTP_NOT_FOUND, urnState->request);
        err->url = xstrdup(storeUrl(e));
        errorAppendEntry(e, err);
        goto error;
    }

    min_u = urnFindMinRtt(urls, urnState->request->method, NULL);
    qsort(urls, urlcnt, sizeof(*urls), url_entry_sort);
    storeBuffer(e);
    mb = new MemBuf;
    mb->init();
    mb->Printf( "<TITLE>Select URL for %s</TITLE>\n"
                "<STYLE type=\"text/css\"><!--BODY{background-color:#ffffff;font-family:verdana,sans-serif}--></STYLE>\n"
                "<H2>Select URL for %s</H2>\n"
                "<TABLE BORDER=\"0\" WIDTH=\"100%%\">\n", storeUrl(e), storeUrl(e));

    for (i = 0; i < urlcnt; i++) {
        u = &urls[i];
