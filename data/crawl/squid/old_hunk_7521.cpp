static void sendSignal __P((void));

static void
usage()
{
    fprintf(stderr, "\
Usage: %s [-hsvzCDFRUVY] [-f config-file] [-[au] port] [-k signal]\n\