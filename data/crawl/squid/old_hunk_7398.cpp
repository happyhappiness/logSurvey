	sprintf(tmp_error_buf, "Cannot open swap logfile: %s", swaplog_file);
	fatal(tmp_error_buf);
    }
    swaplog_lock = file_write_lock(swaplog_fd);
    if (!opt_zap_disk_store)
	storeStartRebuildFromDisk();
    else
