    fdc_table[fd].half_closed = true;
}

int commIsHalfClosed(int fd) {
    if (fdc_table[fd].active != 1) {
        fatal("foo");
    }

    return fdc_table[fd].half_closed;
}

void
commCheckHalfClosed(void *data) {
    AbortChecker::Instance().doIOLoop();
    eventAdd("commCheckHalfClosed", commCheckHalfClosed, NULL, 1.0, false);
}

AbortChecker &AbortChecker::Instance() {return Instance_;}

AbortChecker AbortChecker::Instance_;
