    MemBuf *html;
    char prefix[2048];
    ftpListParts *parts;
    *icon = *href = *text = *size = *chdir = *view = *download = *link = *html = '\0';

    if (strlen(line) > 1024) {
        html->Printf("<tr><td colspan="5">%s</td></tr>\n", line);
        return html;
    }

