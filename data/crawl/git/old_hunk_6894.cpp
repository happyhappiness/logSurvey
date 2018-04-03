	ce->ce_size  = ntohl(ondisk->size);
	/* On-disk flags are just 16 bits */
	ce->ce_flags = ntohs(ondisk->flags);
	hashcpy(ce->sha1, ondisk->sha1);

	len = ce->ce_flags & CE_NAMEMASK;