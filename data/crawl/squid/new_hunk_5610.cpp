    storeCossDirRebuild(sd);
    cs->fd = file_open(sd->path, O_RDWR | O_CREAT);
    if (cs->fd < 0) {
	debug(47, 1) ("%s: %s\n", sd->path, xstrerror());
	fatal("storeCossDirInit: Failed to open a COSS directory.");
    }
    n_coss_dirs++;
