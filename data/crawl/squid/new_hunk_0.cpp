    *buf = 0;
    int x;

    va_list ap;
    /* Fix of bug 753r. The value of vargs is undefined
     * after vsnprintf() returns. Make a copy of vargs
     * incase we loop around and call vsnprintf() again.
     */
    va_copy(ap,vargs);
    errno = 0;
    if ((x = vsnprintf(buf, sizeof(buf), fmt, ap)) < 0) {
        fatal(xstrerr(errno));
        return;
    }
    va_end(ap);

    if (x < static_cast<int>(sizeof(buf))) {
        append(buf, x);