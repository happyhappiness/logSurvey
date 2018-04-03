	    s.lastmod,
	    s.refcount,
	    s.flags,
	    (int) flags.clean);
	storeDirSwapLog(e, SWAP_LOG_ADD);
    }
    eventAdd("storeRebuild", RebuildFromSwapLog, this, 0.0, 1);
}

int
RebuildState::getNextFile(sfileno * filn_p, int *size)
{
    int fd = -1;
    int dirs_opened = 0;
    debug(47, 3) ("commonUfsDirGetNextFile: flag=%d, %d: /%02X/%02X\n",
	flags.init,
	sd->index,
	curlvl1,
	curlvl2);
    if (done)
	return -2;
    while (fd < 0 && done == 0) {
	fd = -1;
	if (0 == flags.init) {	/* initialize, open first file */
	    done = 0;
	    curlvl1 = 0;
	    curlvl2 = 0;
	    in_dir = 0;
	    flags.init = 1;
	    assert(Config.cacheSwap.n_configured > 0);
	}
	if (0 == in_dir) {	/* we need to read in a new directory */
	    snprintf(fullpath, SQUID_MAXPATHLEN, "%s/%02X/%02X",
		sd->path,
		curlvl1, curlvl2);
	    if (dirs_opened)
		return -1;
	    td = opendir(fullpath);
	    dirs_opened++;
	    if (td == NULL) {
		debug(47, 1) ("commonUfsDirGetNextFile: opendir: %s: %s\n",
		    fullpath, xstrerror());
	    } else {
		entry = readdir(td);	/* skip . and .. */
		entry = readdir(td);
		if (entry == NULL && errno == ENOENT)
		    debug(47, 1) ("commonUfsDirGetNextFile: directory does not exist!.\n");
		debug(47, 3) ("commonUfsDirGetNextFile: Directory %s\n", fullpath);
	    }
	}
	if (td != NULL && (entry = readdir(td)) != NULL) {
	    in_dir++;
	    if (sscanf(entry->d_name, "%x", &fn) != 1) {
		debug(47, 3) ("commonUfsDirGetNextFile: invalid %s\n",
		    entry->d_name);
		continue;
	    }
	    if (!UFSSwapDir::FilenoBelongsHere(fn, sd->index, curlvl1, curlvl2)) {
		debug(47, 3) ("commonUfsDirGetNextFile: %08X does not belong in %d/%d/%d\n",
		    fn, sd->index, curlvl1, curlvl2);
		continue;
	    }
	    if (sd->mapBitTest(fn)) {
		debug(47, 3) ("commonUfsDirGetNextFile: Locked, continuing with next.\n");
		continue;
	    }
	    snprintf(fullfilename, SQUID_MAXPATHLEN, "%s/%s",
		fullpath, entry->d_name);
	    debug(47, 3) ("commonUfsDirGetNextFile: Opening %s\n", fullfilename);
	    fd = file_open(fullfilename, O_RDONLY | O_BINARY);
	    if (fd < 0)
		debug(47, 1) ("commonUfsDirGetNextFile: %s: %s\n", fullfilename, xstrerror());
	    else
		store_open_disk_fd++;
	    continue;
	}
	if (td != NULL)
	    closedir(td);
	td = NULL;
	in_dir = 0;
	if (sd->validL2(++curlvl2))
	    continue;
	curlvl2 = 0;
	if (sd->validL1(++curlvl1))
	    continue;
	curlvl1 = 0;
	done = 1;
    }
    *filn_p = fn;
    return fd;
}
