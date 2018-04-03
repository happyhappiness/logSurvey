        if (s->defaultsite)
            storeAppendPrintf(e, " defaultsite=%s", s->defaultsite);

        if (s->protocol && strcmp(s->protocol,"http") != 0)
            storeAppendPrintf(e, " protocol=%s", s->protocol);

        if (s->allow_direct)
            storeAppendPrintf(e, " allow-direct");
