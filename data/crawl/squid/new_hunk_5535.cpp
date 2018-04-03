    return loadav;
}

void
storeAufsDirIOUnlinkFile(char *path)
{
#if USE_TRUNCATE_NOT_UNLINK
    aioTruncate(path, NULL, NULL);
#else
    aioUnlink(path, NULL, NULL);
#endif
}

/* ========== LOCAL FUNCTIONS ABOVE, GLOBAL FUNCTIONS BELOW ========== */

static struct cache_dir_option options[] =
{
#if NOT_YET_DONE
