    fprintf(stderr,
            "Version: %s\n"
            "Usage: %s [-arsv] [-g count] [-h remote host] [-H 'string'] [-i IMS] [-I ping-interval] [-j 'Host-header']"
            "[-k] [-l local-host] [-m method] "
#if HAVE_GSSAPI
            "[-n] [-N] "
#endif
            "[-p port] [-P file] [-t count] [-T timeout] [-u proxy-user] [-U www-user] "
            "[-V version] [-w proxy-password] [-W www-password] url\n"
            "\n"
            "Options:\n"
