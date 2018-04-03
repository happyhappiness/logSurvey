static int die_is_recursing_builtin(void)
{
	static int dying;
	return dying++;
}

/* If we are in a dlopen()ed .so write to a global variable would segfault