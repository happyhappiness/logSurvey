        fprintf(stderr, "\t-g\t\t\tfirst query parameter is base DN extension\n\t\t\t\tfor this query\n");
        fprintf(stderr, "\t-S\t\t\tStrip NT domain from usernames\n");
        fprintf(stderr, "\t-K\t\t\tStrip Kerberos realm from usernames\n");
        fprintf(stderr, "\n");
        fprintf(stderr, "\tIf you need to bind as a user to perform searches then use the\n\t-D binddn -w bindpasswd or -D binddn -W secretfile options\n\n");
        exit(1);