
    for (VI i = services.begin(); i != services.end(); ++i) {
        const ICAPServiceRep::Pointer &r = *i;
        storeAppendPrintf(entry, "%s %s_%s %s %d %s\n", name, r->key.buf(),
                          r->methodStr(), r->vectPointStr(), r->bypass, r->uri.buf());
    }
};

