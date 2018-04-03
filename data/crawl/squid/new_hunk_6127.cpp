    if (LogfileFD == DISK_ERROR) {
	debug(46, 0) ("accessLogRotate: Cannot open logfile: %s\n", fname);
	LogfileStatus = LOG_DISABLE;
	fatalf("Cannot open %s: %s", fname, xstrerror());
    }
}

