     char *progname;
{
    fprintf(stderr, "\
Usage: %s [-rs] [-i IMS_time] [-h host] [-p port] [-m method] url\n\
Options:\n\
    -r         Force cache to reload URL.\n\
    -s         Silent.  Do not print data to stdout.\n\
    -i IMS     If-Modified-Since time (in Epoch seconds).\n\
    -h host    Retrieve URL from cache on hostname.  Default is localhost.\n\
    -p port    Port number of cache.  Default is %d.\n\
    -m method  Request method, default is GET.\n\
", progname, CACHE_HTTP_PORT);
    exit(1);
}
