
/* vprintf for other printf()'s to use */
void
memBufVPrintf(MemBuf * mb, const char *fmt, va_list vargs)
{
    mb_size_t sz = 0;
    assert(mb && fmt);
    assert(mb->buf);
    assert(mb->freefunc);	/* not frozen */
    /* @?@ we do not init buf with '\0', do we have to for vsnprintf?? @?@ */
    /* assert in Grow should quit first, but we do not want to have a scare (1) loop */
    while (mb->capacity <= mb->max_capacity) {
	mb_size_t free_space = mb->capacity - mb->size;
	/* put as much as we can */
	sz = vsnprintf(mb->buf + mb->size, free_space, fmt, vargs) + 1;
	/* check for possible overflow @?@ can vsnprintf cut more than needed off? */
	if (sz + 32 >= free_space)	/* magic constant 32, ARGH! @?@ */
	    memBufGrow(mb, mb->capacity + 1);
	else
	    break;
    }
    mb->size += sz - 1;		/* note that we cut 0-terminator as store does @?@ @?@ */
}

/*
