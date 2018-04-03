			      enum object_type *type, unsigned long *size)
{
	struct pack_entry e;

	if (!find_pack_entry(sha1, &e, NULL))
		return NULL;
	else
		return cache_or_unpack_entry(e.p, e.offset, size, type, 1);
}

/*