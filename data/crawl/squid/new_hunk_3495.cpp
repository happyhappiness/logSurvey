    int do_buffer = 1;

    if (argc < 2) {
        printf("Error: usage: %s <logfile>\n", argv[0]);
        exit(1);
    }
    fp = fopen(argv[1], "a");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }
    setbuf(stdout, NULL);
    close(2);
