    fd_bytes(lf->fd, s, FD_WRITE);
    if (s == len)
	return;
    if (!lf->flags.fatal)
	return;
    fatalf("logfileWrite: %s: %s\n", lf->path, xstrerror());
}
