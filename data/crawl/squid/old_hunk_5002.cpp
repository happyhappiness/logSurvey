    storeAppendPrintf(e, "</PRE>\n");

    if (ftpState->flags.listformat_unknown && !ftpState->flags.tried_nlst) {
        storeAppendPrintf(e, "<A HREF=\"./;type=d\">[As plain directory]</A>\n");
    } else if (ftpState->typecode == 'D') {
        const char *path = ftpState->filepath ? ftpState->filepath : ".";
        storeAppendPrintf(e, "<A HREF=\"%s/\">[As extended directory]</A>\n", html_quote(path));
    }

