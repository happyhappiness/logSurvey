    else
        prefix[0] = '\0';

    /* Handle builtin <dirup> */
    if (strcmp(line, "<internal-dirup>") == 0) {
        /* <A HREF="{href}">{icon}</A> <A HREF="{href}">{text}</A> {link} */
        snprintf(icon, 2048, "<IMG border=\"0\" SRC=\"%s\" ALT=\"%-6s\">",
                 mimeGetIconURL("internal-dirup"),
                 "[DIRUP]");

        if (!flags.no_dotdot && !flags.root_dir) {
            /* Normal directory */

            if (!flags.dir_slash)
                strcpy(href, "../");
            else
                strcpy(href, "./");

            strcpy(text, "Parent Directory");
        } else if (!flags.no_dotdot && flags.root_dir) {
            /* "Top level" directory */
            strcpy(href, "%2e%2e/");
            strcpy(text, "Parent Directory");
            snprintf(link, 2048, "(<A HREF=\"%s\">%s</A>)",
                     "%2f/",
                     "Root Directory");
        } else if (flags.no_dotdot && !flags.root_dir) {
            char *url;
            /* Normal directory where last component is / or ..  */
            strcpy(href, "%2e%2e/");
            strcpy(text, "Parent Directory");

            if (flags.dir_slash) {
                url = xstrdup("./");
            } else {
                const char *title = title_url.termedBuf();
                int k = 6 + strcspn(&title[6], "/");
                char *t;
                url = xstrdup(title + k);
                t = url + strlen(url) - 2;

                while (t > url && *t != '/')
                    *t-- = '\0';
            }

            snprintf(link, 2048, "(<A HREF=\"%s\">%s</A>)", url, "Back");
            safe_free(url);
        } else {		/* NO_DOTDOT && ROOT_DIR */
            /* "UNIX Root" directory */
            strcpy(href, "/");
            strcpy(text, "Home Directory");
        }

        snprintf(html, 8192, "<A HREF=\"%s\">%s</A> <A HREF=\"%s\">%s</A> %s\n",
                 href, icon, href, text, link);
        return html;
    }

    if ((parts = ftpListParseParts(line, flags)) == NULL) {
        const char *p;
        snprintf(html, 8192, "%s\n", line);

        for (p = line; *p && xisspace(*p); p++);
        if (*p && !xisspace(*p))
