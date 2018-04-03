	storelog_fd = file_open(fname, O_WRONLY | O_CREAT, NULL, NULL);
    if (storelog_fd < 0)
	debug(20, 1) ("Store logging disabled\n");
    if (storeVerifyCacheDirs() < 0) {
        xstrncpy(tmp_error_buf,
            "\tFailed to verify one of the swap directories, Check cache.log\n"
            "\tfor details.  Run 'squid -z' to create swap directories\n"
            "\tif needed, or if running Squid for the first time.",
            ERROR_BUF_SZ); 
        fatal(tmp_error_buf);
    }   
    storeDirOpenSwapLogs();
    storeStartRebuildFromDisk();
    all_list.head = all_list.tail = NULL;
    inmem_list.head = inmem_list.tail = NULL;
}
