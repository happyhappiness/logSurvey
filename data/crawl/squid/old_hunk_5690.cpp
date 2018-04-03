    int s;
    int rl;
    struct sockaddr_in S;
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    s = socket(PF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
	perror("socket");
	return 1;
    }
    while (fgets(input, 512, stdin)) {
	struct in_addr junk;
	strtok(input, "\r\n");
