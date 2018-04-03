    file_close(ll->fd);		/* always close */

    if (Config.Log.rotateNumber > 0) {
        snprintf(to, MAXPATHLEN, "%s.%d", lf->path, 0);
        xrename(lf->path, to);
    }
    /* Reopen the log.  It may have been renamed "manually" */
    ll->fd = file_open(lf->path, O_WRONLY | O_CREAT | O_TEXT);

    if (DISK_ERROR == ll->fd && lf->flags.fatal) {
        debugs(50, DBG_CRITICAL, "logfileRotate (stdio): " << lf->path << ": " << xstrerror());
        fatalf("Cannot open %s: %s", lf->path, xstrerror());
    }
}

