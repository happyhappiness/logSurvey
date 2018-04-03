        fprintf(stderr, "digest_file_auth: cannot create hash table\n");
        exit(1);
    }
    f = fopen(passwordFile, "r");
    while (fgets(buf, 8192, f) != NULL) {
        if ((buf[0] == '#') || (buf[0] == ' ') || (buf[0] == '\t') ||
                (buf[0] == '\n'))
            continue;
        user = strtok(buf, ":\n");
        realm = strtok(NULL, ":\n");
        passwd = strtok(NULL, ":\n");
        if (!passwd) {
