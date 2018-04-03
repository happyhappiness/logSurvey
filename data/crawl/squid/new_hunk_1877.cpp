        setmode(put_fd, O_BINARY);
#endif

        if (fstat(put_fd, &sb) < 0) {
            fprintf(stderr, "%s: can't identify length of file (%s)\n", argv[0], xstrerror());
        }
    }

    if (!host) {