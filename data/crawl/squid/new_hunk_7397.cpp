	    tmp_filename, xstrerror());
	fatal("storeStartRebuildFromDisk: Can't open tmp swaplog");
    }
    /* Open the existing swap log for reading */
    if ((data->log = fopen(swaplog_file, "r")) == (FILE *) NULL) {
	sprintf(tmp_error_buf, "storeRebuildFromDisk: %s: %s",
