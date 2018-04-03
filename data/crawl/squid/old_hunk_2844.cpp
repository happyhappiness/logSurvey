        debugs(4, 2, HERE << "No existing error page language negotiated for " << errorPageName(page_id) << ". Using default error file.");
    }

    assert(m);
    content->init();

    while ((p = strchr(m, '%'))) {
        content->append(m, p - m);	/* copy */
        t = Convert(*++p, false);	/* convert */
        content->Printf("%s", t);	/* copy */
        m = p + 1;			/* advance */
    }
