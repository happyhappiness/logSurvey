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
