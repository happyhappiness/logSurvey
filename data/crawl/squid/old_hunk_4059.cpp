
    if (parts->type != 'd') {
        if (mimeGetViewOption(parts->name)) {
            snprintf(view, 2048, " <A HREF=\"%s%s;type=a\"><IMG border=\"0\" SRC=\"%s\" "
                     "ALT=\"[VIEW]\"></A>",
                     prefix, href, mimeGetIconURL("internal-view"));
        }

        if (mimeGetDownloadOption(parts->name)) {
            snprintf(download, 2048, " <A HREF=\"%s%s;type=i\"><IMG border=\"0\" SRC=\"%s\" "
                     "ALT=\"[DOWNLOAD]\"></A>",
                     prefix, href, mimeGetIconURL("internal-download"));
        }
    }

    /* <A HREF="{href}">{icon}</A> <A HREF="{href}">{text}</A> . . . {date}{size}{chdir}{view}{download}{link}\n  */
    if (parts->type != '\0') {
        snprintf(html, 8192, "<A HREF=\"%s%s\">%s</A> <A HREF=\"%s%s\">%s</A>%s "
                 "%s%8s%s%s%s%s\n",
                 prefix, href, icon, prefix, href, html_quote(text), dots_fill(strlen(text)),
                 parts->date, size, chdir, view, download, link);
    } else {
        /* Plain listing. {icon} {text} ... {chdir}{view}{download} */
        snprintf(html, 8192, "<A HREF=\"%s%s\">%s</A> <A HREF=\"%s%s\">%s</A>%s "
                 "%s%s%s%s\n",
                 prefix, href, icon, prefix, href, html_quote(text), dots_fill(strlen(text)),
                 chdir, view, download, link);
    }

    ftpListPartsFree(&parts);
    return html;
