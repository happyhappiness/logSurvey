}

void
Packer::Printf(const char *fmt,...)
{
    va_list args;
    va_start(args, fmt);

    assert(real_handler && packer_vprintf);
    packer_vprintf(real_handler, fmt, args);
    va_end(args);
}

