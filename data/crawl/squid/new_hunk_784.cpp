    e->buffer();
    mb = new MemBuf;
    mb->init();
    mb->appendf( "<TITLE>Select URL for %s</TITLE>\n"
                "<STYLE type=\"text/css\"><!--BODY{background-color:#ffffff;font-family:verdana,sans-serif}--></STYLE>\n"
                "<H2>Select URL for %s</H2>\n"
                "<TABLE BORDER=\"0\" WIDTH=\"100%%\">\n", e->url(), e->url());

    for (i = 0; i < urlcnt; ++i) {
        u = &urls[i];
        debugs(52, 3, "URL {" << u->url << "}");
        mb->appendf(
            "<TR><TD><A HREF=\"%s\">%s</A></TD>", u->url, u->url);

        if (urls[i].rtt > 0)
            mb->appendf(
                "<TD align=\"right\">%4d <it>ms</it></TD>", u->rtt);
        else
            mb->appendf("<TD align=\"right\">Unknown</TD>");

        mb->appendf("<TD>%s</TD></TR>\n", u->flags.cached ? "    [cached]" : " ");
    }

    mb->appendf(
        "</TABLE>"
        "<HR noshade size=\"1px\">\n"
        "<ADDRESS>\n"
