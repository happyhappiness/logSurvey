    return 1;
}

static void
storeCreateDirectory(const char *path, int lvl)
{
    struct stat st;
    if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) {
	debug(20, lvl) ("%s exists\n", path);
    } else if (mkdir(path, 0755) == 0) {
	debug(20, lvl) ("%s created\n", path);
    } else if (errno == EEXIST) {
	debug(20, lvl) ("%s exists\n", path);
    } else {
	snprintf(tmp_error_buf, ERROR_BUF_SZ,
	    "Failed to make swap directory %s: %s",
	    path, xstrerror());
	fatal(tmp_error_buf);
    }
}

static int
