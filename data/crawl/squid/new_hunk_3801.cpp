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
