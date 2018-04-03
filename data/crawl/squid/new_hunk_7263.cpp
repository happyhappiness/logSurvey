static int
storeGetUnusedFileno(void)
{
    int fn;
    if (fileno_stack_count < 1)
	return -1;
    fn = fileno_stack[--fileno_stack_count];
    storeDirMapBitSet(fn);
    return fn;
}

static void
storePutUnusedFileno(int fileno)
{
    if (!storeDirMapBitTest(fileno))
	fatal_dump("storePutUnusedFileno: fileno not in use");
    storeDirMapBitReset(fileno);
    if (fileno_stack_count < FILENO_STACK_SIZE)
	fileno_stack[fileno_stack_count++] = fileno;
    else
