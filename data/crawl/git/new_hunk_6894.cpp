	ce->ce_size  = ntohl(ondisk->size);
	/* On-disk flags are just 16 bits */
	ce->ce_flags = ntohs(ondisk->flags);

	/* For future extension: we do not understand this entry yet */
	if (ce->ce_flags & CE_EXTENDED)
		die("Unknown index entry format");
	hashcpy(ce->sha1, ondisk->sha1);

	len = ce->ce_flags & CE_NAMEMASK;