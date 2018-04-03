    typedef Services::iterator SCI;
    for (SCI i = AllServices().begin(); i != AllServices().end(); ++i) {
        const ServiceConfig &cfg = (*i)->cfg();
        storeAppendPrintf(entry, "%s %s_%s %s %d %s\n", name, cfg.key.buf(),
                          cfg.methodStr(), cfg.vectPointStr(), cfg.bypass, cfg.uri.buf());
    }
}

