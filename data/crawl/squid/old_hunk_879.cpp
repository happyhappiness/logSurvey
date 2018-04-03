    *space() = '\0';
}

/* calls memBufVPrintf */
void
MemBuf::Printf(const char *fmt,...)
{
    va_list args;
    va_start(args, fmt);
    vappendf(fmt, args);
    va_end(args);
}

/**
 * vappendf for other printf()'s to use; calls vsnprintf, extends buf if needed
 */
