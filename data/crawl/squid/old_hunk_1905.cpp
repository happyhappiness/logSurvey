        setmode(put_fd, O_BINARY);
#endif

        fstat(put_fd, &sb);
    }

    if (!host) {