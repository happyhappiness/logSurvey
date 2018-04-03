    while ((p = strchr(m, '%'))) {
        content->append(m, p - m);  /* copy */
        const char *t = Convert(*++p, false, allowRecursion);   /* convert */
        content->appendf("%s", t);   /* copy */
        m = p + 1;          /* advance */
    }

    if (*m)
        content->appendf("%s", m);   /* copy tail */

    content->terminate();

