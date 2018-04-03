        auth = passwd_auth(user, passwd);
#endif
        if (auth == 0) {
            SEND_ERR("No such user");
        } else {
            if (auth == 2) {
                SEND_ERR("Wrong password");
            } else {
                SEND_OK("");
            }
        }
    }
    return 0;
}
