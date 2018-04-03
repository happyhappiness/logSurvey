        }
        if (action == -1) {
            session_logout(detail, detail_len);
            printf("%s OK message=\"Bye\"\n", user_key);
        } else if (action == 1) {
            session_login(detail, detail_len);
            printf("%s OK message=\"Welcome\"\n", user_key);
        } else if (session_active(detail, detail_len)) {
            session_login(detail, detail_len);
            printf("%s OK\n", user_key);
        } else if (default_action == 1) {
            session_login(detail, detail_len);
            printf("%s ERR message=\"Welcome\"\n", user_key);
        } else {
            printf("%s ERR message=\"No session available\"\n", user_key);
        }
    }
    shutdown_db();