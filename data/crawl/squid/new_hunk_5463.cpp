    if (xrename(new_path, swaplog_path) < 0) {
	fatal("storeCossDirCloseTmpSwapLog: rename failed");
    }
    anfd = file_open(swaplog_path, O_WRONLY | O_CREAT | O_BINARY);
    if (anfd < 0) {
	debug(50, 1) ("%s: %s\n", swaplog_path, xstrerror());
	fatal("storeCossDirCloseTmpSwapLog: Failed to open swap log.");
    }
    safe_free(swaplog_path);
    safe_free(new_path);
    sd->swaplog_fd = anfd;
    debug(47, 3) ("Cache COSS Dir #%d log opened on FD %d\n", sd->index, anfd);
}

static FILE *
storeCossDirOpenTmpSwapLog(CossSwapDir * sd, int *clean_flag, int *zero_flag)
{
    char *swaplog_path = xstrdup(storeCossDirSwapLogFile(sd, NULL));
    char *clean_path = xstrdup(storeCossDirSwapLogFile(sd, ".last-clean"));
    char *new_path = xstrdup(storeCossDirSwapLogFile(sd, ".new"));
    struct stat log_sb;
    struct stat clean_sb;
    FILE *fp;
    int anfd;
    if (stat(swaplog_path, &log_sb) < 0) {
	debug(50, 1) ("Cache COSS Dir #%d: No log file\n", sd->index);
safe_free(swaplog_path);
	safe_free(clean_path);
	safe_free(new_path);
	return NULL;
    }
    *zero_flag = log_sb.st_size == 0 ? 1 : 0;
    /* close the existing write-only FD */
    if (sd->swaplog_fd >= 0)
	file_close(sd->swaplog_fd);
    /* open a write-only FD for the new log */
    anfd = file_open(new_path, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY);
    if (anfd < 0) {
	debug(50, 1) ("%s: %s\n", new_path, xstrerror());
	fatal("storeDirOpenTmpSwapLog: Failed to open swap log.");
    }
    sd->swaplog_fd = anfd;
    /* open a read-only stream of the old log */
    fp = fopen(swaplog_path, "rb");
    if (fp == NULL) {
