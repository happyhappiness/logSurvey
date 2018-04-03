    fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK);
#endif
    nas_ipaddr = ntohl(salocal.sin_addr.s_addr);
    while (fgets(authstring, MAXLINE, stdin) != NULL) {
        char *end;
        /* protect me form to long lines */
        if ((end = strchr(authstring, '\n')) == NULL) {
            err = 1;
            continue;
        }
        if (err) {
            printf("ERR\n");
            err = 0;
            continue;
        }
        if (strlen(authstring) > MAXLINE) {
            printf("ERR\n");
            continue;
        }
        /* Strip off the trailing newline */
        *end = '\0';

        /* Parse out the username and password */
        ptr = authstring;
        while (isspace(*ptr))
            ptr++;
        if ((end = strchr(ptr, ' ')) == NULL) {
            printf("ERR\n");	/* No password */
            continue;
        }
        *end = '\0';
