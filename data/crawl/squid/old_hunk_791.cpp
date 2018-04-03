    *buf = 0;
    int x;

    errno = 0;
    if ((x = vsnprintf(buf, sizeof(buf), fmt, vargs)) < 0) {
        fatalf( xstrerror(errno));
        return;
    }

    if (x < sizeof(buf)) {
        append(buf, x);