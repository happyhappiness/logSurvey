{
    storeAppendPrintf(entry, "%s %s %s %d\n",
	name,
	s->type,
	s->path,
	s->max_size >> 20);
}
