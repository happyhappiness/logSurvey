    obj->squid_get_start = squid_get_start;
    obj->parameter_get = parameter_get;
    obj->server_list = server_list;

    xmemcpy(obj->logfilename, logfilename, (int) (strlen(logfilename) + 1) % 256);
    obj->logfile_fd = file_open(obj->logfilename, NULL, O_WRONLY | O_CREAT);
    if (obj->logfile_fd == DISK_ERROR) {
	debug(18, 0, "%s: %s\n", obj->logfilename, xstrerror());
	fatal("Cannot open logfile.");
    }
    obj->logfile_access = file_write_lock(obj->logfile_fd);

    obj->proto_id = urlParseProtocol;
    obj->proto_newobject = proto_newobject;
    obj->proto_purgeobject = proto_purgeobject;
    obj->proto_touchobject = proto_touchobject;
    obj->proto_hit = proto_hit;
    obj->proto_miss = proto_miss;
    obj->NotImplement = dummyhandler;

    for (i = PROTO_NONE; i <= PROTO_MAX; i++) {
	switch (i) {
	case PROTO_HTTP:
