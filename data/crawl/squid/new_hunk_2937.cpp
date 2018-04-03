            printf("TIMEOUT\n");
            continue;
        }
        memset(rbuf, '\0', RFC1035_DEFAULT_PACKET_SZ);
        rl = recv(s, rbuf, RFC1035_DEFAULT_PACKET_SZ, 0);
        {
            unsigned short rid = 0;
            int i;
