    setbuf(stdout, NULL);

    if (argc != 3) {
        fprintf(stderr, "Usage: basic_nis_auth <domainname> <nis map for password>\n");
        fprintf(stderr, "\n");
        fprintf(stderr, "Example basic_nis_auth mydomain.com passwd.byname\n");
        exit(1);
    }
    nisdomain = argv[1];
