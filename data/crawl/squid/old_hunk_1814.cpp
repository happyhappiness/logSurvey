        fprintf(stderr, "FATAL: %s: %s\n", passwdfile, xstrerror());
        exit(1);
    }
    while (fgets(buf, 8192, f) != NULL) {
        if ((buf[0] == '#') || (buf[0] == ' ') || (buf[0] == '\t') ||
                (buf[0] == '\n'))
            continue;
        user = strtok(buf, ":\n\r");
        passwd = strtok(NULL, ":\n\r");
        if ((strlen(user) > 0) && passwd) {
            u = static_cast<user_data*>(xmalloc(sizeof(*u)));
