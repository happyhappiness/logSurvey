            printf("TIMEOUT\n");
            continue;
        }
        memset(rbuf, '\0', 512);
        rl = recv(s, rbuf, 512, 0);
        {
            unsigned short rid = 0;
            int i;
