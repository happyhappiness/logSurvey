    memFree(MEM_4K_BUF, ybuf);
    return len;
}

static void
clientCacheHit(void *data, char *buf, ssize_t size)
