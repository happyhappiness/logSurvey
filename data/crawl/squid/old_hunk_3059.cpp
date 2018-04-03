    // seek end of output file ...
    off_t position = lseek( out, filesize-metasize-1, SEEK_SET );
    if ( position == -1 ) {
        fprintf( stderr, "lseek(%s,%lu): %s\n", filename, 
                 (unsigned long)filesize-metasize,
                 strerror(errno) );
        BAUTZ(false);
