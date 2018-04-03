    va_end(ap);
    if (x > 0) {
        dbuf[x] = '\0';
        ++x;
        fputs(dbuf, stdout);
        *(dbuf) = '\0';
    } else {
