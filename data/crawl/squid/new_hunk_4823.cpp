}

int commIsHalfClosed(int fd) {
    assert (fdc_table[fd].active);

    return fdc_table[fd].half_closed;
}