	*q = outq;
}

void diffcore_pickaxe(struct diff_options *o)
{
	const char *needle = o->pickaxe;
