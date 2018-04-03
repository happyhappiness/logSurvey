        urldecode(passwd, ptr, MAXPASS);

        if (authenticate(sockfd, username, passwd))
            printf("OK\n");
        else
            printf("ERR\n");
    }
    close(sockfd);
    exit(1);
