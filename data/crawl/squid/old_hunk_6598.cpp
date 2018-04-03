	    xpercent(f->stat.errCount, f->stat.parsCount),
	    xpercent(f->stat.repCount, f->stat.parsCount));
    }
    storeAppendPrintf(e, "%s\n", "<hr size=1 noshade>");
    /* short strings */
    shortStringStatDump(e);
}


/*
 * "short string" routines below are trying to recycle memory for short strings
 */

static char *
dupShortStr(const char *str)
{
    return dupShortBuf(str, strlen(str));
}

static char *
dupShortBuf(const char *str, size_t len)
{
    char *buf;
    assert(str);
    buf = allocShortBuf(len + 1);
    assert(buf);
    if (len)
	xmemcpy(buf, str, len);	/* may not have terminating 0 */
    buf[len] = '\0';		/* terminate */
    debug(55, 9) ("dupped short buf[%d] (%p): '%s'\n", len + 1, buf, buf);
    return buf;
}

static char *
appShortStr(char *str, const char *app_str)
{
    const size_t size = strlen(str) + strlen(app_str) + 1;
    char *buf = allocShortBuf(size);
    snprintf(buf, size, "%s, %s", str, app_str);
    freeShortString(str);
    return buf;
}

static char *
allocShortBuf(size_t sz)
{
    char *buf = NULL;
    assert(shortStrings);
    if (sz > shortStrSize) {
	buf = xmalloc(sz);
	longStrAliveCount++;
	longStrAliveSize += sz;
	if (longStrHighWaterCount < longStrAliveCount)
	    longStrHighWaterCount = longStrAliveCount;
	if (longStrHighWaterSize < longStrAliveSize)
	    longStrHighWaterSize = longStrAliveSize;
    } else
	buf = memPoolAlloc(shortStrings);
    return buf;
}

static void
freeShortString(char *str)
{
    assert(shortStrings);
    if (str) {
	const size_t sz = strlen(str) + 1;
	debug(55, 9) ("freeing short str of size %d (max: %d) '%s' (%p)\n", sz, shortStrSize, str, str);
	if (sz > shortStrSize) {
	    debug(55, 9) ("LONG short string[%d>%d]: %s\n", sz, shortStrSize, str);
	    assert(longStrAliveCount);
	    xfree(str);
	    longStrAliveCount--;
	    longStrAliveSize -= sz;
	} else
	    memPoolFree(shortStrings, str);
    }
}

