static void
storePutUnusedFileno(int fileno)
{
    assert(storeDirMapBitTest(fileno));
    storeDirMapBitReset(fileno);
    if (fileno_stack_count < FILENO_STACK_SIZE)
	fileno_stack[fileno_stack_count++] = fileno;