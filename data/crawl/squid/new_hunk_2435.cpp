        }
        if (action == -1) {
            session_logout(detail, detail_len);
            printf("%s OK message=\"Bye\"\n", channel_id);
        } else if (action == 1) {
            session_login(detail, detail_len);
            printf("%s OK message=\"Welcome\"\n", channel_id);
        } else if (session_active(detail, detail_len)) {
            if (fixed_timeout == 0) {
                session_login(detail, detail_len);
            }
            printf("%s OK\n", channel_id);
        } else if (default_action == 1) {
            session_login(detail, detail_len);
            printf("%s ERR message=\"Welcome\"\n", channel_id);
        } else {
            printf("%s ERR message=\"No session available\"\n", channel_id);
        }
    }
    shutdown_db();