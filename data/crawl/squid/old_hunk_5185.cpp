
    if (fd < 0) {
        debug(47, 1) ("%s: %s\n", path, xstrerror());
        fatal("storeCossDirInit: Failed to open a COSS directory.");
    }

    n_coss_dirs++;
    (void) storeDirGetBlkSize(path, &fs.blksize);
}

void
