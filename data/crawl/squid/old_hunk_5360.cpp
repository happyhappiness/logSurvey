    mb = va_arg(args, MemBuf *);
    fmt = va_arg(args, char *);
#endif
    memBufVPrintf(mb, fmt, args);
    va_end(args);
}


/* vprintf for other printf()'s to use; calls vsnprintf, extends buf if needed */
void
memBufVPrintf(MemBuf * mb, const char *fmt, va_list vargs)
{
    int sz = 0;
    assert(mb && fmt);
    assert(mb->buf);
    assert(!mb->stolen);	/* not frozen */
    /* assert in Grow should quit first, but we do not want to have a scary infinite loop */
    while (mb->capacity <= mb->max_capacity) {
	mb_size_t free_space = mb->capacity - mb->size;
	/* put as much as we can */
	sz = vsnprintf(mb->buf + mb->size, free_space, fmt, vargs);
	/* check for possible overflow */
	/* snprintf on Linuz returns -1 on overflows */
	/* snprintf on FreeBSD returns at least free_space on overflows */
	if (sz < 0 || sz >= free_space)
	    memBufGrow(mb, mb->capacity + 1);
	else
	    break;
    }
    mb->size += sz;
    /* on Linux and FreeBSD, '\0' is not counted in return value */
    /* on XXX it might be counted */
    /* check that '\0' is appended and not counted */
    if (!mb->size || mb->buf[mb->size - 1]) {
	assert(!mb->buf[mb->size]);
    } else {
	mb->size--;
    }
}

