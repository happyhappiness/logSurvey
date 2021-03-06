    qsort(urls, urlcnt, sizeof(*urls), url_entry_sort);
    storeBuffer(e);
    mb = new MemBuf;
    memBufDefInit(mb);
    memBufPrintf(mb,
                 "<TITLE>Select URL for %s</TITLE>\n"
                 "<STYLE type=\"text/css\"><!--BODY{background-color:#ffffff;font-family:verdana,sans-serif}--></STYLE>\n"
                 "<H2>Select URL for %s</H2>\n"
                 "<TABLE BORDER=\"0\" WIDTH=\"100%%\">\n", storeUrl(e), storeUrl(e));

    for (i = 0; i < urlcnt; i++) {
        u = &urls[i];
        debug(52, 3) ("URL {%s}\n", u->url);
        memBufPrintf(mb,
                     "<TR><TD><A HREF=\"%s\">%s</A></TD>", u->url, u->url);

        if (urls[i].rtt > 0)
            memBufPrintf(mb,
                         "<TD align=\"right\">%4d <it>ms</it></TD>", u->rtt);
        else
            memBufPrintf(mb, "<TD align=\"right\">Unknown</TD>");

        memBufPrintf(mb,
                     "<TD>%s</TD></TR>\n", u->flags.cached ? "    [cached]" : " ");
    }

    memBufPrintf(mb,
                 "</TABLE>"
                 "<HR noshade size=\"1px\">\n"
                 "<ADDRESS>\n"
                 "Generated by %s@%s\n"
                 "</ADDRESS>\n",
                 full_appname_string, getMyHostname());
    rep = httpReplyCreate();
    httpReplySetHeaders(rep, version, HTTP_MOVED_TEMPORARILY, NULL,
                        "text/html", mb->contentSize(), 0, squid_curtime);
