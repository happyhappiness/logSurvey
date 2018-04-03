    storeAppendPrintf(e, "</PRE>\n");

    if (ftpState->flags.listformat_unknown && !ftpState->flags.tried_nlst) {
        storeAppendPrintf(e, "<A HREF=\"%s/;type=d\">[As plain directory]</A>\n",
                          ftpState->flags.dir_slash ? rfc1738_escape_part(ftpState->filepath) : ".");
    } else if (ftpState->typecode == 'D') {
        const char *path = ftpState->flags.dir_slash ? ftpState->filepath : ".";
        storeAppendPrintf(e, "<A HREF=\"%s/\">[As extended directory]</A>\n", html_quote(path));
    }

