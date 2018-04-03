    while ((p = strchr(m, '%'))) {
        result.append(m, p - m);       /* copy */
        t = Convert(*++p, true, true);       /* convert */
        result.appendf("%s", t);        /* copy */
        m = p + 1;                     /* advance */
    }

    if (*m)
        result.appendf("%s", m);        /* copy tail */

    assert((size_t)result.contentSize() == strlen(result.content()));
}
