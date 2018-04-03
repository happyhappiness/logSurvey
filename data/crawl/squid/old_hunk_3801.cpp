                if (answers[i].type == RFC1035_TYPE_A) {

                    struct in_addr a;
                    memcpy(&a, answers[i].rdata, 4);
                    printf("A\t%d\t%s\n", answers[i].ttl, inet_ntoa(a));
                } else if (answers[i].type == RFC1035_TYPE_AAAA) {

                    struct in6_addr a;
                    memcpy(&a, answers[i].rdata, 16);
                    printf("AAAA\t%d\t%s\n", answers[i].ttl, inet_ntoa(a));
                } else if (answers[i].type == RFC1035_TYPE_PTR) {
                    char ptr[RFC1035_MAXHOSTNAMESZ];
                    strncpy(ptr, answers[i].rdata, answers[i].rdlength);
