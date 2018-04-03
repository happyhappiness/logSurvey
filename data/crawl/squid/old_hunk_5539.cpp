    fd_note(diskdinfo->wfd, "squid -> diskd");
    commSetTimeout(diskdinfo->wfd, -1, NULL, NULL);
    commSetNonBlocking(diskdinfo->wfd);
    storeDiskdDirInitBitmap(sd);
    if (storeDiskdDirVerifyCacheDirs(sd) < 0)
	fatal(errmsg);
    storeDiskdDirOpenSwapLog(sd);
    storeDiskdDirRebuild(sd);
    if (!started_clean_event) {
	eventAdd("storeDirClean", storeDiskdDirCleanEvent, NULL, 15.0, 1);
	started_clean_event = 1;
    }
    (void) storeDirGetBlkSize(sd->path, &sd->fs.blksize);
    comm_quick_poll_required();
}

