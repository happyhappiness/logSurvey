    }
    swaplog_stream = fdopen(swaplog_fd, "w");
    if (!swaplog_stream) {
	debug(1, "storeInit: fdopen(%d, \"w\"): %s\n", swaplog_fd, xstrerror());
	sprintf(tmpbuf, "Cannot open a stream for swap logfile: %s\n", swaplog_file);
	fatal(tmpbuf);
    }
