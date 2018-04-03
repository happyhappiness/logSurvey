    fprintf(stderr, "--kerberos full kerberos helper path with arguments\n");
}

int
main(int argc, char *const argv[])
{
    char buf[MAX_AUTHTOKEN_LEN];
    char tbuff[MAX_AUTHTOKEN_LEN];
    char buff[MAX_AUTHTOKEN_LEN+2];
    char *c;
    int debug = 0;
    int length;
    int nstart = 0, kstart = 0;
    int nend = 0, kend = 0;
    uint8_t *token;
    char **nargs, **kargs;
    int fpid;
    FILE *FDKIN,*FDKOUT;
    FILE *FDNIN,*FDNOUT;
    int pkin[2];
    int pkout[2];
    int pnin[2];
