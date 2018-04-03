	return !strcasecmp(src, dst);
}

/*
 * Given a buffer and its encoding, return it re-encoded
 * with iconv.  If the conversion fails, returns NULL.
