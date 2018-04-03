
    debug(18, 5) ("stat_init: Initializing...\n");
    obj = xcalloc(1, sizeof(cacheinfo));
    if (logfilename)
    	accessLogOpen(logfilename);
    obj->proto_id = urlParseProtocol;
    obj->proto_newobject = proto_newobject;
    obj->proto_purgeobject = proto_purgeobject;
