}

void
Packer::vappendf(const char *fmt, va_list args)
{
    assert(real_handler && packer_vprintf);
    packer_vprintf(real_handler, fmt, args);
}

