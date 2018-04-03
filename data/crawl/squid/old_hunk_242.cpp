    }
    FILE *f = fopen(passwordFile, "r");
    if (!f) {
        fprintf(stderr, "digest_file_auth: cannot open password file: %s\n", xstrerror());
        exit(1);
    }
    unsigned int lineCount = 0;
