    if (obj->logfile_fd == DISK_ERROR) {
	debug(18, 0, "Cannot open logfile: %s\n", obj->logfilename);
	obj->logfile_status = LOG_DISABLE;
	fatal("Cannot open logfile.\n");
    }
    obj->logfile_access = file_write_lock(obj->logfile_fd);

