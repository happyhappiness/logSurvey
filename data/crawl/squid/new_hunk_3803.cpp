    memcpy(&S.sin_addr.s_addr, h->h_addr_list[0], sizeof(S.sin_addr.s_addr));
    S.sin_port = htons(port);
    S.sin_family = AF_INET;
    if (debug) {
        char tmp[16];
        fprintf(stderr, "%s (%s) %d %s\n", host, inet_ntop(AF_INET, &S.sin_addr,tmp,sizeof(tmp)), (int) port, path);
    }
    s = socket(PF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        perror("socket");