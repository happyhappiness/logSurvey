	/* On-disk flags are just 16 bits */
	ce->ce_flags = ntohs(ondisk->flags);

	/* For future extension: we do not understand this entry yet */
	if (ce->ce_flags & CE_EXTENDED)
		die("Unknown index entry format");
	hashcpy(ce->sha1, ondisk->sha1);

	len = ce->ce_flags & CE_NAMEMASK;
	if (len == CE_NAMEMASK)
		len = strlen(ondisk->name);
	/*
	 * NEEDSWORK: If the original index is crafted, this copy could
	 * go unchecked.
	 */
	memcpy(ce->name, ondisk->name, len + 1);
}

static inline size_t estimate_cache_size(size_t ondisk_size, unsigned int entries)
