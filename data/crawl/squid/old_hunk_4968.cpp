wordlistCat(const wordlist * w, MemBuf * mb)
{
    while (NULL != w) {
        memBufPrintf(mb, "%s\n", w->key);
        w = w->next;
    }
}
