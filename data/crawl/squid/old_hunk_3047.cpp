    static const size_t addon = sizeof(unsigned char) + sizeof(unsigned int);
    bool flag = true;

    if ( debug & 0x01 ) fprintf( stderr, "# [3] %s\n", fn );
    int fd = open( fn, O_RDONLY );
    if ( fd != -1 ) {
        if ( read(fd,::linebuffer,::buffersize-1) > 60 ) {
