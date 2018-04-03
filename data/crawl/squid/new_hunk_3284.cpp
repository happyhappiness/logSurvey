        urldecode(passwd, ptr, MAXPASS);

        if (authenticate(sockfd, username, passwd))
            SEND_OK("");
        else
            SEND_ERR("");
    }
    close(sockfd);
    exit(1);
