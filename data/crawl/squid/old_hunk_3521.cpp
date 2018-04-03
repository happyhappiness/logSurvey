        }
        if (action == -1) {
            session_logout(detail);
            printf("%s OK message=\"Bye\"\n", index);
        } else if (action == 1) {
            session_login(detail);
            printf("%s OK message=\"Welcome\"\n", index);
        } else if (session_active(detail)) {
            session_login(detail);
            printf("%s OK\n", index);
        } else if (default_action == 1) {
            session_login(detail);
            printf("%s ERR message=\"Welcome\"\n", index);
        } else {
            printf("%s ERR message=\"No session available\"\n", index);
        }
    }
    shutdown_db();
