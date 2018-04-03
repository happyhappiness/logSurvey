        makeUsernameHeader(request, buf);

    // Adaptation::Config::metaHeaders
    typedef Adaptation::Config::MetaHeaders::iterator ACAMLI;
    for (ACAMLI i = Adaptation::Config::metaHeaders.begin(); i != Adaptation::Config::metaHeaders.end(); ++i) {
        HttpRequest *r = virgin.cause ?
                         virgin.cause : dynamic_cast<HttpRequest*>(virgin.header);
        Must(r);

        HttpReply *reply = dynamic_cast<HttpReply*>(virgin.header);

        if (const char *value = (*i)->match(r, reply))
            buf.Printf("%s: %s\r\n", (*i)->name.termedBuf(), value);
    }

    // fprintf(stderr, "%s\n", buf.content());
