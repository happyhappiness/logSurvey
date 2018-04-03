void
writePidFile(void)
{
    int fd;
    const char *f = NULL;
    mode_t old_umask;
    char buf[32];
    if ((f = Config.pidFilename) == NULL)
	return;
    if (!strcmp(Config.pidFilename, "none"))
	return;
    enter_suid();
    old_umask = umask(022);
    fd = file_open(f, O_WRONLY | O_CREAT | O_TRUNC, NULL, NULL);
    umask(old_umask);
    leave_suid();
    if (fd < 0) {
	debug(50, 0, "%s: %s\n", f, xstrerror());
	debug_trap("Could not write pid file");
	return;
    }
    sprintf(buf, "%d\n", (int) getpid());
    write(fd, buf, strlen(buf));
    file_close(fd);
}


pid_t
readPidFile(void)
{
    FILE *pid_fp = NULL;
    const char *f = Config.pidFilename;
    pid_t pid = -1;
    int i;

    if (f == NULL || !strcmp(Config.pidFilename, "none")) {
	fprintf(stderr, "%s: ERROR: No pid file name defined\n", appname);
	exit(1);
    }
