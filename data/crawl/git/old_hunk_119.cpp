	if (!buf)
		return error("cannot read sha1_file for %s", oid_to_hex(oid));
	hdrlen = xsnprintf(hdr, sizeof(hdr), "%s %lu", typename(type), len) + 1;
	ret = write_loose_object(oid->hash, hdr, hdrlen, buf, len, mtime);
	free(buf);

	return ret;