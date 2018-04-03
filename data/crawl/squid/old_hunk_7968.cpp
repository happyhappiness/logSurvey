    memcpy(obj->logfilename, logfilename, (int) (strlen(logfilename) + 1) % 256);
    obj->logfile_fd = file_open(obj->logfilename, NULL, O_RDWR | O_CREAT);
    if (obj->logfile_fd == DISK_ERROR) {
	debug(0, "Cannot open logfile: %s\n", obj->logfilename);
	obj->logfile_status = LOG_DISABLE;
	fatal("Cannot open logfile.\n");
    }
