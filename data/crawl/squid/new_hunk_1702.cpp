    }
}

/// set the working directory.
static void
mainSetCwd(void)
{
    char pathbuf[MAXPATHLEN];
    static bool chrooted = false;

    if (Config.chroot_dir && !chrooted) {
        chrooted = true;

        if (chroot(Config.chroot_dir) != 0);
            fatal("failed to chroot");

        strncpy(pathbuf, "/", sizeof(pathbuf)-1);
    }

    if (Config.coredump_dir && strcmp("none", Config.coredump_dir) == 0) {
        strncpy(pathbuf, Config.coredump_dir, sizeof(pathbuf)-1);
    }

    if (chdir(pathbuf) == 0) {
        debugs(0, DBG_IMPORTANT, "Set Current Directory to " << Config.coredump_dir);
        return;
    } else {
        debugs(50, DBG_CRITICAL, "chdir: " << pathbuf << ": " << xstrerror());
    }

    /* If we don't have coredump_dir or couldn't cd there, report current dir */
