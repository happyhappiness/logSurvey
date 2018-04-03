static int
storeGetUnusedFileno(void)
{
    if (fileno_stack_count < 1)
	return -1;
    return fileno_stack[--fileno_stack_count];
}

static void
storePutUnusedFileno(int fileno)
{
    if (fileno_stack_count < FILENO_STACK_SIZE)
	fileno_stack[fileno_stack_count++] = fileno;
    else
