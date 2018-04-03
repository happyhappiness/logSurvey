    int i = 0;

    for (t = s; *t != '\0'; ++t) {
        if (i > HELPER_INPUT_BUFFER-2) {
            buf[i] = '\0';
            (void) fputs(buf, p);
            i = 0;
