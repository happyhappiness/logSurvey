#endif
                      0 );
        } else {
            snprintf( line, 128, "detected dead child (pid=%ld), status %d\n%c",
                      (long) pid, status, 0 );
        }
        write( STDERR_FILENO, line, strlen(line) );
    }
    errno = saveerr;
