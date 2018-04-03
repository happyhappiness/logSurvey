errorInitialize(void)
{
    err_type i;
    int fd;
    char path[MAXPATHLEN];
    struct stat sb;
    for (i = ERR_NONE + 1; i < ERR_MAX; i++) {
	snprintf(path, MAXPATHLEN, "%s/%s",
	    Config.errorDirectory, err_type_str[i]);
	fd = file_open(path, O_RDONLY, NULL, NULL, NULL);
	if (fd < 0) {
	    debug(4, 0) ("errorInitialize: %s: %s\n", path, xstrerror());
	    fatal("Failed to open error text file");
	}
	if (fstat(fd, &sb) < 0)
	    fatal("fstat() failed on error text file");
	safe_free(error_text[i]);
	error_text[i] = xcalloc(sb.st_size + 1, 1);
	if (read(fd, error_text[i], sb.st_size) != sb.st_size)
	    fatal("failed to fully read error text file");
	file_close(fd);
    }
}

void
