                     * out of device space - recover by rotating and hoping that rotation count drops a big one.
                     */
                    if (err == EFBIG || err == ENOSPC) {
                        fprintf(stderr, "WARNING: %s writing %s. Attempting to recover via a log rotation.\n",strerror(err),argv[1]);
                        fclose(fp);
                        rotate(argv[1], rotate_count);
                        fp = fopen(argv[1], "a");
