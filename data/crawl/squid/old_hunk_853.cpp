    while ((p = strchr(m, '%'))) {
        result.append(m, p - m);       /* copy */
        t = Convert(*++p, true, true);       /* convert */
        result.Printf("%s", t);        /* copy */
        m = p + 1;                     /* advance */
    }

    if (*m)
        result.Printf("%s", m);        /* copy tail */

    assert((size_t)result.contentSize() == strlen(result.content()));
}
