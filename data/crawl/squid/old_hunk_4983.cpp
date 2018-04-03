    const char *t;
    assert(err != NULL);
    assert(err->page_id > ERR_NONE && err->page_id < error_page_count);
    memBufDefInit(content);
    m = error_text[err->page_id];
    assert(m);

    while ((p = strchr(m, '%'))) {
        memBufAppend(content, m, p - m);	/* copy */
        t = errorConvert(*++p, err);	/* convert */
        memBufPrintf(content, "%s", t);	/* copy */
        m = p + 1;		/* advance */
    }

    if (*m)
        memBufPrintf(content, "%s", m);	/* copy tail */

    assert((size_t)content->contentSize() == strlen(content->content()));

