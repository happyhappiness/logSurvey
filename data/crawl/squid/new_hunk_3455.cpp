        case 'L':
            if (buf[1] != '\0') {
                fprintf(fp, "%s", buf + 1);
                /* try to detect the 32-bit file too big write error and rotate */
                int err = ferror(fp);
                clearerr(fp);
                if (err < 0) {
                    /* file too big - recover by rotating the logs and starting a new one.
                     * out of device space - recover by rotating and hoping that rotation count drops a big one.
                     */
                    if (err == EFBIG || err == ENOSPC) {
                        fprintf(stderr, "WARNING: %s writing %s. Attempting to recover via a log rotation.\n",strerror(err),argv[1]);
                        fclose(fp);
                        rotate(argv[1], rotate_count);
                        fp = fopen(argv[1], "a");
                        if (fp == NULL) {
                            perror("fopen");
                            exit(1);
                        }
                        fprintf(fp, "%s", buf + 1);
                    } else {
                        perror("fprintf");
                        exit(1);
                    }
                }
            }
            if (!do_buffer)
                fflush(fp);
