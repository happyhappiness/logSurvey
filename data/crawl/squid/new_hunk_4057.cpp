    return buf;
}

MemBuf *
FtpStateData::htmlifyListEntry(const char *line)
{
    char icon[2048];
    char href[2048 + 40];
    char text[ 2048];
    char size[ 2048];
    char chdir[ 2048 + 40];
    char view[ 2048 + 40];
    char download[ 2048 + 40];
    char link[ 2048 + 40];
    MemBuf *html;
    char prefix[2048];
    ftpListParts *parts;
    *icon = *href = *text = *size = *chdir = *view = *download = *link = *html = '\0';

    if (strlen(line) > 1024) {
        html->Printf("<tr><td colspan="5">%s</td></tr>\n", line);
        return html;
    }

