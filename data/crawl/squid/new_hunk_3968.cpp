    typedef Services::iterator SCI;
    for (SCI i = AllServices().begin(); i != AllServices().end(); ++i) {
        const ServiceConfig &cfg = (*i)->cfg();
        storeAppendPrintf(entry, "%s %.*s_%s %s %d %.*s\n", name, cfg.key.size(), cfg.key.rawBuf(),
                          cfg.methodStr(), cfg.vectPointStr(), cfg.bypass, cfg.uri.size(), cfg.uri.rawBuf());
    }
}
