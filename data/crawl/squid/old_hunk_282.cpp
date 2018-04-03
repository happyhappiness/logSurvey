        f = chroot_f;
    }

    pid_fp = fopen(f, "r");

    if (pid_fp != NULL) {
        pid = 0;

        if (fscanf(pid_fp, "%d", &i) == 1)
            pid = (pid_t) i;

        fclose(pid_fp);
    } else {
        if (errno != ENOENT) {
            fprintf(stderr, APP_SHORTNAME ": ERROR: Could not read pid file\n");
            fprintf(stderr, "\t%s: %s\n", f, xstrerror());
            exit(1);
        }
    }
