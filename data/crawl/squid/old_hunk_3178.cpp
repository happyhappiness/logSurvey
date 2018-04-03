
    init_db();

    while (fgets(request, sizeof(request), stdin)) {
        const char *user_key, *detail;
        char *lastdetail;
        int action = 0;
        user_key = strtok(request, " \n");
        detail = strtok(NULL, "\n");
        lastdetail = strrchr(detail, ' ');
        if (lastdetail) {
            if (strcmp(lastdetail, " LOGIN") == 0) {
                *lastdetail++ = '\0';
                action = 1;
            } else if (strcmp(lastdetail, " LOGOUT") == 0) {
                action = -1;
                *lastdetail++ = '\0';
            }
        }
        if (action == -1) {
            session_logout(detail);
            printf("%s OK message=\"Bye\"\n", user_key);
        } else if (action == 1) {
            session_login(detail);
            printf("%s OK message=\"Welcome\"\n", user_key);
        } else if (session_active(detail)) {
            session_login(detail);
            printf("%s OK\n", user_key);
        } else if (default_action == 1) {
            session_login(detail);
            printf("%s ERR message=\"Welcome\"\n", user_key);
        } else {
            printf("%s ERR message=\"No session available\"\n", user_key);
