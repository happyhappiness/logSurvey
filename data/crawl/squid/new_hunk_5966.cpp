    }
    /* Reopen the log.  It may have been renamed "manually" */
    lf->fd = file_open(lf->path, O_WRONLY | O_CREAT);
    if (DISK_ERROR == lf->fd && lf->flags.fatal) {
	debug(50, 1) ("logfileRotate: %s: %s\n", lf->path, xstrerror());
	fatalf("Cannot open %s: %s", lf->path, xstrerror());
    }
