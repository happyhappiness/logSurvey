        }
    }

    DEBUG(2)
    fprintf(stderr, "%d WRITE %d,%d,%"PRId64"\n", (int) mypid,
            fs->fd, wrtlen, (int64_t)r->offset);
    x = write(fs->fd, buf, wrtlen);

    if (x < 0) {
