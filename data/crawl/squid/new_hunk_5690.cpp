    int s;
    int rl;
    struct sockaddr_in S;
    if (3 != argc) {
	fprintf(stderr, "usage: %s ip port\n", argv[0]);
	return 1;
    }
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    s = socket(PF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
	perror("socket");
	return 1;
    }
    memset(&S, '\0', sizeof(S));
    S.sin_family = AF_INET;
    S.sin_port = htons(atoi(argv[2]));
    S.sin_addr.s_addr = inet_addr(argv[1]);
    while (fgets(input, 512, stdin)) {
	struct in_addr junk;
	strtok(input, "\r\n");
