
#define REQ_SZ 512

int
main(int argc, char *argv[])
{
    char request[512];
    char msg[1024];
    const struct hostent *result = NULL;
    FILE *logfile = NULL;
    long start;
    long stop;
    char *t = NULL;
    char buf[256];
    int addr_count = 0;
    int alias_count = 0;
    int i;
    int c;
    int opt_s = 0;
    extern char *optarg;
