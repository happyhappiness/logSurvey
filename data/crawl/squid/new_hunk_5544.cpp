    return 999;
}

void
storeUfsDirIOUnlinkFile(char *path)
{
#if USE_UNLINKD
    unlinkdUnlink(path);
#elif USE_TRUNCATE
    truncate(path, 0);
#else
    unlink(path);
#endif
}

/* ========== LOCAL FUNCTIONS ABOVE, GLOBAL FUNCTIONS BELOW ========== */

static struct cache_dir_option options[] =
{
#if NOT_YET_DONE
