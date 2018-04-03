    return h.id;
}

#if DRIVER
int
main(int argc, char *argv[])
{
    rfc1035_header h;
    char input[512];
    char buf[512];
    char rbuf[512];
    size_t sz = 512;
    unsigned short sid;
    off_t offset = 0;
    int s;
    int rl;
    struct sockaddr_in S;
