    if ( debugFlag & 0x01 ) fprintf( stderr, "# [3] %s\n", fn );
    int fd = open( fn, O_RDONLY );
    if ( fd != -1 ) {
        if ( read(fd,::linebuffer,::buffersize-1) > 60 ) {
            ::linebuffer[ ::buffersize-1 ] = '\0'; // force-terminate string

            // check the offset into the start of object data. The offset is
