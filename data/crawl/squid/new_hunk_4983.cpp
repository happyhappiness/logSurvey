    const char *t;
    assert(err != NULL);
    assert(err->page_id > ERR_NONE && err->page_id < error_page_count);
    content->init();
    m = error_text[err->page_id];
    assert(m);

    while ((p = strchr(m, '%'))) {
        content->append(m, p - m);	/* copy */
        t = errorConvert(*++p, err);	/* convert */
        content->Printf("%s", t);	/* copy */
        m = p + 1;		/* advance */
    }

    if (*m)
        content->Printf("%s", m);	/* copy tail */

    assert((size_t)content->contentSize() == strlen(content->content()));

