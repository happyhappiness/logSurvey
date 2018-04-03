    return roles;
}

void
writePidFile(void)
{
    int fd;
    const char *f = NULL;
    mode_t old_umask;
    char buf[32];

    debugs(50, DBG_IMPORTANT, "creating PID file: " << Config.pidFilename);

    if ((f = Config.pidFilename) == NULL)
        return;

    if (!strcmp(Config.pidFilename, "none"))
        return;

    enter_suid();

    old_umask = umask(022);

    fd = open(f, O_WRONLY | O_CREAT | O_TRUNC | O_TEXT, 0644);
    int xerrno = errno;

    umask(old_umask);

    leave_suid();

    if (fd < 0) {
        debugs(50, DBG_CRITICAL, "" << f << ": " << xstrerr(xerrno));
        debug_trap("Could not open PID file for write");
        return;
    }

    snprintf(buf, 32, "%d\n", (int) getpid());
    const size_t ws = write(fd, buf, strlen(buf));
    assert(ws == strlen(buf));
    close(fd);
}

void
removePidFile()
{
    if (Config.pidFilename && strcmp(Config.pidFilename, "none") != 0) {
        debugs(50, DBG_IMPORTANT, "removing PID file: " << Config.pidFilename);
        enter_suid();
        safeunlink(Config.pidFilename, 0);
        leave_suid();
    }
}

pid_t
readPidFile(void)
{
    FILE *pid_fp = NULL;
    const char *f = Config.pidFilename;
    char *chroot_f = NULL;
    pid_t pid = -1;
    int i;

    if (f == NULL || !strcmp(Config.pidFilename, "none")) {
        fprintf(stderr, APP_SHORTNAME ": ERROR: No PID file name defined\n");
        exit(1);
    }

    if (Config.chroot_dir && geteuid() == 0) {
        int len = strlen(Config.chroot_dir) + 1 + strlen(f) + 1;
        chroot_f = (char *)xmalloc(strlen(Config.chroot_dir) + 1 + strlen(f) + 1);
        snprintf(chroot_f, len, "%s/%s", Config.chroot_dir, f);
        f = chroot_f;
    }

    if ((pid_fp = fopen(f, "r"))) {
        pid = 0;

        if (fscanf(pid_fp, "%d", &i) == 1)
            pid = (pid_t) i;

        fclose(pid_fp);
    } else {
        int xerrno = errno;
        if (xerrno != ENOENT) {
            fprintf(stderr, APP_SHORTNAME ": ERROR: Could not open PID file for read\n");
            fprintf(stderr, "\t%s: %s\n", f, xstrerr(xerrno));
            exit(1);
        }
    }

    safe_free(chroot_f);
    return pid;
}

/* A little piece of glue for odd systems */
#ifndef RLIMIT_NOFILE
#ifdef RLIMIT_OFILE
