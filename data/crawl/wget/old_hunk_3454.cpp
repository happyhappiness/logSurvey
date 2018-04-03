static int msock = -1;
static struct sockaddr *addr;

/* A kludge, but still better than passing the host name all the way
   to connect_to_one.  */
static const char *connection_host_name;
