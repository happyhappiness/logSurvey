#endif
                      0 );
        } else {
            fprintf( stderr, "detected dead child (pid=%ld), status %d\n%c",
                      (long) pid, status, 0 );
        }
    }
    errno = saveerr;
