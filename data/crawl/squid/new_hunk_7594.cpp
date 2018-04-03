}


int readPidFile()
{
    FILE *pid_fp = NULL;
    char *f = NULL;
    int pid = -1;

    if ((f = Config.pidFilename) == NULL) {
	fprintf(stderr, "%s: ERROR: No pid file name defined\n", appname);
	exit(1);
    }
    pid_fp = fopen(f, "r");
    if (pid_fp != NULL) {
	if (fscanf(pid_fp, "%d", &pid) != 1)
	    pid = 0;
	fclose(pid_fp);
    } else {
	if (errno != ENOENT) {
	    fprintf(stderr, "%s: ERROR: Could not read pid file\n", appname);
	    fprintf(stderr, "\t%s: %s\n", f, xstrerror());
	    exit(1);
	}
    }
    return pid;
}


void setMaxFD()
{
#if HAVE_SETRLIMIT