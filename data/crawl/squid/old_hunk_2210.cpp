    if (r->offset > -1 && r->offset != fs->offset) {
        if (lseek(fs->fd, r->offset, SEEK_SET) < 0) {
            DEBUG(1) {
                fprintf(stderr, "%d FD %d, offset %"PRId64": ", (int) mypid, fs->fd, (int64_t)r->offset);
                perror("lseek");
            }
        }
    }

    DEBUG(2) {
        fprintf(stderr, "%d WRITE %d,%d,%"PRId64"\n", (int) mypid,
                fs->fd, wrtlen, (int64_t)r->offset);
    }
    x = write(fs->fd, buf, wrtlen);
