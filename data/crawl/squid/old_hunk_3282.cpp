
    /* Get the IP address of the authentication server */
    if ((auth_ipaddr = get_ipaddr(server)) == 0) {
        fprintf(stderr, "Couldn't find host %s\n", server);
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
