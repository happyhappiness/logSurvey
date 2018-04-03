
        unsigned count(0);
        for ( tail = head; tail != NULL; tail = tail->next ) {
            if ( count++ ) printf( "#%22u", count );
#if defined(LINUX) && putc==_IO_putc
            // I HATE BROKEN LINUX HEADERS!
            // purge.o(.text+0x1040): undefined reference to `_IO_putc'