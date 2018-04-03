
    while (fgets(request, HELPER_INPUT_BUFFER, stdin)) {
        int action = 0;
        const char *user_key = strtok(request, " \n");
        const char *detail = strtok(NULL, "\n");
        const char *lastdetail = strrchr(detail, ' ');
        size_t detail_len = strlen(detail);
        if (lastdetail) {
