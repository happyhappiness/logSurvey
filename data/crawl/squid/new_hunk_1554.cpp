        } else if (strcmp(nispasswd, (char *) crypt(passwd, nispasswd)) == 0) {
            /* All ok !, thanks... */
            printf("OK\n");
        } else {
            /* Password incorrect */
            printf("ERR Wrong password\n");
#else
        } else {
            /* Password incorrect */
            printf("BH message=\"Missing crypto capability\"\n");
#endif
        }
    }
    exit(0);