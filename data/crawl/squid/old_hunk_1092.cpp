                strcpy(buff,tbuff);
            }
        } else {
            free(token);
            if (debug)
                fprintf(stderr, "%s| %s: received Kerberos token\n",
                        LogTime(), PROGRAM);
