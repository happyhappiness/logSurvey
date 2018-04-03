
    if (parts->type != 'd') {
        if (mimeGetViewOption(parts->name)) {
            snprintf(view, 2048, "<a href=\"%s%s;type=a\"><img border=\"0\" src=\"%s\" "
                     "alt=\"[VIEW]\"></a>",
                     prefix, href, mimeGetIconURL("internal-view"));
        }

        if (mimeGetDownloadOption(parts->name)) {
            snprintf(download, 2048, "<a href=\"%s%s;type=i\"><img border=\"0\" src=\"%s\" "
                     "alt=\"[DOWNLOAD]\"></a>",
                     prefix, href, mimeGetIconURL("internal-download"));
        }
    }

    /* construct the table row from parts. */
    html = new MemBuf();
    html->init();
    html->Printf("<tr class=\"entry\">"
             "<td class=\"icon\"><a href=\"%s%s\">%s</a></td>"
             "<td class=\"filename\"><a href=\"%s%s\">%s</a></td>"
             "<td class=\"date\">%s</td>"
             "<td class=\"size\">%s</td>"
             "<td class=\"actions\">%s%s%s%s</td>"
             "</tr>\n",
             prefix, href, icon,
             prefix, href, html_quote(text),
             parts->date,
             size,
             chdir, view, download, link);

    ftpListPartsFree(&parts);
    return html;
