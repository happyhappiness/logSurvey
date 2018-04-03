    if (s->key)
        storeAppendPrintf(e, " key=%s", s->key);

    if (s->options)
        storeAppendPrintf(e, " options=%s", s->options);

