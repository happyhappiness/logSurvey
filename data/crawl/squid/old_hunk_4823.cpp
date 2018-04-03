}

int commIsHalfClosed(int fd) {
    if (fdc_table[fd].active != 1) {
        fatal("foo");
    }

    return fdc_table[fd].half_closed;
}