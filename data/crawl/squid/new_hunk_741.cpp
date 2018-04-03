
        html = new MemBuf();
        html->init();
        html->appendf("<tr class=\"entry\"><td colspan=\"5\">%s</td></tr>\n", line);

        for (p = line; *p && xisspace(*p); ++p);
        if (*p && !xisspace(*p))
