    }
    FILE *f = fopen(passwordFile, "r");
    if (!f) {
        int xerrno = errno;
        fprintf(stderr, "digest_file_auth: cannot open password file: %s\n", xstrerr(xerrno));
        exit(1);
    }
    unsigned int lineCount = 0;
