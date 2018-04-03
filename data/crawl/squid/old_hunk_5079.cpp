logfileOpen(const char *path, size_t bufsz, int fatal_flag)
{
    int fd;
    Logfile *lf;
    fd = file_open(path, O_WRONLY | O_CREAT | O_TEXT);

    if (DISK_ERROR == fd) {
        if (ENOENT == errno && fatal_flag) {
            fatalf("Cannot open '%s' because\n"
                   "\tthe parent directory does not exist.\n"
                   "\tPlease create the directory.\n", path);
        } else if (EACCES == errno && fatal_flag) {
            fatalf("Cannot open '%s' for writing.\n"
                   "\tThe parent directory must be writeable by the\n"
                   "\tuser '%s', which is the cache_effective_user\n"
                   "\tset in squid.conf.", path, Config.effectiveUser);
        } else {
            debug(50, 1) ("logfileOpen: %s: %s\n", path, xstrerror());
            return NULL;
        }
    }

    lf = static_cast<Logfile *>(xcalloc(1, sizeof(*lf)));
    lf->fd = fd;

    if (fatal_flag)
        lf->flags.fatal = 1;

    xstrncpy(lf->path, path, MAXPATHLEN);

    if (bufsz > 0) {
        lf->buf = (char *) xmalloc(bufsz);
        lf->bufsz = bufsz;
    }

    return lf;
}

void
logfileClose(Logfile * lf)
{
    logfileFlush(lf);
    file_close(lf->fd);

    if (lf->buf)
        xfree(lf->buf);