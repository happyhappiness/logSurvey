{
    assert(p);
    /* pack request-line */
    p->Printf(SQUIDSBUFPH " " SQUIDSTRINGPH " HTTP/%d.%d\r\n",
              SQUIDSBUFPRINT(method.image()), SQUIDSTRINGPRINT(urlpath),
              http_ver.major, http_ver.minor);
    /* headers */
    header.packInto(p);
    /* trailer */
