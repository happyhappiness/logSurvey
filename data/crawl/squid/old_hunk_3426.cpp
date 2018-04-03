            if (ferror(stdin)) {
                if (debug)
                    fprintf(stderr,
                            "%s| %s: fgets() failed! dying..... errno=%d (%s)\n",
                            LogTime(), PROGRAM, ferror(stdin),
                            strerror(ferror(stdin)));

