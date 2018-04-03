    fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK);
#endif
    nas_ipaddr = ntohl(salocal.sin_addr.s_addr);
    while (fgets(buf, HELPER_INPUT_BUFFER, stdin) != NULL) {
        char *end;
        /* protect me form to long lines */
        if ((end = strchr(buf, '\n')) == NULL) {
            err = 1;
            continue;
        }
        if (err) {
            SEND_ERR("");
            err = 0;
            continue;
        }
        if (strlen(buf) > HELPER_INPUT_BUFFER) {
            SEND_ERR("");
            continue;
        }
        /* Strip off the trailing newline */
        *end = '\0';

        /* Parse out the username and password */
        ptr = buf;
        while (isspace(*ptr))
            ptr++;
        if ((end = strchr(ptr, ' ')) == NULL) {
            SEND_ERR("No password");
            continue;
        }
        *end = '\0';
