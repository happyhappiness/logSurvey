                  (unsigned long)temp.timestamp, (unsigned long)temp.lastref,
                  (unsigned long)temp.expires, (unsigned long)temp.lastmod, temp.flags, temp.refcount );
    } else {
        snprintf( timeb, sizeof(timeb), "%08lx %08lx %08lx %08lx %04x %5hu ", (unsigned long)-1, (unsigned long)-1, (unsigned long)-1, (unsigned long)-1, 0, 0 );
    }

    // make sure that there is just one printf()
