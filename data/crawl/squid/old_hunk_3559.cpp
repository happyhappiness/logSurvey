
    while ((p = strchr(m, '%'))) {
        content->append(m, p - m);	/* copy */
        t = Convert(*++p);		/* convert */
        content->Printf("%s", t);	/* copy */
        m = p + 1;			/* advance */
    }
