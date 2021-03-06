
        if ( ! inet_pton(AF_INET, argv[var], &((struct sockaddr_in *)S)->sin_addr.s_addr) ) {
            perror("listen address");
            exit(EXIT_FAILURE);
        }
    }

    while (fgets(input, PACKET_BUFSZ, stdin))
    {

        struct in6_addr junk6;

        struct in_addr junk4;
        strtok(input, "\r\n");
        memset(buf, '\0', PACKET_BUFSZ);
        sz = PACKET_BUFSZ;

        if (inet_pton(AF_INET6, input, &junk6)) {
            sid = rfc1035BuildPTRQuery6(junk6, buf, &sz, edns_max);
            sidb=0;
        } else if (inet_pton(AF_INET, input, &junk4)) {
            sid = rfc1035BuildPTRQuery4(junk4, buf, &sz, edns_max);
            sidb=0;
        } else {
            sid = rfc1035BuildAAAAQuery(input, buf, &sz, edns_max);
            sidb = rfc1035BuildAQuery(input, buf, &sz, edns_max);
        }

        sendto(s, buf, sz, 0, S, sizeof(*S));

        do {
            fd_set R;

            struct timeval to;
            FD_ZERO(&R);
            FD_SET(s, &R);
            to.tv_sec = 10;
            to.tv_usec = 0;
            rl = select(s + 1, &R, NULL, NULL, &to);
        } while (0);

        if (rl < 1) {
            printf("TIMEOUT\n");
            continue;
        }

        memset(rbuf, '\0', PACKET_BUFSZ);
        rl = recv(s, rbuf, PACKET_BUFSZ, 0);
        {
            unsigned short rid = 0;
            int i;
            int n;
            rfc1035_rr *answers = NULL;
            n = rfc1035AnswersUnpack(rbuf,
                                     rl,
                                     &answers,
                                     &rid);

            if (n < 0) {
                printf("ERROR %d\n", -n);
            } else if (rid != sid && rid != sidb) {
                printf("ERROR, ID mismatch (%#hx, %#hx)\n", sid, rid);
                printf("ERROR, ID mismatch (%#hx, %#hx)\n", sidb, rid);
            } else {
                printf("%d answers\n", n);

                for (i = 0; i < n; i++) {
                    if (answers[i].type == RFC1035_TYPE_A) {

                        struct in_addr a;
                        char tmp[16];
                        memcpy(&a, answers[i].rdata, 4);
                        printf("A\t%d\t%s\n", answers[i].ttl, inet_ntop(AF_INET,&a,tmp,16));
                    } else if (answers[i].type == RFC1035_TYPE_AAAA) {

                        struct in6_addr a;
                        char tmp[INET6_ADDRSTRLEN];
                        memcpy(&a, answers[i].rdata, 16);
                        printf("AAAA\t%d\t%s\n", answers[i].ttl, inet_ntop(AF_INET6,&a,tmp,sizeof(tmp)));
                    } else if (answers[i].type == RFC1035_TYPE_PTR) {
                        char ptr[RFC1035_MAXHOSTNAMESZ];
                        strncpy(ptr, answers[i].rdata, answers[i].rdlength);
                        printf("PTR\t%d\t%s\n", answers[i].ttl, ptr);
                    } else if (answers[i].type == RFC1035_TYPE_CNAME) {
                        char ptr[RFC1035_MAXHOSTNAMESZ];
                        strncpy(ptr, answers[i].rdata, answers[i].rdlength);
                        printf("CNAME\t%d\t%s\n", answers[i].ttl, ptr);
                    } else {
                        fprintf(stderr, "can't print answer type %d\n",
                                (int) answers[i].type);
                    }
                }
            }
        }
    }

    return EXIT_SUCCESS;
}

#endif
