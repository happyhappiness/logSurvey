    ll->fd = file_open(realpath, O_WRONLY | O_CREAT | O_TEXT);

    if (DISK_ERROR == ll->fd && lf->flags.fatal) {
        int xerrno = errno;
        debugs(50, DBG_CRITICAL, MYNAME << "ERROR: " << lf->path << ": " << xstrerr(xerrno));
        fatalf("Cannot open %s: %s", lf->path, xstrerr(xerrno));
    }
}

