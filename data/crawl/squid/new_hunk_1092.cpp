                strcpy(buff,tbuff);
            }
        } else {
            xfree(token);
            if (debug)
                fprintf(stderr, "%s| %s: received Kerberos token\n",
                        LogTime(), PROGRAM);
