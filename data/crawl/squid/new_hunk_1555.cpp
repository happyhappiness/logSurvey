        if (!nispasswd) {
            /* User does not exist */
            printf("ERR No such user\n");
#if HAVE_CRYPT
        } else if (strcmp(nispasswd, (char *) crypt(passwd, nispasswd)) == 0) {
            /* All ok !, thanks... */
            printf("OK\n");
#else
        } else {
            /* Password incorrect */
            printf("BH message=\"Missing crypto capability\"\n");
#endif
        } else {
            /* Password incorrect */
            printf("ERR Wrong password\n");
