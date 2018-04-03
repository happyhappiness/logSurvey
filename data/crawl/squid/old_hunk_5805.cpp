    storeCossDirOpenSwapLog(sd);
    storeCossDirRebuild(sd);
    cs->fd = file_open(sd->path, O_RDWR | O_CREAT);
    n_coss_dirs++;
    (void) storeDirGetBlkSize(sd->path, &sd->fs.blksize);
}