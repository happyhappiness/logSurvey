        auth = passwd_auth(user, passwd);
#endif
        if (auth == 0) {
            printf("ERR No such user\n");
        } else {
            if (auth == 2) {
                printf("ERR Wrong password\n");
            } else {
                printf(OK);
            }
        }
    }
    exit(0);
}
